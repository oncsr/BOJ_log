#include <iostream>
using namespace std;

int main() {
	int n;
	string a;
	cin >> n >> a;
	int b = 0, s = 0;
	for (char i : a) {
		if (i == 'b')	b++;
		if (i == 's')	s++;
	}
	if (b > s)	cout << "bigdata?";
	else if (b < s)	cout << "security!";
	else	cout << "bigdata? security!";
}