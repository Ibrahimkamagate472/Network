#include "Network.hpp"

std::string first_name_, last_name_, person_field_, person_school_;
std::string change_first_, change_last_, friend_first_, friend_last_;



bool setPerson(int indicator_, Network& world_){
    std::string fragment_ = ":";
    switch (indicator_)
    {
    //remove 
    case 1:
        fragment_ = " to remove: ";
        break;

    //change
    case 2:
        fragment_ = " to change: ";
        break;
    
    //add friend 
    case 3:
        fragment_ = " you want to add a friend with: ";
        break;
    
    //remove friend 
    case 4:
        fragment_ = " you want to remove a friend with: ";
        break;

    //list friends
    case 5:
        fragment_ = " friends list you want to see: ";
        break;

    case 6:
        fragment_ = " you want a friend recommendation for: ";
        break;
    default:
        break;
    }

    std::cout << "Please enter the first name of the person" << fragment_;
    std::cin >> first_name_;
    std::cout << "Please enter the last name of the person" << fragment_;
    std::cin >> last_name_;

    if(world_.setCurrentPerson(first_name_,last_name_)){
        return 1;
    }
    return 0;

}

void addPerson(Network& world_){
    std::cout << "\nPlease enter in the person first name: ";
    std::cin >> first_name_;
    std::cout << "Please enter in the person last name: ";
    std::cin >> last_name_;
    std::cout << "Please enter in the school the person attended: ";
    std::cin >> person_school_;
    std::cout << "Please enter in the person's field: ";
    std::cin >> person_field_;

    if(world_.addPerson(first_name_,last_name_,person_school_, person_field_)){
        std::cout << "\nYou have successfully added " << first_name_ << " " << 
        last_name_ << ".";
        return;
    }
    std::cout << "\nThere was an error adding " << first_name_ << " " << last_name_ << " to the world.";
}

void removePerson(Network& world_){
    if(setPerson(1, world_)){
        if(world_.removePerson()){
            std::cout << "\nYou have successfully removed " << first_name_ << " " <<
            last_name_;
            return;
        }
        std::cout << "\nThere was an error removing " << first_name_ << " " << last_name_ << " from the world.";
    }
}

void changeName(Network& world_){
    if(setPerson(2, world_)){
        std::cout << "\nPlease enter the new first name of the person want to change: ";
        std::cin >> change_first_;
        std::cout << "Please enter the new last name of the person want to change: ";
        std::cin >> change_last_;

        if(world_.changePersonName(change_first_,change_last_)){
            std::cout << "\nYou have successfully changed " << first_name_ << " " <<
            last_name_ << " to " << change_first_ << " " << change_last_;
        }else{
            std::cout << "There was an error changing " << first_name_ << " " << last_name_ << ".";
        }
    }
}

void addFriend(Network& world_){
    if(setPerson(3, world_)){
        std::cout << "\nPlease enter the first name of the person you want to add: ";
        std::cin >> friend_first_;
        std::cout << "Please enter the last name of the person you want to add: ";
        std::cin >> friend_last_;

        if(world_.addFriend(friend_first_,friend_last_)){
            std::cout << "\nYou have successfully added " << friend_first_ << " " << friend_last_ <<
            " as a friend!";
            return;
        }
        std::cout << "\nThere was an error adding " << friend_first_ << " " << friend_last_ << ".";
    }
}

void removeFriend(Network& world_){
    if(setPerson(4, world_)){
        if(world_.removeFriend(friend_first_, friend_last_)){
            std::cout << "\nYou have successfully removed " << friend_first_ << " " << friend_last_ << ".";
            return;
        }
        std::cout << "\nThere was an error unfriending " << first_name_ << " " << friend_last_ << ".";
    }
}

void listFriends(Network& world_){
    if(setPerson(5, world_)){
        std::cout << first_name_ << " " << last_name_ << " friends are: ";
        world_.listFriends();
    }
}

void friendRecommendation(Network& world_){
    if(setPerson(6, world_)){
        world_.recomendFriend();
    }
}

void listPeople(Network& world_){
    world_.listEverybody();
}


int main(){
    Network world_;

    int option_;
    std::cout << "Welcome to Network!\nOur goal is to connect the world!\n";
    std::cout << "Please enter the number that correspond with the option you want.\n" 
    << "1. Add Person\n2. Remove Person\n3. Change Name\n4. Add Friend\n5. Remove Friend\n6. list Friends" 
    << "\n7. Friend Recommendation\n8. List Everybody\n9. Current Size of Network\n10. Close Program\n";
    std::cin >> option_;

    while(option_ != 10){
        switch (option_)
        {
            case 1:
                /** ADD PERSON **/
                addPerson(world_);
                break;

            case 2:
                /** REMOVE PERSON **/
                removePerson(world_);
                break;

            case 3:
                /** CHANGE PERSON NAME **/
                changeName(world_);
                break;

            case 4:
                /** ADD FRIEND **/
                addFriend(world_);
                break;

            case 5:
                /** REMOVE FRIEND**/
                removeFriend(world_);
                break;

            case 6:
                listFriends(world_);
                break;

            case 7:
                /** FRIEND RECOMMENDATION **/
                friendRecommendation(world_);
                break;
            case 8:
                /** LIST EVERYBODY **/
                listPeople(world_);
                break;

            case 9:
                /** CURRENT SIZE **/
                world_.size();
                break;

            default:
                std::cout << "That was an invalid input";
                break;
        }
        std::cout << "\nPlease enter the number that correspond with the option you want.\n" 
        << "1. Add Person\n2. Remove Person\n3. Change Name\n4. Add Friend\n5. Remove Friend\n6. list Friends" 
        << "\n7. Friend Recommendation\n8. List Everybody\n9. Current Size of Network\n10. Close Program\n";
        std::cin >> option_;
    }
}