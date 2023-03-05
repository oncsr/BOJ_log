#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	bool space = 0;
	getline(cin, a);
	int n = 0, o = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(' || a[i] == '<') {
			if (!i)	cout << a[i];
			else	cout << ' ' << a[i];
			space = 1;
		}
		else if (a[i] == ')' || a[i] == '>') {
			if (!i)	cout << a[i];
			else	cout << ' ' << a[i];
			space = 1;
		}
		else if (a[i] == '&') {
			if (n) {
				if (i == 1)	cout << "&&";
				else	cout << " &&";
				n = 0, space = 1;
			}
			else	n++;
		}
		else if (a[i] == '|') {
			if (o) {
				if (i == 1)	cout << "||";
				else	cout << " ||";
				o = 0, space = 1;
			}
			else	o++;
		}
		else if (a[i] == ' ') {
			space = 1;
		}
		else {
			if (space)	cout << ' ';
			cout << a[i];
			space = 0;
		}
	}
}