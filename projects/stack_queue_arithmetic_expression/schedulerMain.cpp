#include <iostream>
#include<string>
#include<fstream>
#include "PendingProcess.h"
#include "Scheduler.h"
using namespace std;

void in_file(que& obj);

void main() {
	int a = 4;
	que obj(a);
	in_file(obj);
	//obj.dis();
	int i = 0;
	while (obj.empty())
	{
		cout << "Second " << i << ": " << obj.next() << endl;
		i++;
	}

	//obj.dis();
	system("pause");
}
void in_file(que& obj) 
{
	ifstream in;
	in.open("pendingProcessList.csv");
	string a;
	int b;

	for (size_t i = 0; i < 4; i++)
	{
		getline(in, a, ',');
		in >> b;
		obj.add(a, b);
	}
}