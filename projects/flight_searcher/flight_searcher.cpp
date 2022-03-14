#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

struct Flight
{
    string departureCity,
           arrivalCity;
    double price;
    double distance;
};

int readFlights(ifstream& in, Flight flights[]);
void printFlight(Flight flight);
void printFlights(Flight flights[], int flightsCnt);
void printFlightsFrom(Flight flights[], int SIZE, string city);
double findHighestDistanceToPriceRatio(Flight flights[], int SIZE, int& flightIndex);
void showMenu();

int main()
{
    ifstream in;
    in.open("flights.csv");
    if (!in)
    {
        cout << "File not found!\n";
        return 1;
    }

    const int MAX_FLIGHTS = 100;
    Flight flights[MAX_FLIGHTS];
    const int FLIGHTS_SIZE = readFlights(in, flights);
    string city;

    int menuOption = -1;
    int flightIndex = -1;
    double ratio = -1;
    do
    {
        showMenu();
        cin >> menuOption;
        cin.ignore();
        switch(menuOption){
            case 1:
                printFlights(flights, FLIGHTS_SIZE);
                break;
            case 2:
                cout << "Enter departure city: ";
                getline(cin, city);
                printFlightsFrom(flights, FLIGHTS_SIZE, city);
                break;
            case 3:
                ratio = findHighestDistanceToPriceRatio(flights, FLIGHTS_SIZE, flightIndex);
                cout << "The best distance to price ratio is: " << ratio << " km/$." << endl;
                cout << setw(20) << left << "From" << setw(20) << "To" << setw(10)
                     << "Price" << setw(10) << "Distance" << endl;
                printFlight(flights[flightIndex]);
                break;
            default:
                cout << "Invalid menu option" << endl;
                break;
        }

    }while (menuOption != 4);
    cout << "Exiting the program" << endl;
    in.close();
    return 0;
}

//***********************************************************
// readFlights: Reads flight information from file.
// in - file (stream) "handle" of .csv file where flights are stored.
// flights - an array of flights with empty Flight structures. This array is filled with flights.
// returns: number of flights that were read
//***********************************************************
int readFlights(ifstream &in, Flight flights[])
{
    string priceStr,
           distanceStr;
    int flightsSize = 0;

    while (getline (in, flights[flightsSize].departureCity, ','))
    {
        getline (in, flights[flightsSize].arrivalCity, ',');
        getline (in, priceStr, ',');
        flights[flightsSize].price = stod(priceStr);
        getline (in, distanceStr);
        flights[flightsSize].distance = stod(distanceStr);
        flightsSize++;
    }
    return flightsSize;
}


//***********************************************************
// printFlight: Prints a single flight.
// flight - flight to print
// returns:
//***********************************************************
void printFlight(Flight flight){
    cout << left << fixed << setprecision(2)
         << setw(20) << flight.departureCity
         << setw(20) << flight.arrivalCity
         << setw(10) << flight.price
         << setw(10) << flight.distance << endl;
}


//***********************************************************
// printFlights: Prints flight information read from file
// Array of flight struct - Holds flight information
// FlightsCnt - Number of flights
// returns:
//***********************************************************
void printFlights(Flight flights[], int flightsCnt)
{
    cout << left << setw(20) << "From" << setw(20) << "To" << setw(10)
         << "Price" << setw(10) << "Distance" << endl;

    for (int i = 0; i < flightsCnt; i++)
    {
       printFlight(flights[i]);
    }
}

//***********************************************************
// printFlightsFrom: Prints flights that depart from a given city
// flights - an array of all flights
// SIZE - number of flights
// city - a target city of departure
// returns:
//***********************************************************
void printFlightsFrom(Flight flights[], int SIZE, string city)
{
    cout << setw(20) << left << "From" << setw(20) << "To" << setw(10)
         << "Price" << setw(10) << "Distance" << endl;
    bool flightFound = false;

    for (int i = 0; i < SIZE; i++)
    {
        if (flights[i].departureCity == city)
        {
            flightFound = true;
            printFlight(flights[i]);
        }
    }
    if (!flightFound)
    {
        cout << "No flight from " << city << "found" << endl;
    }
}

//***********************************************************
// findHighestDistanceToPriceRatio: Finds the flight with the best price
// to distance ratio
// flights - flights to print
// SIZE - size of flights array
// flightIndex - variable that after function returns
//               will contain the index of a flight with highest distance to price ratio
// returns: the highest distance to price ratio
//***********************************************************
double findHighestDistanceToPriceRatio(Flight flights[], int SIZE, int& flightIndex)
{
    flightIndex = -1;
    double highestRatio = -1;
    for (int i = 0; i < SIZE; i++) {
        if (highestRatio < (flights[i].distance / flights[i].price))
        {
            flightIndex = i;
            highestRatio = flights[i].distance / flights[i].price;
        }
    }
    return highestRatio;
}

//***********************************************************
// showMenu: Prints menu options
// returns:
//***********************************************************
void showMenu()
{
    cout << "\nSelect the action:\n"
         << "1) Display all flights\n"
         << "2) Show the flights that depart from a given city\n"
         << "3) Find a flight with the best distance to price ratio\n"
         << "4) Exit the program\n";
}
