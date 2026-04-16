#include <bits/stdc++.h>
using namespace std;

int score[100001]{}, cnt[100001]{}, sz = 0, N, M, K, ans = 0;
pair<int, int> yet[20]{};

void sol(int idx, int mx) {
	if (idx == sz) {
		if (score[K] == mx && cnt[mx] == 1)	ans++;
		return;
	}
	auto [a, b] = yet[idx];
	
	cnt[score[a]]--; score[a]++; cnt[score[a]]++;
	sol(idx + 1, max(mx, score[a]));
	cnt[score[a]]--; score[a]--; cnt[score[a]]++;

	cnt[score[b]]--; score[b]++; cnt[score[b]]++;
	sol(idx + 1, max(mx, score[b]));
	cnt[score[b]]--; score[b]--; cnt[score[b]]++;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!c)	yet[sz++] = { a,b };
		else {
			int win = c == 1 ? a : b;
			cnt[score[win]]--;
			score[win]++;
			cnt[score[win]]++;
		}
	}

	sol(0, *max_element(score, score + N + 1));
	cout << ans;

}