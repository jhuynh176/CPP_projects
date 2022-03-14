#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


struct Restaurant
{
    string name,
           city,
           range;
    int ranking = -1,
        reviews = -1;
    double rating = -1;
};

int readRestaurants(ifstream& in, Restaurant restaurants[]);

void printMenu();
void printHeader();
void printRestaurant(const Restaurant& restaurant);
void printRestaurants(Restaurant restaurants[], int SIZE);

void sortRestaurantsByRanking(Restaurant restaurants[], int SIZE);
void sortRestaurantsByName(Restaurant restaurants[], int SIZE);

int binarySearchName(Restaurant restaurants[], int SIZE, const string& name);
bool isInPriceRange(const string& priceRange, const string& targetPrice);
int findBestRestaurantWithPrice(Restaurant restaurants[], int SIZE, const string& targetPrice);

const int MAXSIZE = 100;


int main() {
    string filename = "restaurants.csv";
    ifstream in(filename);
    if (!in)
    {
        cout << "Error opening a file: " << filename << endl;
        return 1;
    }

    string tmp;
    getline(in, tmp);

    Restaurant restaurants[MAXSIZE];
    const int SIZE = readRestaurants(in, restaurants);
    string name,
           targetPrice,
           isInPriceRange;
    int index = -1;
    int menuOption = -1;

    do {
        printMenu();
        cin >> menuOption;
        cin.ignore();

        switch (menuOption)
        {
            case 1:
                sortRestaurantsByName(restaurants, SIZE);
                printRestaurants(restaurants, SIZE);
                break;
            case 2:
                sortRestaurantsByRanking(restaurants, SIZE);
                printRestaurants(restaurants, SIZE);
                break;
            case 3:
                cout << "Please enter a restaurant name: " << endl;
                getline(cin, name);
                sortRestaurantsByName(restaurants, SIZE);
                index = binarySearchName(restaurants, SIZE, name);
                if(index == -1) {
                    cout << "Restaurant with an entered name is not found." << endl;
                }
                else {
                    printHeader();
                    printRestaurant(restaurants[index]);
                }
                break;
            case 4:
                cout << "Please enter a price ($, $$, $$$ or $$$$)." << endl;
                cin >> targetPrice;
                sortRestaurantsByRanking(restaurants, SIZE);
                index = findBestRestaurantWithPrice(restaurants, SIZE, targetPrice);
                if(index == -1) {
                    cout << "No restaurants with entered price." << endl;
                }
                else {
                    printHeader();
                    printRestaurant(restaurants[index]);
                }
                break;
            case 5:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid input" << endl << endl;
        }
    }while(menuOption != 5);
    in.close();
    return 0;
}

//***********************************************************
// printMenu: prints the menu
// returns:
//***********************************************************
void printMenu(){
    cout << endl
         << "Select the action:" << endl
         << "1) Show restaurants sorted by Name" << endl
         << "2) Show restaurants sorted by Ranking" << endl
         << "3) Find a restaurant by name" << endl
         << "4) Find the best restaurant with a price" << endl
         << "5) Exit the program" << endl;
}

//***********************************************************
// readRestaurants: reads restaurants from a file
// in - file stream object
// restaurants - list of uninitialized restaurants
// returns: number of restaurants read (size of useful part of restaurants array)
//***********************************************************
int readRestaurants(ifstream& in, Restaurant restaurants[]) {
    string rankingStr, ratingStr, reviewsStr;
    int size = 0;

    while(getline(in, restaurants[size].name, ',') &&
          getline(in, restaurants[size].city, ',') &&
          getline(in,rankingStr,',') &&
          getline(in,ratingStr,',') &&
          getline(in, restaurants[size].range, ',') &&
          getline(in,reviewsStr))
    {
        restaurants[size].ranking = stoi(rankingStr);
        restaurants[size].rating = stod(ratingStr);
        restaurants[size].reviews = stoi(reviewsStr);
        size++;
    }
    return size;
}


