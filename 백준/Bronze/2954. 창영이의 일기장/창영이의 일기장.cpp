#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	getline(cin, a);
	for (int i = 0; i < a.size(); i++) {
		char c = a[i];
		cout << c;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')	i += 2;
	}
}