# A Restaurant Trip Advisor

## Introduction:
- This is a simple retaurant trip advisor.
- This will help user to find a place to eat from the provided restaurant databases.
## Description:
- Create a simple menu options for the users:
  1. `sorted` restaurant by a Name column
      - output format = table
  2. `sorted` restaurant by a Ranking column
      - output format = table
  3. `search` restaurant Name using `a binary search`
      - output format = table
  4. `find` the best restaurant (highest ranking) with given budgets
      - output format = table
  5. `exit`

## Database Format (.csv):
- The restaurant database includes:
  1. name
  2. city
  3. ranking
  4. rating
  5. price
  6. range
  7. number of reviews

## Sample Output:
```
Select the action:
1) Show restaurants sorted by Name
2) Show restaurants sorted by Ranking
3) Find a restaurant by name
4) Find the best restaurant with a price
5) Exit the program
1
Name                    City              Ranking   Rating  Price Range   Reviews
Blavis                  Barcelona         3         5.0     $$ - $$$      643
Bodega Biarritz         Barcelona         5         5.0     $$ - $$$      1078
Chaka Khan              Barcelona         8         5.0     $$ - $$$      479
My Restaurant           Barcelona         4         5.0     $$ - $$$      159
Rudi of Pirate Cooking  Barcelona         7         5.0     $$ - $$$      110
Santa Rita Experience   Barcelona         6         5.0     $$$$          329
Spoonik Restaurant      Barcelona         9         5.0     $$$$          408
The Box                 Barcelona         10        4.5     $             834
Uma                     Barcelona         1         5.0     $$$$          792
Viana                   Barcelona         2         5.0     $$ - $$$      2707
```
## Test Case:
### Link to Program:
- [simple-restaurant-trip-advisor.cpp](https://github.com/jhuynh176/cpp_projects/blob/main/projects/restaurant_trip_advisor/restaurant_trip_advisor.cpp)
### Link to Test Case:
- [test-case.csv](https://github.com/jhuynh176/cpp_projects/blob/main/projects/restaurant_trip_advisor/test_case.csv)
