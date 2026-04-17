#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	queue<int> next[500001]{};
	int d[500001]{};
	int arr[500001]{};
	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
		next[arr[i]].emplace(i);
	}
	for (int i = 1; i <= K; i++)	next[i].emplace(K + 1);

	int use[500001]{}, cnt = 0, ans = 0;
	priority_queue<pair<int, int>> Q;
	for (int i = 1; i <= K; i++) {
		int a = arr[i];
		if (use[a]) { next[a].pop(); Q.emplace(next[a].front(), a); continue; }
		if (cnt < N) { use[a] ^= 1; next[a].pop(); Q.emplace(next[a].front(), a); cnt++; continue; }
		ans++;
		int rem = Q.top().second;
		Q.pop(); 
		use[rem] ^= 1;
		use[a] ^= 1;
		next[a].pop();
		Q.emplace(next[a].front(), a);
	}
	cout << ans;

}