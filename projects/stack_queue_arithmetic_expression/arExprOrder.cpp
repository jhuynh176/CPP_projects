//#include <iostream>
#include <stack>
#include <string>


using namespace std;


int main()
{
	stack <int> stackone;
	string s;
	cout << "enter the expression : ";
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			stackone.push(i);
		}
		else if (s[i] == ')') {
			if (!stackone.empty()) {
				int posstart = stackone.top() + 1;
				stackone.pop();
				int posend = i - posstart;
				cout << s.substr(posstart, posend) << endl;
			}
			else {
				cout << "invalid expression.\n";
				exit(0);
			}
		}
		
	}
	cout << s;
	cout << endl;
	return 0;
}


