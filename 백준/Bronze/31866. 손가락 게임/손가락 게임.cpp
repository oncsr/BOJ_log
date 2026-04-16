#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int a, b;
	cin >> a >> b;
	int c = (a == b ? 2 : 0);
	if (a == 0) {
		if (b == 5)	c = 1;
	}
	else if (a == 2) {
		if (b == 0)	c = 1;
	}
	else if (a == 5) {
		if (b == 2)	c = 1;
	}
	else {
		if (b == 0 || b == 2 || b == 5)	c = 1;
		else	c = 2;
	}
	cout << (c ? (c == 1 ? '<' : '=') : '>');
}