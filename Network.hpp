#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "Person.hpp"


#ifndef NETWORK_H
#define NETWORK_H

class Network{

    private:
        std::unordered_map<int, Person*> network_;
        std::unordered_map<std::string, std::vector<int>> second_table_;
        std::unordered_map<std::string, std::vector<int>> same_school_field_;
        int new_id_ = 0;
        int vec_location_ = 0;
        Person* current_person_;
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
     * @param reference to a string of the first name 
     * @param reference to a string of the last nmae
     * 
     * @return true or flase if done
     */
    bool setCurrentPerson(const std::string& first_name_, const std::string& last_name_);

    /**
     * @brief function list everybody that is in the network
     * 
     */
    void listEverybody();

    /** 
     * @brief function list the current size of network
    */
    void size();

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

    void idMaker();


    /* FRIENDS SECTION */

    /**
     * @brief functions adds a friend to the current preson that we are using 
     * 
     * @param const reference to a string of the friend we are adding first name
     * @param const reference to a string of the friend we are adding last name
     * 
     * @return true or false if we were able to add the friend
     */
    bool addFriend(const std::string& friend_first_name, const std::string& friend_last_name_, 
        int friend_id_);


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
     * @brief function recomends a new friend for the current person
     */
    void recommendFriend();

    /** DUPLICATE HANDLER SECTION **/
    
    /**
     * @brief function list out all duplicates
     * 
     * @param pointer to a Person 
     * 
     * @return pointer to a Person
     */
    Person* listDuplicate(std::vector<int>& duplicate_people_);

};
#endif