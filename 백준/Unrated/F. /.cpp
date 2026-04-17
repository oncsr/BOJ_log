#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	map<ll, int> M;
	ll arr[200001]{};
	int N;
	cin >> N;
	ll mx = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		arr[i] = arr[i - 1] + a;
		if (!M[a]) {
			M[a] = i;
			if (a > mx)	mx = a, cnt = 1;
			else if (a == mx)	cnt++;
		}
		else {
			int id = M[a];
			ll S = arr[i] - arr[id - 1];
			if (S > mx)	mx = S, cnt = 1;
			else if (S == mx)	cnt++;
		}
		
	}
	cout << mx << ' ' << cnt;

}