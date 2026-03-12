#include "Network.hpp"

std::string first_name_, last_name_, person_field_, person_school_;
std::string change_first_, change_last_, friend_first_, friend_last_;



void setPerson(int indicator_, Network& world_){
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
    default:
        break;
    }

    std::cout << "Please enter the first name of the person" << fragment_;
    std::cin >> first_name_;
    std::cout << "Please enter the last name of the person" << fragment_;
    std::cin >> last_name_;

    world_.setCurrentPerson(first_name_,last_name_);

}
void addPerson(Network& world_){
    std::cout << "Please enter in the person first name: ";
    std::cin >> first_name_;
    std::cout << "Please enter in the person last name: ";
    std::cin >> last_name_;
    std::cout << "Please enter in the school the person attended: ";
    std::cin >> person_school_;
    std::cout << "Please enter in the person's field: ";
    std::cin >> person_field_;

    if(world_.addPerson(first_name_,last_name_,person_school_, person_field_)){
        std::cout << "You have successfully added " << first_name_ << " " << 
        last_name_ << ".";
        return;
    }
    std::cout << "There was an error adding " << first_name_ << " " << last_name_ << " to the world.";
}
void removePerson(Network& world_){
    if(world_.removePerson()){
        std::cout << "You have successfully removed " << first_name_ << " " <<
        last_name_;
    }
}
void changeName(Network& world_){
    std::cout << "Please enter the new first name of the person want to change: ";
    std::cin >> change_first_;
    std::cout << "Please enter the new last name of the person want to change: ";
    std::cin >> change_first_;
    if(world_.changePersonName(change_first_,change_first_)){
        std::cout << "You have successfully changed " << first_name_ << " " <<
        last_name_ << " to " << change_first_ << " " << change_last_;
    }else{
        std::cout << "There was an error changing " << first_name_ << " " << last_name_ << ".";
    }
}
void listFriends(Network& world_){
    std::cout << first_name_ << " " << last_name_ << " friends are: ";
    world_.listFriends();
}
void addFriend(Network& world_){
    if(world_.addFriend(friend_first_,friend_last_)){
        std::cout << "You have successfully added " << friend_first_ << " " << friend_last_ <<
        " as a friend!";
        return;
    }
    std::cout << "There was an error adding " << friend_first_ << " " << friend_last_ << ".";
}
void removeFriend(Network& world_){
    if(world_.removeFriend(friend_first_, friend_last_)){
        std::cout << " You have successfully removed " << friend_first_ << " " << friend_last_ << ".";
        return;
    }
    std::cout << "There was an error unfriend " << first_name_ << " " << friend_last_ << ".";
}
void friendRecommendation(Network& world_){

}
void listPeople(Network& world_){
    world_.listEverybody();
}


int main(){
    Network world_;

    int option_;
    std::cout << "Welcome to Network!\n Our goal is to connect the world!\n";
    std::cout << "Please enter the number that correspond with the option you want.\n" 
    << "1. Add Person\n2. Remove Person\n3. Change Name\n5. List Friends\n6. Add Friend\n7. Remove Friend" 
    << "\n8. Friend Recommendation\nList Everybody\n10. Close Program\n";
    std::cin >> option_;

    while(option_ != 11){
        switch (option_)
        {
            case 1:
                /** ADD PERSON **/
                addPerson(world_);
                break;
            case 2:
                /** REMOVE PERSON **/
                setPerson(1, world_);
                removePerson(world_);
                break;
            case 3:
                /** CHANGE PERSON NAME **/
                setPerson(2, world_);
                changeName(world_);
                break;

            // case 5:
            //     setPerson("set", world_);
            //     listFriends(world_);
            //     break;
            // case 6:
            //     /** ADD FRIEND **/
            //     setPerson("add friend", world_);
            //     addFriend(world_);
            //     break;
            // case 7:
            //     /** REMOVE FRIEND**/
            //     setPerson("remove friend", world_);
            //     break;
            // case 8:
                /** FRIEND RECOMMENDATION **/
                break;
            case 9:
                /** LIST EVERYBODY **/
                listPeople(world_);
                break;
            case 10:
                /** CURRENT SIZE **/
                world_.size();
                break;
            default:
                std::cout << "That was an invalid input";
                break;
        }
        std::cout << "\nPlease enter the number that correspond with the option you want.\n" 
        << "1. Set Currenet Person \n2. Add Person\n3. Remove Person\n4. Change Name\n5. List Friends\n6. Add Friend\n7. Remove Friend" 
        << "\n8. Friend Recommendation\n9. List Everybody\n10. Close Program\n";
        std::cin >> option_;
    }
}