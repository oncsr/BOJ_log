#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a, n, temp = 0, ex = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (ex) {
			if (a < temp)	temp = a;
			else {
				ex = 0;
				temp = a;
				if (i == n)	cout << i;
			}
		}
		else {
			if (a > temp)	temp = a;
			else {
				cout << i - 1 << '\n';
				if (a < temp) {
					ex = 1;
					temp = a;
				}
				else	temp = a;
			}
			if (i == n && !ex)	cout << i;
		}
	}
}