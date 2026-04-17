#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	getline(cin, a);
	for (char i : a) {
		if (i == ' ' || ('0' <= i && i <= '9')) { cout << i; continue; }
		int base = i <= 90 ? 65 : 97;
		cout << (char)(base + ((i - base + 13) % 26));
	}
}