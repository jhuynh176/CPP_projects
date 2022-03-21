#include "banking_record_system.h"

/*
    Class: User Function
*/
void Account::create_account() {
    std::cout << "Enter a username: ";
    std::cin >> username;

    std::cout << "Enter a password: ";
    std::cin >> password;

    std::cout << "Enter your first name: ";
    std::cin >> first_name;

    std::cout << "Enter your last name: ";
    std::cin >> last_name;

    std::cout << "Enter your account number: ";
    std::cin >> account_number;

    std::cout << "Enter your initial deposit: $";
    std::cin >> account_balance;

    std::cout << std::endl;
}

void Account::show_account_info() {
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Account number: " << account_number << std::endl;
    std::cout << "Account balance: $" << account_balance << std::endl;
    std::cout << std::endl;
}

void Account::show_account_balance() {
    std::cout << "Account balance: $" << account_balance << std::endl;
    std::cout << std::endl;
}

void Account::deposit() {
    std::cout << "\nHow much would you like to deposit today? \n" 
              << "$";
    std::cin >> money_deposit;
    
    std::cout << "You have deposited: $" << money_deposit << std::endl;
    std::cout << "Your old balance is: $" << account_balance << std::endl;

    account_balance = account_balance + money_deposit;
    std::cout << "Your new balance is: $" << account_balance << std::endl;
    std::cout << std::endl;
}

void Account::withdraw() {
    std::cout << "\nHow much would you like to withdraw today? \n" 
              << "$";
    std::cin >> money_withdraw;
    
    std::cout << "You have withdrawn: $" << money_withdraw << std::endl;
    std::cout << "Your old balance is: $" << account_balance << std::endl;

    account_balance = account_balance - money_withdraw;
    std::cout << "Your new balance is: $" << account_balance << std::endl;
    std::cout << std::endl;
}

/* 
    Class: System function 
*/
void Account::user_options() {
    std::cout << "Bank Record System - MAIN MENU\n"
              << "[1]. Create account.\n"
              << "[2]. Show account information.\n"
              << "[3]. Search account based on register order.\n"
              << "[4]. Deposit.\n"
              << "[5]. Withdraw.\n"
              << "[6]. Close an account.\n"
              << "[7]. Exit.\n";
}

void Account::write_file() {
    std::ofstream outfile;
    outfile.open("account_record.dat", std::ios::binary | std::ios::app);

    create_account();

    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));

    outfile.close();
}

void Account::read_file() {
    std::ifstream infile;
    infile.open("account_record.dat", std::ios::binary);

    if(!infile)
    {
        std::cout << "ERROR: Cannot Open File. File is not found!" << std::endl;
        return;
    }
    std::cout << "\n====== Data from file ======" << std::endl;

    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            show_account_info();
        }
    }

    infile.close();
}

void Account::search_file() {
    int n;

    std::ifstream infile;
    infile.open("account_record.dat", std::ios::binary);
    if(!infile)
    {
        std::cout << "ERROR: Cannot Open File. File is not found!" << std::endl;
        return; 
    }

    infile.seekg(0, std::ios::end);

    int count = infile.tellg()/sizeof(*this);

    std::cout << "There are " << count << " account in the file.\n";
    std::cout << "Enter the account order to search: ";
    std::cin >> n;

    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));

    std::cout << "Account No." << n << std::endl;
    show_account_info();
}

void Account::delete_file() {
    int n;
    std::ifstream infile;
    infile.open("account_record.dat", std::ios::binary);

    if(!infile)
    {
        std::cout << "ERROR: Cannot Open File. File is not found!" << std::endl;
        return;
    }
    infile.seekg(0, std::ios::end);

    int count = infile.tellg()/sizeof(*this);

    std::cout << "There are " << count << " account in the file.\n";
    std::cout << "Enter the account order to delete: ";
    std::cin >> n;

    std::fstream file_temp;
    file_temp.open("account_temp.dat", std::ios::out | std::ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        file_temp.write(reinterpret_cast<char*>(this), sizeof(*this));
    }

    infile.close();
    file_temp.close();
    remove("account_record.dat");
    rename("account_temp.dat", "account_record.dat");
}


/*
//System function
    void read_file();
    void write_file();
    void search_file();
    void edit_file();
    void delete_file();
*/

/*
    Main function
*/
void intro();

int main() {
    intro();

    Account user;

    bool run = true;
    char option;

    while (run) {
        user.user_options();
        std::cin >> option;

        switch (option) {
            case '1': //create account
                //user.create_account();
                std::cout << std::endl;
                user.write_file();
                system("pause");
                break;
            case '2': //show account information
                std::cout << std::endl;
                //user.show_account_info();
                user.read_file();
                system("pause");
                break;
            case '3': //show account balance
                //user.show_account_balance();
                user.search_file();
                system("pause");
                break;
            case '4': //deposit
                user.deposit();
                system("pause");
                break;
            case '5': //withdraw
                user.withdraw();
                system("pause");
                break;
            case '6': //close account
                //user.close_account();
                user.delete_file();
                system("pause");
                break;
            case '7':
                std::cout << "Exit . . .";
                run = false;
                break;
            default:
                std::cout << "ERROR: Invalid option. Please try again . . .\n" 
                          << std::endl;
                break;
        }
    }

    return 0;
}


void intro()
{
	std::cout << "\n\n"
              << "==================================\n"
              << "      BANK MANAGEMENT SYSTEM\n"
              << "==================================\n"
              << "\n\n";
    system("pause");
    std::cout << std::endl;
}