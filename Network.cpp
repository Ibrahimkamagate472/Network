#include "Network.hpp"

/** BASIC FUNCTIONS **/

/**
 * @brief functions looks through our network for a person
 * 
 * @param const reference to a string of the first name 
 * @param const reference to a string of the last name 
 * 
 * @return a pointer to the person
 */
Person* Network::lookUp(const std::string& first_name_, const std::string& last_name_){
    auto& look_up_ = second_table_[first_name_ + " " + last_name_];

    //There is one or more person
    if(look_up_.size() > 1) {
        std::cout << "There is more than one person with that name.";
        return listDuplicate(look_up_);
    }else if(look_up_.size() == 1){
        return network_[look_up_[0]];
    }
    //if the person is not in the network
    return nullptr;
 }

/**
 * @brief function sets the currerent person
 * 
 * @param const reference to a string of the first name 
 * @param const reference to a string of the last nmae
 * 
 * @return true or flase if done
 */
 bool Network::setCurrentPerson(const std::string& first_name_,const std::string& last_name_){
    Person* temp_person_ = lookUp(first_name_, last_name_);

    //checks if there person even exist in our network
    if(temp_person_ == nullptr){
        std::cout << "\nThis person does not exist in our network." << std::endl;
        return 0;
    }
    //if they do they we set it to the current person that we want to minipluate
    current_person_ = temp_person_;
    return 1;
}

/**
 * @brief function list everybody that is in the network
 * 
 */
void Network::listEverybody(){
    std::string list_;
    if(network_.size() > 50){
        std::cout << "\nThere is over 50 people in the network." <<
        "\nAre you sure you want to see everyboydy";    
        std::cin >> list_;
        if(list_ == "yes" || list_ == "Yes"){
            int i = 1;
            for(const auto& list_person_ : network_){
                std::cout << i << ". " << list_person_.second->getFullData() << std::endl;
                i++;
            }
        }
    }else{
        int i = 1;
        for(const auto& list_person_ : network_){
            std::cout << i << ". " << list_person_.second->getFullName() << std::endl;
            i++;
        }

    }
}

/** 
 * @brief function list the current size of network
*/
void Network::size(){
    std::cout << "\nCurrent size of our Network is: " << network_.size(); 
}

/** PERSON **/

/**
 * @brief function adds a person to the network
 * 
 * @param const reference to a string of the first name
 * @param const reference to a string of the last name
 * @param const reference to a string of the school
 * @param const reference to a string of the field
 * 
 * @return true or false 
 */
bool Network::addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_){
    idMaker();
    Person* new_person_ = new Person (new_id_, first_name_,last_name_, school_, field_, {});
    
    // store person in main network table
    network_[new_person_->getId()] = new_person_;
    second_table_[new_person_->getFullName()].push_back(new_person_->getId());

    //for friend rec.
    same_schol_field_[field_].push_back(new_id_);
    same_schol_field_[school_].push_back(new_id_);
    return 1;
}

/**
 * @brief function removes a person from the network 
 * 
 * @return true or false 
 */
bool Network::removePerson(){
    std::string temp_name_ = current_person_->getFullName();

    //delete them from the network
    if(network_.erase(current_person_->getId())){
       auto& location_ =  second_table_[temp_name_];

       //checks the size of people with the same name to determine how to delete
       if(location_.size() > 1){
            location_.erase(location_.begin()+ vec_location_);
       }else if(location_.size() == 1 || location_.empty()){
            second_table_.erase(temp_name_);
       }
       return 1;
    }
    return 0;
}

/** 
 * @brief function changes a person names 
 * 
 * @param const reference to a string of the new first name
 * @param const reference to a string of the new last name 
 * 
 * @return true or false
*/
bool Network::changePersonName(const std::string& new_first_name, const std::string& new_last_name){
    Person* temp_ = current_person_;
    removePerson();
    if(temp_->changeFirstName(new_first_name) &&
    temp_->changeLastName(new_last_name)){
        network_[temp_->getId()] = temp_;
        second_table_[temp_->getFullName()].push_back(temp_->getId());
        return 1;
    }
    return 0;
}


void Network::idMaker(){
    new_id_ ++;
}

/** FRIENDS SECTION **/

/**
 * @brief function add a friend to the current person that we are on
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
 * @brief function removes a friend from the current person that we are on 
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
 * @brief function list all the friends of the current person
 */
void Network::listFriends(){
    current_person_->friendsList();
    
}

/**
 * @brief function recomends a new friend for the current person
 */
void Network::recomendFriend(){
    //gets the vector of people that have similar attributes with the current person
    const auto& same_school_ = same_schol_field_.find(current_person_->getSchool());
    const auto& same_field_ = same_schol_field_.find(current_person_->getField());
    
    int amount_ = std::min(10, (int)same_school_->second.size());

    for (int i = 0; i < amount_; i++){
        int idx = same_school_->second[i];
        if(network_[idx]->getId() != current_person_->getId()){
            std::cout << "\nSame school:";
            std::cout << std::endl << i+1 << ". " << network_[idx]->getFullName();
        }
    }
    
}

/** DUPLICATE HANDLER SECTION **/

/**
 * @brief function list out all duplicates
 * 
 * @param pointer to a Person 
 * 
 * @return pointer to a Person
 */
Person* Network::listDuplicate(std::vector<int>& duplicate_people_){ 
    int select_ = 0;
    //gets the size of the amout of people with the same name
    int amount_ = duplicate_people_.size();
    int i = 1;
    
    //list all the duplicates with that name
    for(const auto& ids_ : duplicate_people_){
        //if statment stops a person from adding themselves
        if(ids_ != current_person_->getId()){
            std::cout << std::endl << std::endl << i << "." << network_[ids_]->getFullData() << std::endl;
            i++;
        }else{
            amount_--;
        }
    }

    //make the person choose what duplicate person they want 
    std::cout << "\nPlease chose a number 1 - " << amount_ << " to select the person: ";
    std::cin >> select_;


    while(select_ > amount_ || select_ < 0){
        std::cout << "Incorrect value, out of bound.";
        std::cout << "\nPlease chose a number 1 - " << amount_ << " to select the person: ";
        std::cin >> select_;
    }
    
    int idx = select_;
    idx --;
    vec_location_ = idx;
    select_ = duplicate_people_[idx];
    return network_[select_];
}
