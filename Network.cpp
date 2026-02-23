#include "Network.hpp"

/** BASIC FUNCTIONS **/

/**
 * @brief this functions looks through our network for a perso
 * 
 * @param const reference to a string of the first name 
 * @param const reference to a string of the last name 
 * 
 * @return a pointer to the person
 */
Person* Network::lookUp(const std::string& first_name_, const std::string& last_name_){
    auto look_up_ = network_.find(first_name_ + " " + last_name_);
    //makes a temp person
    Person* temp_person_ = new Person (first_name_,last_name_,"","",{});

    //if person not in network then we set to nullptr
    if(look_up_  != network_.end()){
        //checks if there are duplicate people by that name
        if(duplicateChecker(temp_person_)){
            std::cout << "There is more than one person with that name\n";
            //listDuplicates return the duplicated person that we want
            delete temp_person_;
            return listDuplicate(temp_person_);
        }
        return nullptr;
    }
    delete temp_person_;
    //if they are we return the actual person
    return look_up_->second;
 }

 /**
 * @brief this function list out all duplicates
 * 
 * @param a pointer to a Person 
 * 
 * @return a pointer to a Person
 */
Person* Network::listDuplicate(Person* person_){
    //find the original person
    auto initial_person_ = network_.find(person_->getFullName()); 

    //double checks if we found the person
    if(initial_person_ != network_.end()){
        //get the amount of duplicates of that name 
        int amount_ = duplicate_table_[person_->getFullName()];
        
        std::cout << "1. \n" << initial_person_->second->getFullData();
        //while we didn't reach the amount of duplicates there are, cout all of them 
        int i = 2;
        while(i <= amount_){
            //find the dup person and cout all data
            auto in = network_.find(std::to_string(i)+person_->getFullName());
            std::cout << "\n" << i << ". " << in->second->getFullData();
            i++;
        }

        //make the person choose what duplicate person they want 
        int select_;
        std::cout << "\nPlease chose a number 1-" << amount_ << " to select the person.";
        std::cin >> select_;

        while(select_ > amount_ || select_ < 0){
            std::cout << "Incorrect value or out of bound.";
            std::cout << "\nPlease chose a number 1-" << amount_ << " to select the person.";
            std::cin >> select_;
            }
        //returns the person they want
        auto return_person_ = network_.find(std::to_string(select_) + person_->getFullName());
        return return_person_->second;
    }

return nullptr;
}

/**
 * @brief this function sets the currerent person
 * 
 * @param const reference to a string of the first name 
 * @param const reference to a string of the last nmae
 * 
 * @return true or flase if done
 */
 bool Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    person_ = lookUp(first_name_, last_name_);

    //checks if there person even exist in our network
    if(person_ == nullptr){
        std::cout << "This person does not exist in our network." << std::endl;
        return 0;
    }
    //if they do they we set it to the current person that we want to minipluate
    current_person_ = person_;
    return 1;
}


/** PERSON **/

/**
 * @brief this function adds a person to the network
 * 
 * @param const reference to a string of the first name
 * @param const reference to a string of the last name
 * @param const reference to a string of the school
 * @param const reference to a string of the field
 * 
 * @return true or false 
 */
bool Network::addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_){
    Person* new_person = new Person (first_name_,last_name_,school_,field_, {});

    //calls duplicateChecker to see if there are duplicates 
    if(duplicateChecker(new_person)){
        addDuplicate(new_person);
        delete new_person;
        return 0;
    }
    network_.insert({new_person->getFullName(), new_person});
    delete new_person;
    return 1;
}

bool Network::removeDuplicate(){


}

/**
 * @brief this function removes a person from the network 
 * 
 * @return true or false 
 */
bool Network::removePerson(){
    if(duplicateChecker(current_person_)){
        removeDuplicate();

    }
    network_.erase(current_person_->getFullName());
    return 1;
}

bool Network::changePersonName(const std::string& new_first_name, const std::string& new_last_name){
    current_person_->changeFirstName(new_first_name);
    current_person_->changeLastName(new_last_name);
    return 1;
}

/** FRIENDS SECTION **/

/**
 * @brief this function add a friend to the current person that we are on
 * 
 * @param const reference to a string of the friends first name 
 * @param const reference to a string of the friends last name
 * 
 * @return true or false if done 
 */
bool Network::addFriend(const std::string& friend_first_name, const std::string& friend_last_name_){
    friend_ = lookUp(friend_first_name, friend_last_name_);

    //makes sure the person exist that we will be adding
    if(friend_ != nullptr && current_person_->friendAdd(friend_)){
        return 1;
    }
    return 0;
}

/**
 * @brief this function removes a friend from the current person that we are on 
 * 
 * @param const reference to a string of the friends first name that we want to remove
 * @param const reference to a string of the friends last name that we want to remove
 * 
 * @return true or false if done
 */
bool Network::removeFriend(const std::string& remove_first, const std::string& remove_last){
    friend_ = lookUp(remove_first, remove_last);

    if(friend_ != nullptr && current_person_->friendRemove(friend_)){
        return 1;    
    }
    return 0;
}
/**
 * @brief this function list all the friends of the current person
 */
void Network::listFriends(){
    current_person_->friendsList();
    
}

/** DUPLICATE HANDLER SECTION **/
/**
 * @brief this function adds a duplicate person to the network
 * 
 * 
 */
 //need to add it to network the new changed dup name 
void Network::addDuplicate(Person* duplicate_person_){
    //find the person in the dup table
    auto person_ = duplicate_table_.find(duplicate_person_->getFullName());

    //this is the first duplicate for that name
    if(person_ == duplicate_table_.end()){
        //add them to the duplicate table and add the to the network with a slightly changed name
        duplicate_table_[duplicate_person_->getFullName()] = 2;
        network_.insert({"2" + duplicate_person_->getFullName(), duplicate_person_});
        return;
    }
    //if there is more than one person for that name then we increase the total by 1
   int value_ = duplicate_table_[duplicate_person_->getFullName()] ++;
   //convert the int to string and set the naming style the same for if its the first duplicate or 30th
   network_.insert({std::to_string(value_) + duplicate_person_->getFullName(), duplicate_person_});
}

/**
 * @brief this function checks if the person a is our duplicate list 
 * 
 * @param pointer a person that is being checked for duplicates 
 * 
 * returns true or false if there are duplicates
 */
bool Network::duplicateChecker(Person* person_){
    //find the name in the table
    auto checker_ = duplicate_table_.find(person_->getFullName());

    //if in the table
    if(checker_ != duplicate_table_.end()){
        return 1;
    }
    return 0;
}