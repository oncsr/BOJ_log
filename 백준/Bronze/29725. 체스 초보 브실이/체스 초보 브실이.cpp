#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int w = 0, b = 0;
	map<char, int> M;
	M['K'] = M['k'] = 0;
	M['P'] = M['p'] = 1;
	M['N'] = M['n'] = M['B'] = M['b'] = 3;
	M['R'] = M['r'] = 5;
	M['Q'] = M['q'] = 9;
	for (int i = 0; i < 64; i++) {
		char a;
		cin >> a;
		if (a > 90)	b += M[a];
		else	w += M[a];
	}
	cout << w - b;

}