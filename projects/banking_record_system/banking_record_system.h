#ifndef BANKING_RECORD_SYSTEM_H
#define BANKING_RECORD_SYSTEM_H

#include <iostream>
#include <fstream>
#include <cstdlib>

/*
- This project apply the knowledge of:
    - `add`
    - `edit`
    - `search`
    - `delete`
    - `adjust records in files`

[1]. Create account
[2]. Close account
[3]. Show account information
[4]. Show account balance
[5]. Deposit money
[6]. Withdraw money
[7]. Exit
*/

class Account {
private:
    char account_number[20];
    char first_name[10];
    char last_name[10];
    float account_balance = 0.00;
    float money_deposit;
    float money_withdraw;

    char username[20];
    char password[20];
public:
//User options
    void create_account();          //read data
    void close_account();           //delete data
    void show_account_info();       //show data
    void show_account_balance();    //show data
    void deposit();                 //edit data
    void withdraw();                //edit data

//System function
    void user_options();
    void read_file();
    void write_file();
    void search_file();
    void edit_file();
    void delete_file();
    
};

#endif