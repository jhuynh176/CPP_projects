# A Flight Searcher

## Description:
- The objective is to write the program that can help you process the database. 
-  Your program should be able to:  
   1. display the database in a readable format, 
   2. show flights that depart from a given city, 
   3. find the flight with the best distance to price ratio and show it together with the ratio.


## Instruction:
- The program should run in a while loop. Each iteration the program should ask to enter the menu option (1-4). 
- Depending on the menu option the program should do the following:
  1. `Show` all the flights in a database in a human readable format.   
  2. `Ask` for a city name. Then show the flights that depart from that city.
  3. `Print` the best (highest) distance to price ratio and a flight that has it. 
  4. `Exit` the loop

## Sample Output:
```
Select the action:
1) Display all flights
2) Show the flights that depart from a given city
3) Find a flight with the best distance to price ratio
4) Exit the program
1
Austin            Houston           109   140
Washington D.C.   Seattle           139   421
Austin            New York          94    1511
Dallas            Austin            93    74
Chicago           Las Vegas         149   1039
```

## Test Case (.csv):
- The database is stored in a CSV (comma-separated values) file.
- It’s a file format used to store tabular data. 
- Rows are separated with an endline symbol and individual values are separated by comma.
- Note, values stored cannot contain comma or endline symbol.

### Link to Program:
- [simple-flight-seacher.cpp](https://github.com/jhuynh176/cpp_projects/blob/main/projects/flight_searcher/flight_searcher.cpp)
### Link to Test Case: 
- [test-case.csv](https://github.com/jhuynh176/cpp_projects/blob/main/projects/flight_searcher/test_case.csv)
