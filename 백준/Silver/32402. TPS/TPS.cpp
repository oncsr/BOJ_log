#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int x = 0, y = 0, d = 0;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	for (cin >> N; N--;) {
		string o;
		cin >> o;
		int p;
		if (o == "W")	p = d;
		else if (o == "A")	p = (d + 3) % 4;
		else if (o == "S")	p = (d + 2) % 4;
		else if (o == "D")	p = (d + 1) % 4;
		else if (o == "MR")	d = (d + 1) % 4, p = -1;
		else	d = (d + 3) % 4, p = -1;
		if (p != -1)	x += dx[p], y += dy[p];
		cout << x << ' ' << y << ' ' << x - dx[d] << ' ' << y - dy[d] << '\n';
	}

}