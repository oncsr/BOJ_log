#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, L;
	cin >> N >> L;
	int S[100001]{};

	for (int i = 1; i <= N; i++) {
		char a;
		cin >> a;
		S[i] = S[i - 1];
		if (a == 'K')	S[i]++;
		else	S[i]--;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q[200020]{};
	Q[100010].emplace(0, 0);
	for (int i = 1; i <= N; i++) {
		int x = S[i] + 100010;
		int res = 1e9;
		while (!Q[x - 1].empty() && i - Q[x - 1].top().second > L)	Q[x - 1].pop();
		if (!Q[x - 1].empty())	res = min(res, Q[x - 1].top().first + 1);
		while (!Q[x].empty() && i - Q[x].top().second > L)	Q[x].pop();
		if (!Q[x].empty())	res = min(res, Q[x].top().first + 1);
		while (!Q[x + 1].empty() && i - Q[x + 1].top().second > L)	Q[x + 1].pop();
		if (!Q[x + 1].empty())	res = min(res, Q[x + 1].top().first + 1);
		Q[x].emplace(res, i);
		if (i == N)	cout << res;
	}

}