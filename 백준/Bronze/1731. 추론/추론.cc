#include <iostream>
using namespace std;

int main() {
	int N, a, b, c, e, p = 0, q = 0;
	cin >> N >> a >> b >> c;
	int d = b - a, r = b / a;
	if (c - b == d)	p++;
	for (int i = 0; i < N - 3; i++)	cin >> e;
	if (p)	cout << a + N * d;
	else {
		for (int i = 0; i < N; i++)	a *= r;
		cout << a;
	}
}