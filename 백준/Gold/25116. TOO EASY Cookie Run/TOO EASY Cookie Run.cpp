#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll arr[100001]{}, M, K;
	int N;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	ll cnt = 0;
	int s = 1, e = 1;
	ll a = 0, b = 2000000000000000000, X = (a + b) / 2;
	while (a <= b) {
		ll s = 1, e = 1, cnt = 0;
		
		while (s <= e && s <= N) {
			if (arr[e] - arr[s - 1] + (e - s + 1) * X >= M) {
				s++;
				if (s > e) {
					e++;
				}
			}
			else {
				cnt += (e - s + 1);
				if (e == N) {
					break;
				}
				else {
					e++;
				}
			}
		}
		ll poss = (ll)N * ((ll)N + 1) / 2 - cnt;
		//cout << "X : " << X << ", possible : " << poss << '\n';
		if (poss >= K) {
			if (a == b)	break;
			b = X;
		}
		else {
			if (a == b) {
				X++;
				break;
			}
			a = X + 1;
		}
		X = (a + b) / 2;
	}
	cout << X;
}