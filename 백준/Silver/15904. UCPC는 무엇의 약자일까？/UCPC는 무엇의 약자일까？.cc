#include <iostream>
#include <string>
using namespace std;
int main() {
	string a;
	getline(cin, a);
	int pos = 0;
	for (char p : a) {
		if (pos % 2 && p == 'C')	pos++;
		else if (!pos && p == 'U')	pos++;
		else if (pos == 2 && p == 'P')	pos++;
		if (pos > 3)	break;
	}
	cout << "I " << (pos > 3 ? "love" : "hate") << " UCPC";
}