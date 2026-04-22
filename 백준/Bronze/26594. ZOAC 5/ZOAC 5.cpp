#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	char prev = a[0];
	int s = 1;
	for (int i = 1; i < a.size(); i++) {
		if (prev == a[i]) {
			s++;
		}
		else {
			cout << s;
			return 0;
		}
	}
	cout << s;
}