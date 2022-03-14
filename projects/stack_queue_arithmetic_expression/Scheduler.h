#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "PendingProcess.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;


class que 
{
public:
	PendingProcess* queue;
	int n, rear;
	que(int);
	void add(string name, int time);
	void dis();
	bool empty();
	string next();
};

#endif // !SCHEDULER_H
