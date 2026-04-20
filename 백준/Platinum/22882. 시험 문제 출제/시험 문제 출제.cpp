#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[20][20]{};
ll N, K;

vector<vector<pair<ll, ll>>> res1(20);
vector<vector<pair<ll, ll>>> res2(20);

void push1(int x, int y, int sel, ll sum, ll mx1, ll right) {

	if (sel == N - 1) {
		res1[x].emplace_back(mx1, right);
		return;
	}

	sum = sum < 0 ? arr[x][y] : sum + arr[x][y];
	mx1 = max(mx1, sum);

	right = max(arr[x][y], arr[x][y] + right);

	push1(x + 1, y, sel + 1, sum, mx1, right);
	push1(x, y + 1, sel + 1, sum, mx1, right);

}

void push2(int x, int y, int sel, ll sum, ll mx1, ll right) {

	sum = sum < 0 ? arr[x][y] : sum + arr[x][y];
	mx1 = max(mx1, sum);

	right = max(arr[x][y], arr[x][y] + right);

	if (sel == N - 1) {
		res2[x].emplace_back(mx1, right);
		return;
	}

	push2(x - 1, y, sel + 1, sum, mx1, right);
	push2(x, y - 1, sel + 1, sum, mx1, right);

}

int main() {
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	ll ans = 0;
	ll inf = -1000000001;
	push1(0, 0, 0, inf, inf, inf);
	push2(N - 1, N - 1, 0, inf, inf, inf);
	for (int i = 0; i < N; i++) {
		
		vector<ll> V1, V2;
		vector<ll> VV1, VV2;

		for (auto [sum1, right] : res1[i]) {
			if (sum1 > K)	continue;
			V1.push_back(right);
			if (sum1 == K)	continue;
			VV1.push_back(right);
		}

		for (auto [sum2, left] : res2[i]) {
			if (sum2 > K)	continue;
			V2.push_back(left);
			if (sum2 == K)	continue;
			VV2.push_back(left);
		}

		sort(V2.begin(), V2.end());
		sort(VV2.begin(), VV2.end());
		ll cnt1 = 0, cnt2 = 0;
		for (ll foo : V1) {
			cnt1 += upper_bound(V2.begin(), V2.end(), K - foo) - V2.begin();
		}
		for (ll foo : VV1) {
			cnt2 += upper_bound(VV2.begin(), VV2.end(), K - 1 - foo) - VV2.begin();
		}

		ans += cnt1 - cnt2;
		
	}

	cout << ans;

}