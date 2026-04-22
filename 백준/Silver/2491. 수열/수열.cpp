#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, temp, mx = 0, up = 1, down = 1;
	cin >> n >> temp;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if (a - temp > 0) {
			mx = max(mx, down);
			up++;
			down = 1;
		}
		else if (a - temp < 0) {
			mx = max(mx, up);
			down++;
			up = 1;
		}
		else {
			up++, down++;
			mx = max(mx, max(up, down));
		}
		temp = a;
	}
	mx = max(mx, max(up, down));
	cout << mx;
}