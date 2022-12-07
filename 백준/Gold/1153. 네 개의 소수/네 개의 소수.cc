#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int e[1000001]{}, n;
	vector<int> s;
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * 2; j <= 1000000; j += i)
				e[j] = 1;
	cin >> n;
	int S = n, a = 0, b = 0, c = 0, d = 0;
	for (int i = S - 6; i >= 2; i--)
		if (!e[i]) {
			a = i;
			break;
		}
	S -= a;
	for (int i = S - 4; i >= 2; i--)
		if (!e[i]) {
			b = i;
			break;
		}
	S -= b;
	for (int i = S - 2; i >= 2; i--)
		if (!e[i]) {
			c = i;
			break;
		}
	S -= c;
	for (int i = S; i >= 2; i--)
		if (!e[i]) {
			d = i;
			break;
		}
	S -= d;
	if (!a || !b || !c || !d)	cout << -1;
	else	cout << d << ' ' << c << ' ' << b << ' ' << a;
}