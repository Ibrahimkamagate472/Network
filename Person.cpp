#include "Person.hpp"

Person::Person(){}

Person::Person(int id, std::string first_name, std::string last_name, std::string school, 
std::string field, std::unordered_map<int, Person*> friends):
id_{id}, first_name_{first_name}, last_name_{last_name}, school_{school}, field_{field}, 
friends_{friends}{}

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


bool Person::friendAdd(Person* friend_search_){
    auto person_ = friends_.find(friend_search_->getId());

    //makes sure we not adding the same people over
    if(person_ == friends_.end()){
       friends_[friend_search_->id_] = friend_search_;
       return 1;
    }
    return 0;
}

bool Person::friendRemove(Person* friend_search_){
    //checks if they have any firends
    if(friends_.empty()){
        return 0;
    }
    //finds the person
    auto person_ = friends_.find(friend_search_->getId());

    if(person_ != friends_.end()){
        friends_.erase(person_);
        return 1;
    }
    return 0;
}

void Person::friendsList(){
    //checks if the have any friends 
    if(friends_.empty()){
        std::cout << "\nThis person has no friends";
        return;
    }

    std::vector<std::string> names_;
    //loops through all the friends and add to a vector 
    for(const auto& person_: friends_){
        names_.push_back(person_.second->getFullName());
    }
    //sort the names and cout 
    std::sort(names_.begin(), names_.end());

    for(const auto& person_ : names_){
        std::cout << std::endl << person_ << std::endl;
    }
}