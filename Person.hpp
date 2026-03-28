#include <iostream>
#include <string>
#include <unordered_map>

#ifndef PERSON_H
#define PERSON_H
class Person{
    private:
        int id_;
        std::string first_name_;
        std::string last_name_;
        std::string school_;
        std::string field_;
        std::unordered_map<int, Person*> friends_;
    public:
        Person();

        Person(int id, std::string first_name, std::string last_name, std::string school, 
            std::string field, std::unordered_map<int, Person*> friends);
        
        /** GETTERS **/
        /**
         * @brief function gets the id of a person
         * 
         * @return an int of the id
         */
        int getId();
        /**
         * @brief function gets the first name of a person
         * 
         * @return returns a string to the person's first name 
         */
        std::string getFirstName();

        /**
         * @brief function gets the last name of a person
         * 
         * @return returns a string to the person's last name 
         */
        std::string getLastName();
        
        /**
         * @brief function returns a persons full name
         * 
         * @return the full name of the person
         */
        std::string getFullName();

        /**
         * @brief functions return all the person data
         * 
         * @return a string of all data
         */
        std::string getFullData();

        /**
         * @brief function gets the school the person attend
         * 
         * @return a sting of the school
         */
        std::string getSchool();

        /**
         * @brief function get the field the person is in
         * 
         * @return a string of the field
         */
        std::string getField();

        /** SETTERS **/

        /**
         * @brief function gets the first name of a person
         * 
         * @param const reference to a string of the first name
         */
        void setFirstName(const std::string& first_);

        /**
         * @brief function gets the last name of a person
         * 
         * @param const reference to a string of the last name 
         */
        void setLastName(const std::string& last_);

        /**
         * @brief function gets the last name of a person
         * 
         * @param const reference to a string of the school 
         */
        void setSchool(const std::string& college_);


        /**
         * @brief function gets the last name of a person
         * 
         * @param const reference to a string of the field 
         */
        void setField(const std::string& job_);
        
        
        /** MUTATORS **/

        /**
         * @brief function changes the first name of a person
         * 
         * @param const referent to a string of the new first name
         * 
         * @return true or false if done
         */
        bool changeFirstName(const std::string& first_);

        /**
         * @brief function changes the first name of a person
         * 
         * @param const referent to a string of the new last name
         * 
         * @return true or false if done
         */
        bool changeLastName(const std::string& last_);

        /** FRIENDS SECTION **/

        /** 
         * @brief function adds a friend for a person
         * 
         * @param pointer to a Person that is going to be added to the friends list 
         * 
         * @return true or false if task was completed
         * 
         */
        bool friendAdd(Person* friend_);

        /** 
         * @brief function removes friend from the persons friends list
         * 
         * @param pointeer to a Person that is going to be removed from the friends list
         * 
         * @return ture or false if the task was completed
        */
        bool friendRemove(Person* friend_);

        /**
         * @brief function cout the entire friends list for a person
         */
        void friendsList();

};
#endif