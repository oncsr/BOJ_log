#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int aa = a * b, bb = c * d;
	if (aa == bb)	cout << 'E';
	else if (aa > bb)	cout << 'M';
	else	cout << 'P';
}