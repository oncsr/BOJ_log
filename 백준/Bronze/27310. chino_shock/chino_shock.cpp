#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	int s = a.size();
	for (char i : a) {
		if (i == ':')	s++;
		if (i == '_')	s += 5;
	}
	cout << s;
}