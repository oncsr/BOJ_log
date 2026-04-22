#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, K, i = 1, P = 2, cnt = 0, KK = 1, len = 0;
	cin >> N >> K;
	while (K--)	KK *= 2;
	while (1) {
		len += (P / 2);
		ll G = (P - 1) / KK;
		if (len <= N) {
			cnt += min(G + 1, P);
		}
		else {
			cnt += max(0LL, min(P, G + 1) - (len - N));
			break;
		}
		P *= 2;
	}
	cout << cnt;
}