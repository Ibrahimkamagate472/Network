#include <iostream>
#include <unordered_map>
#include "Person.hpp"


#ifndef NETWORK_H
#define NETWORK_H

class Network{

    private:
        int id_;
        std::unordered_map<std::string ,Person*> network_;
        std::unordered_map<std::string, int> duplicate_table_;
        Person* current_person_;
        Person* person_;
        Person* friend_;
    public:
    /** BASIC FUNCTIONS **/

    /**
     * @brief functions looks through our network for a person
     * 
     * @param const reference to a string of the first name 
     * @param const reference to a string of the last name 
     * 
     * @return a pointer to the person
     */
    Person* lookUp(const std::string& first_name_, const std::string& last_name_);

    /**
     * @brief function sets the currerent person
     * 
     * @param const reference to a string of the first name 
     * @param const reference to a string of the last nmae
     * 
     * @return true or flase if done
     */
    bool setCurrentPerson(const std::string& first_name_, const std::string& last_name_);

    /** PERSON SECTION **/
    
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
    bool addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_);
   
    /**
     * @brief function removes a person from the network 
     * 
     * @return true or false 
     */
    bool removePerson();

    /** 
     * @brief function changes a person names 
     * 
     * @param const reference to a string of the new first name
     * @param const reference to a string of the new last name 
     * 
     * @return true or false
    */
    bool changePersonName(const std::string& new_first_name, const std::string& new_last_name);


    /* FRIENDS SECTION */

    /**
     * @brief functions adds a friend to the current preson that we are using 
     * 
     * @param const reference to a string of the friend we are adding first name
     * @param const reference to a string of the friend we are adding last name
     * 
     * @return true or false if we were able to add the friend
     */
    bool addFriend(const std::string& friend_first_name, const std::string& friend_last_name_);


    /**
     * @brief function list out all the friends for a current person
     */
    void listFriends();

    /**
     * @brief function deletes a friend from a persons list 
     * 
     * @param const reference to a string of the person first name we want to remove
     * @param const reference to a string of the person last name we want to remove
     */
    bool removeFriend(const std::string& remove_first, const std::string& remove_last);

    /**
     * 
     */
    bool recomendFriend();

    /** DUPLICATE HANDLER SECTION **/

    /**
     * @brief function checks if the person a is our duplicate list 
     * 
     * @param pointer to a person that is being checked for duplicates 
     * 
     * @returns true or false if there are duplicates
     */
    bool duplicateChecker(Person* dup_person_);

    /**
     * @brief function adds a duplicate person to the network
     * 
     * @param pointer to a person that is being added as a duplicate
     * 
     * @return true or false 
     *
     */
    bool addDuplicate(Person* duplicate_person_);

    /**
     * @brief function removes a person that is a duplicate
     * 
     * @return true or false 
     */
    bool removeDuplicate();

    /**
     * @brief function list out all duplicates
     * 
     * @param pointer to a Person 
     * 
     * @return pointer to a Person
     */
    Person* listDuplicate(Person* dup_person_);
};
#endif