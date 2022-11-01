#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	getline(cin, a);
	while (a != "EOI") {
		int s = 0;
		for (char i : a) {
			if (i == 'N' || i == 'n')	s++;
			else if (s == 1 && (i == 'E' || i == 'e'))	s++;
			else if (s == 2 && (i == 'M' || i == 'm'))	s++;
			else if (s == 3 && (i == 'O' || i == 'o'))	s++;
			else if (s == 4)	break;
			else	s = 0;
		}
		cout << (s == 4 ? "Found\n" : "Missing\n");
		getline(cin, a);
	}
}