#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	if (n < 10) {
		cout << n + 1;
		return 0;
	}
	int s = (int)log10(n);
	bool add = 0;
	int G = pow(10, s);
	int ch = n / G;
	s = s * 10 + ch - 1;
	n -= G * ch;	G /= 10;
	while (G) {
		int temp = n / G;
		if (temp > ch) {
			add = 1;
			break;
		}
		if (temp < ch)	break;
		n -= G * temp;	G /= 10;
	}
	if (add || G == 0)	s++;
	
	cout << s;

}