#include "Person.hpp"


Person::Person(){}

Person::Person(int id, std::string first_name, std::string last_name, std::string school, 
std::string field, std::unordered_map<int, Person*> friends, std::unordered_map<int, Person*> pending_friend_requests):
id_{id}, first_name_{first_name}, last_name_{last_name}, school_{school}, field_{field}, 
friends_list_{friends}, pending_friend_requests_{pending_friend_requests}{}

/** GETTERS **/

/**
 * @brief function gets the id of a person
 * 
 * @return an int of the id
 */
int Person::getId(){
    return id_;
}
/**
 * @brief function gets the first name of a person
 * 
 * @return returns a string to the person's first name 
 */
std::string Person::getFirstName(){
    return first_name_;
}

/**
 * @brief function gets the last name of a person
 * 
 * @return returns a string to the person's last name 
 */
std::string Person::getLastName(){
    return last_name_;
}

/**
 * @brief function returns a persons full name
 * 
 * @return the full name of the person
 */
std::string Person::getFullName(){
    return first_name_ + " " + last_name_;
}

/**
 * @brief functions return all the person data
 * 
 * @return a string of all data
 */
std::string Person::getFullData(){
    return "Name: " + first_name_ + " " + last_name_ + "\nSchool: " + school_
    + "\nField: " + field_;
}

/**
 * @brief function gets the school the person attend
 * 
 * @return a sting of the school
 */
std::string Person::getSchool(){
    return school_;
}

/**
 * @brief function get the field the person is in
 * 
 * @return a string of the field
 */
std::string Person::getField(){
    return field_;
}

/** SETTERS **/

/**
 * @brief function gets the first name of a person
 * 
 * @param const reference to a string of the first name
 */
void Person::setFirstName(const std::string& first_){
    first_name_ = first_;
}

/**
 * @brief function gets the last name of a person
 * 
 * @param const reference to a string of the last name 
 */
void Person::setLastName(const std::string& last_){
    last_name_ = last_;
}

/**
 * @brief function gets the last name of a person
 * 
 * @param const reference to a string of the school
 */
void Person::setSchool(const std::string& college_){
    school_ = college_;
}


/**
 * @brief function gets the last name of a person
 * 
 * @param const reference to a string of the field
 */
void Person::setField(const std::string& job_){
    field_ = job_;
}


/** MUTATORS **/

/**
 * @brief function changes the first name of a person
 * 
 * @param const reference to a string of the new first name 
 * 
 * @return true or false if done
 */
bool Person::changeFirstName(const std::string& first_){
    first_name_ = first_;
    return 1;
}

/**
 * @brief function changes the first name of a person
 * 
 * @param const referent to a string of the new last name
 * 
 * @return true or false if done
 */
bool Person::changeLastName(const std::string& last_){
    last_name_ = last_;
    return 1;
}


/** FRIEND SECTION **/

/** 
 * @brief function adds a friend for a person
 * 
 * @param pointer to a Person that is going to be added to the friends list 
 * 
 * @return true or false if task was completed
 * 
 */
int Person::friendAdd(Person* friend_){
    //means that they are already friends
    if(friends_list_.find(friend_->id_) != friends_list_.end()){
        return 1;
    }
    //means that a friend request has already been sent perviously 
    else if(friend_->pending_friend_requests_.find(this->id_) != friend_->pending_friend_requests_.end()){
        return 2;
    }
    //happens if they are not friends 
    //add it to pending friend request for the person to accept or decline
    else if(friends_list_.find(friend_->id_) == friends_list_.end()){
        friend_->pending_friend_requests_[id_] = this;
        return 3;
    }

    return 0;
}

/** 
 * @brief function removes friend from the persons friends list
 * 
 * @param pointer to a Person that is going to be removed from the friends list
 * 
 * @return ture or false if the task was completed
*/
bool Person::friendRemove(Person* friend_search_){
    //checks if they have any firends
    if(friends_list_.empty()){
        return 0;
    }
    //finds the person
    auto person_ = friends_list_.find(friend_search_->getId());

    if(person_ != friends_list_.end()){
        friends_list_.erase(person_);
        return 1;
    }
    return 0;
}

/**
 * @brief function allows the user to accept and decline friend request
 * 
 * @return true or false based on if we were able to complete the operation
 * from the users input
 */
int Person::pendingFriendRequest(){
    if(pending_friend_requests_.empty()){
        std::cout << "\n" << first_name_ << " " << last_name_ << ", doesn't have any pending friend request.";  
        return 1;
    }
    //list all the pending friend request that said person has
    listPendingFriendRequest();

    std::string answer_;
    std::cout << "\nWould you like to add or decline anybodys friend request?\nYes or No:";
    std::cin >> answer_;

    answer_ = lower(answer_);

    if(answer_ == "yes"){
        std::cout << "\nWould you like to add or decline anybodys friend request?\nAdd or Decline:";
        std::cin >> answer_;
        answer_ = lower(answer_);
        if(answer_ == "add"){

        }else if(answer_ == "decline"){

        }
    }else {
        return 2;
    }
    return 0;

}
void Person::listPendingFriendRequest(){
    //goes through everybody in their pending frriends list and list all of them 
    int each_pending_ = 1;
    for(const auto& pending_ : pending_friend_requests_){
        std::cout << "\n" << each_pending_ << " " << pending_.second->getFirstName();
    }
}
/**
 * @brief function cout the entire friends list for a person
 */
void Person::friendsList(){
    //checks if the have any friends 
    if(friends_list_.empty()){
        std::cout << "\nThis person has no friends";
        return;
    }

    std::vector<std::string> names_;
    //loops through all the friends and add to a vector 
    for(const auto& person_: friends_list_){
        names_.push_back(person_.second->getFullName());
    }
    //sort the names and cout 
    std::sort(names_.begin(), names_.end());

    for(const auto& person_ : names_){
        std::cout << std::endl << person_ << std::endl;
    }
}