#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, R;
	cin >> N >> R;
	N -= R;
	vector<ll> V;
	for (ll i = 1; i * i <= N; i++) {
		if (N % i == 0)	V.push_back(i);
	}
	ll s = 0;
	for (int i = 0; i < V.size(); i++) {
		ll g = N / V[i];
		if (g <= R)	break;
		s += g;
	}
	for (int i = V.size() - 1; i >= 0; i--) {
		if (V[i] * V[i] == N)	continue;
		if (V[i] <= R)	break;
		s += V[i];
	}
	cout << s;
}