//***********************************************************
// printHeader: print the header of the restaurants table
// returns:
//***********************************************************
void printHeader(){
    cout << left
         << setw(25) << "Name"
         << setw(15) << "City"
         << setw(8) << "Ranking"
         << setw(8) << "Rating"
         << setw(12) << "Price Range"
         << setw(8) << "Reviews"
         << endl;
}


//***********************************************************
// printRestaurant: prints a single restaurant in a nice format
// returns:
//***********************************************************
void printRestaurant(const Restaurant& restaurant){
    cout << left
         << setw(25) << restaurant.name
         << setw(15) << restaurant.city
         << setw(8) << restaurant.ranking
         << setw(8) << restaurant.rating
         << setw(12) << restaurant.range
         << setw(8) << restaurant.reviews
         << endl;
}


//***********************************************************
// printRestaurants: prints restaurants in a given array
// restaurants - an array of restaurants
// SIZE - size of the restaurants array
// returns:
//***********************************************************
void printRestaurants(Restaurant restaurants[], const int SIZE) {
    printHeader();
    for(int i = 0; i < SIZE; i++)
        printRestaurant(restaurants[i]);
}


//***********************************************************
// sortRestaurantsByRanking: sorts an array of restaurants by ranking
// restaurants - an array of restaurants
// SIZE - size of the restaurants array
// returns:
//***********************************************************
void sortRestaurantsByRanking(Restaurant restaurants[], const int SIZE) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < (SIZE - 1); i++) {
            if(restaurants[i].ranking > restaurants[i + 1].ranking) {
                swap(restaurants[i], restaurants[i + 1]);
                swapped = true;
            }
        }
    }while (swapped);
}


//***********************************************************
// sortRestaurantsByName: sorts restaurants by name
// restaurants - an array of restaurants
// SIZE - size of the restaurants array
// returns:
//***********************************************************
void sortRestaurantsByName(Restaurant restaurants[], const int SIZE) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < (SIZE - 1); i++) {
            if(restaurants[i].name > restaurants[i + 1].name) {
                swap(restaurants[i], restaurants[i + 1]);
                swapped = true;
            }
        }
    } while(swapped);
}


//***********************************************************
// binarySearchName: search a restaurant by name using binary search
// restaurants - an array of restaurants
// SIZE - size of the restaurants array
// name - target restaurant name
// returns: index of the restaurant with a given name
//***********************************************************
int binarySearchName(Restaurant restaurants[], const int SIZE, const string& name) {
    int first = 0,
        last = SIZE - 1,
        middle,
        position = -1;
    bool found = false;

    while (first <= last && !found) {
        middle = (first + last) / 2;

        if (restaurants[middle].name == name) {
            found = true;
            position = middle;
        }   else if (name < restaurants[middle].name) {
            last = middle - 1;
        }   else {
            first = middle + 1;
        }
    }
    return position;
}


//***********************************************************
// isInPriceRange: checks whether targetPrice is in the priceRange
// priceRange - price range of a restaurant
// targetPrice - target price we're interested in
// returns: true if targetPrice is in the priceRange, false otherwise
//***********************************************************
bool isInPriceRange(const string& priceRange, const string& targetPrice) {
    if(priceRange == targetPrice)
        return true;
    else if ((targetPrice == "$$" || targetPrice == "$$$") && priceRange == "$$ - $$$")
        return true;
    return false;
}


//***********************************************************
// findBestRestaurantWithPrice: finds the best (highest Ranking) restaurant with a given price
// restaurants - an array of restaurants
// SIZE - size of the restaurants array
// targetPrice - target price of the restaurant the function searches for
// returns: index of the best restaurant with a targetPrice
//***********************************************************
int findBestRestaurantWithPrice(Restaurant restaurants[], const int SIZE, const string& targetPrice) {
    for (int i = 0; i < SIZE; i++)
    {
        if (isInPriceRange(restaurants[i].range, targetPrice))
        {
            return i;
        }
    }
    return -1;
}
