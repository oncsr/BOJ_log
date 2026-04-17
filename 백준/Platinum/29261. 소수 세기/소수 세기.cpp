#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int P;
	cin >> P;
	if (P < 5) { cout << 1; return 0; }
	P = P / 3 * 2;
	if (P % 4 == 0)	cout << P - 1;
	else if (P % 4 <= 2)	cout << (P - P % 4 + 3);
	else	cout << P;

}