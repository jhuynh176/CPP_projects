#include <iostream>
#include <unordered_map>

//Using unordered hash map
//Register
//Log-in
//Forgot password

class Account {
    private:
    //Log-in Information
        std::string password;
        std::string username;
        std::string hint;

    //Contain personal information
        std::string phone;
        std::string email;

    //Log-in tries
        int tries;
       
    public:
        std::unordered_map<std::string, std::string> user[9];
        //Menu choice
        int menu_choice = -1;

        void home_welcome();
        void home_menu();
        void home_menu_prompt(Account &user);
        void user_registration(Account &user);
        void user_login(Account &user);
        void user_logout(Account &user);
        void user_forgot_password(Account &user); 
};

void Account::home_welcome() {
    //Welcome message
    std::cout << "Welcome to Personal-Folder Homepage!" << std::endl;
}

void Account::home_menu() {
    //Display choice
    std::cout << "\nMenu: "
              << "\n[1]. Log-in"
              << "\n[2]. Resgister"
              << "\n[3]. Forgot Password"
              << std::endl;

    //Prompt user to select an option
    std::cout << "Enter your selected number: ";
    std::cin >> menu_choice;
}            

void Account::home_menu_prompt(Account &user) {
    switch(menu_choice) {
    //If valid option
        case 1:
            std::cout << "Transfering to: Login.";
            user.user_login(user);
            break;
        case 2:
            std::cout << "Transfering to: Registration.";
            user.user_registration(user);
            break;
        case 3:
            std::cout << "Transfering to: Forgotten password.";
            user.user_forgot_password(user);
            break;
    //If invalid option
        default:
            std::cout << "ERROR: You have enter an invalid number. Please try again." << std::endl;
            home_menu();
            break;
    }
}

void Account::user_registration(Account &user) {
    std::cout << "\nYou are registering an account." << std::endl;

    std::cout << "Enter an username: ";
    std::cin  >> user.username;

    std::cout << "Enter a password: ";
    std::cin  >> user.password;

    std::cout << "Enter your phone number: ";
    std::cin  >> user.phone;

    std::cout << "Enter your email address: ";
    std::cin  >> user.email;
}
void Account::user_login(Account &user) {

}
void Account::user_logout(Account &user) {

}
void Account::user_forgot_password(Account &user) {

}

int main() {
    //Object for each username
    Account user;
    user.home_welcome();
    user.home_menu();
    user.home_menu_prompt(user);




}