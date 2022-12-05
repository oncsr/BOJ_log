#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll N, t;
	cin >> N;
	t = N;
	int s = 0;
	while (t > 0)	t >>= 1, s++;
	ll M = (1LL << s) - 1;
	if (N == M)	cout << "1\n" << N;
	else {
		ll a = M - N, b = N;
		cout << "2\n" << min(a, b) << '\n' << max(a, b);
	}
}