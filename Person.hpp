#include <iostream>
#include <string>
#include <unordered_map>

#ifndef PERSON_H
#define PERSON_H
class Person{
    private:
        std::string first_name_;
        std::string last_name_;
        std::string school_;
        std::string field_;
        std::unordered_map<std::string, std::string> friends_;
    public:
        Person();

        Person(std::string first_name, std::string last_name, std::string school, 
            std::string field, std::unordered_map<std::string, std::string> friends);
        
        /** GETTERS **/
        /**
         * @brief this function gets the first name of a person
         * 
         * @return returns a string to the person's first name 
         */
        std::string getFirstName();

        /**
         * @brief this function gets the last name of a person
         * 
         * @return returns a string to the person's last name 
         */
        std::string getLastName();
        
        /**
         * @brief this function returns a persons full name
         * 
         * @return the full name of the person
         */
        std::string getFullName();

        /**
         * @brief this functions return all the person data
         * 
         * @return a string of all data
         */
        std::string getFullData();


        /** SETTERS **/

        /**
         * @brief this function gets the first name of a person
         * 
         * @param const reference to a string of the first name
         */
        void setFirstName(const std::string& first_);

        /**
         * @brief this function gets the last name of a person
         * 
         * @param const reference to a string of the last name 
         */
        void setLastName(const std::string& last_);

        /**
         * @brief this function gets the last name of a person
         * 
         * @param const reference to a string of the school 
         */
        void setSchool(const std::string& college_);


        /**
         * @brief this function gets the last name of a person
         * 
         * @param const reference to a string of the field 
         */
        void setField(const std::string& job_);
        
        
        /** MUTATORS **/

        /**
         * @brief this function changes the first name of a person
         * 
         * @param const referent to a string of the new first name
         * 
         * @return true or false if done
         */
        bool changeFirstName(const std::string& first_);

        /**
         * @brief this function changes the first name of a person
         * 
         * @param const referent to a string of the new last name
         * 
         * @return true or false if done
         */
        bool changeLastName(const std::string& last_);



        /** **/
        bool friendAdd(Person* friend_);

        bool friendRemove(Person* friend_);

        void friendsList();

};
#endif