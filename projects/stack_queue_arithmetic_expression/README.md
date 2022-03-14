# Part 1. `Stack`

## Introduction:
- The goal is to find an order in which expression will be evaluated.

## Description:
- Implement a program that given an arithmetic expression output a sequence of "subexpression" in the order they should be calculated.
- In the main function read an arithmetic expression, and print the order at which it should be evaluated as described in the previous section.

## Sample Execution
Sample 3 separate runs of the program. 

1. First run
```
User Input: ((1+3)/2)*(14+5)

1+3
(1+3)/2
14+5
((1+3)/2)*(14+5)
```
2. Second run
```
User Input: (7-19^(2+5-3)*12)+(4+10)

2+5-3
7-19^(2+5-3)*12
4+10
(7-19^(2+5-3)*12)+(4+10)
```
3. Third run
```
User Input: (7-19^(2+5-3))*12)+(4+10)

2+5-3
7-19^(2+5-3)
Invalid expression
```

# Part 2. `Queue`

## Introduction:
- Decisions on what process to run at each moment of time are done by a scheduler.
- It rapidly switches between different programs giving each one of them some time to run.
- One desired property of the schedule is to minimize the distance between moments of time when the same process is run.

## Description:
- Implement `a simple scheduler` that gives each running process equal share of the CPU and minimizes the distance between two moments of time when the same process is run.
- Assume that the process should run at least for a 1 second before switching to another one.
- `Output` contains 1 line per second the CPU is running. For each second it’s running you should print the process that your scheduler scheduled to run.
- Create a class called Scheduler. 
  - It should have a queue of pending processes as its private field. 
  - It should have 3 public methods: “add”, “next” and “empty”. 
    - “add” adds a pending process to the wait queue. 
    - “next” gives a name of the process that should be scheduled next (and puts this process to the end of the queue with time remaining decreased by 1). 
    - “empty” checks if there are any pending processes remaining.

## Sample Execution:
Each line of the input file contains a process name and number of
seconds this program has to run.
```
Office Word, 5
Google Chrome, 2
CLion, 3
Adobe Acrobat, 1
```

Output to the console.

```
Second 0: Office Word
Second 1: Google Chrome
Second 2: CLion
Second 3: Adobe Acrobat
Second 4: Office Word
Second 5: Google Chrome
Second 6: CLion
Second 7: Office Word
Second 8: CLion
Second 9: Office Word
Second 10: Office Word
```
