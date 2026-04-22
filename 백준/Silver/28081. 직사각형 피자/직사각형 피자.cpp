#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll W, H, K;
	cin >> W >> H >> K;

	int N, M;
	vector<ll> Y;
	vector<ll> X;
	cin >> N;
	ll s = 0;
	for (int i = 0; i < N; i++) {
		ll a;	cin >> a;
		Y.push_back(a - s);
		s = a;
	}
	Y.push_back(H - s);
	cin >> M;
	s = 0;
	for (int i = 0; i < M; i++) {
		ll a;	cin >> a;
		X.push_back(a - s);
		s = a;
	}
	X.push_back(W - s);
	
	ll ans = 0;
	sort(Y.begin(), Y.end());
	for (int i = 0; i < X.size(); i++) {
		ans += (ll)(upper_bound(Y.begin(), Y.end(), K / X[i]) - Y.begin());
	}
	cout << ans;

}