#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a;
	int temp = 0;
	cin >> n;
	int ans = 0;
	double m = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (!i) {
			temp = a;
			continue;
		}
		ans += (temp + a) * (temp + a) + (temp - a) * (temp - a);
		temp = a;
	}
	cout << ans;
}