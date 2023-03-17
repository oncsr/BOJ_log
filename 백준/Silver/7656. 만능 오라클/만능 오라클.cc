#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	getline(cin, a);
	bool start = 1;
	string Q = "What is";
	int e = 0;
	bool pr = 0;
	string temp = "";
	for (int i = 0; i < a.size(); i++) {
		if (start && a[i] == ' ' && !e)	continue;
		if (start) {
			if (e == 7) {
				temp = "Forty-two is";
				if (a[i] == '?') {
					temp += '.';
					cout << temp << '\n';
					pr = 0;
					start = 1;
					e = 0;
				}
				else if (a[i] == '.') {
					temp = "";
					start = 1, e = 0;
				}
				else {
					temp += a[i];
					start = 0;
					pr = 1;
					e = 0;
				}
			}
			else if (Q[e] == a[i])	e++;
			else {
				start = 0, e = 0;
			}
		}
		else {
			if (pr) {
				if (a[i] == '?') {
					temp += '.';
					cout << temp << '\n';
					pr = 0;
					start = 1;
				}
				else if (a[i] == '.') {
					temp = "";
					pr = 0;
					start = 1;
				}
				else	temp += a[i];
			}
			else {
				if (a[i] == '.' || a[i] == '?') {
					start = 1;
				}
			}
		}
	}
}