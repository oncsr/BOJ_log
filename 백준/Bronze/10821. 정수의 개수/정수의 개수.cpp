#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	int a = 1;
	for (char i : s)	a += i == ',';
	cout << a;

}