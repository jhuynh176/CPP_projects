# Single Account Log-in System

## Introduction
- The main objective of Account Log-in System is to perform:
    - `Register` account
    - `Log-in` account
    - `Create` new password
    - `Modify` account information

## Description
- The program will accept string input from user.
- Only username >= 8 letters, and password >= 16 letters will be accepted as valid.
- If either the username or password is incorrect, then it should display the appropriate error message.
- If either the username or password is correct, then it should display "Successfully logged in . . ."

## Functions
- `compiler`
- `vector`
- `class`
- `functions`
- `object-oriented programming`

## Skeleton
```
class Account {
private:
    std::string name;
    int age;
    std::string fname;
    std::string lname;

    std::string username;
    std::string password;

    //Default login tries = 3
    int tries;
public:
    Account ();
};
```