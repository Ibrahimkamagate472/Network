#include "Network.hpp"

std::string first_name_, last_name_, person_field_, person_school_;
std::string change_first_, change_last_, friend_first_, friend_last_;



void setPerson(std::string indicator, Network world_){
    if(indicator == "set"){
        std::cout << "Please enter in the person first name: ";
        std::cin >> first_name_;
        std::cout << "Please enter in the person last name: ";
        std::cin >> last_name_;
        world_.setCurrentPerson(first_name_, last_name_);
    }else if (indicator == "remove"){
        std::cout << "Please enter in the person first name you want to remove: ";
        std::cin >> first_name_;
        std::cout << "Please enter in the person last name you want to remove: ";
        std::cin >> last_name_;
        world_.setCurrentPerson(first_name_, last_name_);
    }else if(indicator == "change"){
        std::cout << "Please enter the first name of the person want to change: ";
        std::cin >> first_name_;
        std::cout << "Please enter the last name of the person want to change: ";
        std::cin >> last_name_;
    }else if("add friend"){
        std::cout << "Please enter in the person first name: ";
        std::cin >> first_name_;
        std::cout << "Please enter in the person last name: ";
        std::cin >> last_name_;
        std::cout << "Please enter the friend's first name to add: ";
        std::cin >> first_name_;
        std::cout << "Please enter the friend's last name to add: ";
        std::cin >> last_name_;
    }else if(indicator == "remove friend"){
        std::cout << "Please enter in the person first name: ";
        std::cin >> first_name_;
        std::cout << "Please enter in the person last name: ";
        std::cin >> last_name_;
        std::cout << "Please enter the friend's first name to remove: ";
        std::cin >> first_name_;
        std::cout << "Please enter the friend's last name to remove: ";
        std::cin >> last_name_;
    }
}
void addPerson(Network world_){
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
void removePerson(Network world_){
    if(world_.removePerson()){
        std::cout << "You have successfully removed " << first_name_ << " " <<
        last_name_;
    }
}
void changeName(Network world_){
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
void listFriends(Network world_){
    std::cout << first_name_ << " " << last_name_ << " friends are: ";
    world_.listFriends();
}
void addFriend(Network world_){
    if(world_.addFriend(first_name_,friend_last_)){
        std::cout << "You have successfully added " << friend_first_ << " " << last_name_ <<
        " as a friend!";
        return;
    }
    std::cout << "There was an error adding " << friend_first_ << " " << friend_last_ << ".";
}
void removeFriend(Network world_){
    if(world_.removeFriend(friend_first_, friend_last_)){
        std::cout << " You have successfully removed " << friend_first_ << " " << friend_last_ << ".";
        return;
    }
    std::cout << "There was an error unfriend " << first_name_ << " " << friend_last_ << ".";
}
void friendRecommendation(Network world_){

}



int main(){
    Network world_;

    int option_;
    std::cout << "Welcome to Network!\n Our goal is to connect the world!\n";
    std::cout << "Please enter the number that correspond with the option you want.\n" 
    << "1. Set Currenet Person \n2. Add Person\n3. Remove Person\n4. Change Name\n5. List Friends\n6. Add Friend\n7. Remove Friend" 
    << "\n8. Friend Recommendation\n9. Close Program\n";
    std::cin >> option_;

    while(option_ != 8){
        switch (option_)
        {
            case 1:
            /** SET PERSON **/
                setPerson("set", world_);
                break;

            case 2:
                /** ADD PERSON **/
                addPerson(world_);
                break;
            case 3:
                /** REMOVE PERSON **/
                setPerson("remove", world_);
                removePerson(world_);
                break;
            case 4:
                /** CHANGE PERSON NAME **/
                setPerson("change", world_);
                changeName(world_);
                break;

            case 5:
                setPerson("set", world_);
                listFriends(world_);
                break;
            case 6:
                /** ADD FRIEND **/
                setPerson("add friend", world_);
                addFriend(world_);

            case 7:
                /** REMOVE FRIEND**/
                setPerson("remove friend", world_);
            case 8:
                /**FRIEND RECOMMENDATION**/
            default:
                std::cout << "That was an invalid input";
                break;
        }
        std::cout << "\n\nPlease enter the number that correspond with the option you want.\n" 
        << "1. Set Currenet Person 1. Add Person\n2. Remove Person\n3. Change Name\n4. List Friends\n5. Add Friend\n6. Remove Friend" 
        << "\n7. Friend Recommendation\n8. Close Program\n";
        std::cin >> option_;
    }
}