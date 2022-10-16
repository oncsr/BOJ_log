#include <iostream>
using namespace std;

int main() {
	string s;
	int n, st = 0, ed = 0, a, b;
	cin >> s >> n;
	for (; n--;) {
		cin >> a >> b;
		st += a;
		ed = st + b - 1;
	}
	for (int i = st; i <= ed; i++)	cout << s[i];
}