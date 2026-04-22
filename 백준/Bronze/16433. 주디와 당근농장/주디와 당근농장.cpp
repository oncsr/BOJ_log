#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, r, c;
	cin >> n >> r >> c;
	string a = "", b = "";
	for (int i = 0; i < n; i++)	a += (i & 1 ? 'v' : '.');
	for (int i = 0; i < n; i++)	b += (i & 1 ? '.' : 'v');
	if ((r ^ c) & 1) {
		for (int i = 0; i < n / 2; i++)	cout << a << '\n' << b << '\n';
		if (n & 1)	cout << a;
	}
	else {
		for (int i = 0; i < n / 2; i++)	cout << b << '\n' << a << '\n';
		if (n & 1)	cout << b;
	}
	
}