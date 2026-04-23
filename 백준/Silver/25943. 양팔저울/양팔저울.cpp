#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, l = 0, r = 0, s, c = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (!i)	l = a;
		else if (i == 1)	r = a;
		else {
			if (l <= r)	l += a;
			else	r += a;
		}
	}
	s = abs(l - r);
	while (s) {
		if (s >= 100)	s -= 100;
		else if (s >= 50)	s -= 50;
		else if (s >= 20)	s -= 20;
		else if (s >= 10)	s -= 10;
		else if (s >= 5)	s -= 5;
		else if (s >= 2)	s -= 2;
		else	s--;
		c++;
	}
	cout << c;
}