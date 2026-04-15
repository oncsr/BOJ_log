#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int N, K, P;
vector<vector<int>> V(300001), R(300001);
int d1[300001]{}, d2[300001]{};
ll c1[300001]{}, c2[300001]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K >> P;
	for (int i = 0, a, b; i < P; i++) {
		cin >> a >> b;
		V[b].push_back(a);
		d1[a]++;
		R[a].push_back(b);
		d2[b]++;
	}

	int num1 = N - K;
	priority_queue<int, vector<int>, greater<>> Q1;
	for (int i = 0; i < K; i++) if (!d1[i]) Q1.push(i);
	while (!Q1.empty()) {
		int n = Q1.top();	Q1.pop();
		c1[n] = num1++;
		for (int j : V[n]) if (!--d1[j]) Q1.push(j);
	}

	int num2 = K - 1;
	priority_queue<int, vector<int>, greater<>> Q2;
	for (int i = 0; i < K; i++) if (!d2[i]) Q2.push(i);
	while (!Q2.empty()) {
		int n = Q2.top();	Q2.pop();
		c2[n] = num2--;
		for (int j : R[n]) if (!--d2[j]) Q2.push(j);
	}

	ll mx = 0, mn = 0, d = 1;
	for (int i = 0; i < K; i++) {
		mx = (mx + d * c1[i]) % mod;
		mn = (mn + d * c2[i]) % mod;
		d = (d * N) % mod;
	}
	cout << (mx + mod - mn) % mod;

}