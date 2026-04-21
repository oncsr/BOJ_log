#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	char _;
	cin >> a >> _ >> b;
	cout << (a == b ? max(0, a - 1) : min(a, b));

}