#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, mx = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		mx = max(mx, max(0, a - (N + 1 - i)));
	}
	cout << mx;
}