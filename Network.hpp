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
        /**
         * @brief this function list out all duplicates
         * 
         * @param a pointer to a Person 
         * 
         * @return a pointer to a Person
         */
        Person* listDuplicate(Person* person_);


    public:

    /**
     * @brief this function checks in our network if a person is in it or not
     * 
     * @param const reference to a string of the persons first name 
     * @param const reference to a string of the persons last name 
     * 
     * @return true or false if we were able find the person or not
     */
    Person* lookUp(const std::string& first_name_, const std::string& last_name_);
    /**
     * @brief this function sets the currernt person we are using, if the exist 
     * 
     * @param const reference to a string of the persons first name 
     * @param const reference to a string of the persons last name 
     * 
     */
    bool setCurrentPerson(const std::string& first_name_, const std::string& last_name_);

    /**
     * @brief this functions handles if there are duplicate 
     */
    void addDuplicate(Person* duplicate_person_);
    /**
     * @brief this function checks if the person a is our duplicate list 
     * 
     * @param pointer a person that is being checked for duplicates 
     * 
     * returns true or false if there are duplicates
     */
    bool duplicateChecker(Person* person_);
    bool removeDuplicate();
    

    void duplicateHandler(const std::string& duplicateName);

    /* FRIENDS SECTION */

    /**
     * @brief this functions adds a friend to the current preson that we are using 
     * 
     * @param const reference to a string of the friend we are adding first name
     * @param const reference to a string of the friend we are adding last name
     * 
     * @return true or false if we were able to add the friend
     */
    bool addFriend(const std::string& friend_first_name, const std::string& friend_last_name_);


    /**
     * @brief this function list out all the friends for a current person
     */
    void listFriends();

    /**
     * @brief this function deletes a friend from a persons list 
     * 
     * @param const reference to a string of the person first name we want to remove
     * @param const reference to a string of the person last name we want to remove
     */
    bool removeFriend(const std::string& remove_first, const std::string& remove_last);

    /**
     * 
     */
    bool recomendFriend();




    
    /**
     * @brief functions adds a new people to out network
     * 
     */
    bool addPerson(std::string first_name_, std::string last_name_, std::string school_, std::string field_);
    bool removePerson();
    bool changePersonName(const std::string& new_first_name, const std::string& new_last_name);


};
#endif