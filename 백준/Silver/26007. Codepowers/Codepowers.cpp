#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, K, X, d[100001]{}, a, s, b;
	cin >> N >> M >> K >> X;
	s = X;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		s += a;
		if (s < K)	d[i] = d[i - 1] + 1;
		else d[i] = d[i - 1];
	}
	for (; M--;) {
		cin >> a >> b;
		cout << d[b - 1] - d[a - 1] << '\n';
	}
}