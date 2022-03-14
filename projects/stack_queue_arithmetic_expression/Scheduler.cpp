#include <iostream>
#include<string>
#include<fstream>
#include "PendingProcess.h"
#include "Scheduler.h"
using namespace std;


que::que(int size) 
{
	rear = -1;
	n = size;
	queue = new PendingProcess[n];

	for (size_t i = 0; i < n; i++)
	{
		queue[i].name = "";
		queue->timeRemaining = -1;

	}
}

void que::add(string name, int time) 
{
	rear++;
	queue[rear].name = name;
	queue[rear].timeRemaining = time;
}

void que::dis()
{
	for (size_t i = 0; i <= rear; i++)
	{
		cout << "(" << queue[i].name << "," << queue[i].timeRemaining << ")" << endl;
	}
	  //cout << endl;
}

bool que::empty() 
{// checks if their is more work or not
	if (rear == -1) 
	{

		return false;
	}
	else 
	{

		return true;
	}
}
string que::next() 
{
	if (empty()) 
	{
		if (queue[0].timeRemaining > 0) 
		{
			queue[0].timeRemaining = queue[0].timeRemaining - 1;
			if (rear != 0) 
			{
				for (size_t i = 0; i <= rear - 1; i++)
				{
					swap(queue[i].timeRemaining, queue[i + 1].timeRemaining);
					swap(queue[i].name, queue[i + 1].name);
				}
			}
		}
		string nam = queue[rear].name;
		if (queue[rear].timeRemaining == 0) 
		{
			queue[rear].name = "";
			queue[rear].timeRemaining = -1;
			rear = rear - 1;
		}
		return nam;
	}
}