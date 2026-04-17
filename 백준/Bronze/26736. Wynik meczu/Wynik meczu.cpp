#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (char i : s) {
		a += i == 'A';
		b += i == 'B';
	}
	cout << a << " : " << b;
}