#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

bool cmp(ii a, ii b) {
	if (a.second == b.second)	return a.first < b.first;
	return a.second < b.second;
}

struct qcmp {
	bool operator()(ii b, ii a) {
		if (a.second == b.second)	return a.first < b.first;
		return a.second < b.second;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	ii arr[100000]{};
	for (int i = 0; i < N; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N, cmp);

	priority_queue<ii, vector<ii>, qcmp> Q1;	// 늦지 않은 사람들
	queue<ii> Q2;	// 늦은 사람들
	int vis[200001]{};	// 늦지 않은 사람 중 시간 다 된사람 체크용
	int pos = 0, t = 1, ans = 0;
	while (pos < N) {
		bool ent = 0;
		for (; pos < N && arr[pos].second == t; pos++) {
			if (arr[pos].first == t) {
				ent = 1;
				continue;
			}
			if (arr[pos].first > arr[pos].second) {
				Q1.push(arr[pos]);
				vis[arr[pos].first] = arr[pos].second;
			}
			else	Q2.push(arr[pos]);
		}
		if (ent) {
			t++;
			continue;
		}
		if (Q1.empty() && Q2.empty()) {
			t++;
			continue;
		}

		if (Q1.empty()) {
			ans = max(ans, t - Q2.front().second);
			Q2.pop();
		}
		else {
			if (vis[t]) {
				ans = max(ans, t - vis[t]);
				vis[t] = 0;
			}
			else {
				while (!Q1.empty() && !vis[Q1.top().first])	Q1.pop();

				int a = -1, b = -1;
				if (!Q1.empty())	a = Q1.top().second;
				if (!Q2.empty())	b = Q2.front().second;
				if (a != -1 && b != -1) {
					if (a < b || (a == b && Q1.top().first < Q2.front().second)) {
						ans = max(ans, t - a);
						vis[Q1.top().first] = 0;
						Q1.pop();
					}
					else {
						ans = max(ans, t - b);
						Q2.pop();
					}
				}
				else if (a != -1) {
					ans = max(ans, t - a);
					vis[Q1.top().first] = 0;
					Q1.pop();
				}
				else if (b != -1) {
					ans = max(ans, t - b);
					Q2.pop();
				}

			}
		}

		t++;
	}
	while (!Q1.empty() && !Q2.empty()) {
		if (vis[t]) {
			ans = max(ans, t - vis[t]);
			vis[t] = 0;
		}
		else {
			while (!Q1.empty() && !vis[Q1.top().first])	Q1.pop();
			if (Q1.empty())	break;

			ii a = Q1.top(), b = Q2.front();
			if (a.second < b.second || (a.second == b.second && a.first < b.first)) {
				ans = max(ans, t - a.second);
				vis[Q1.top().first] = 0;
				Q1.pop();
			}
			else {
				ans = max(ans, t - b.second);
				Q2.pop();
			}
		
		}

		t++;
	}
	while (!Q1.empty()) {
		if (vis[t]) {
			ans = max(ans, t - vis[t]);
			vis[t] = 0;
		}
		else {
			while (!Q1.empty() && !vis[Q1.top().first])	Q1.pop();
			if (Q1.empty())	break;
			ans = max(ans, t - Q1.top().second);
			vis[Q1.top().first] = 0;
			Q1.pop();
		}
		t++;
	}
	while (!Q2.empty()) {
		ans = max(ans, t - Q2.front().second);
		Q2.pop();
		t++;
	}
	cout << ans;
}