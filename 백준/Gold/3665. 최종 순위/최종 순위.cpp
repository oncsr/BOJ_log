#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	for (cin >> t; t--;) {
		int n;
		cin >> n;

		vector<deque<int>> V(n + 1);
		vector<int> arr(n);
		for (int& i : arr)	cin >> i;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				V[arr[i]].push_back(arr[j]);
			}
		}

		int m;
		for (cin >> m; m--;) {
			int a, b;
			cin >> a >> b;
			bool find = 0;
			for (int cnt = V[a].size(); cnt--;) {
				int c = V[a].front();
				V[a].pop_front();
				if (c == b) { find = 1; V[b].push_back(a); break; }
				V[a].push_back(c);
			}
			if (find)	continue;
			V[a].push_back(b);
			for (int cnt = V[b].size(); cnt--;) {
				int c = V[b].front();
				V[b].pop_front();
				if (c == a)	break;
				V[b].push_back(c);
			}
		}
		
		vector<int> D(n + 1);
		queue<int> Q;
		vector<vector<int>> V2(n + 1);
		for (int i = 1; i <= n; i++) {
			if (!(D[i] = V[i].size()))	Q.push(i);
			for (int j : V[i])	V2[j].push_back(i);
		}

		stack<int> ans;
		bool ques = 0;
		while (!Q.empty()) {
			int now = Q.front();
			ans.push(now);
			Q.pop();
			int cnt = 0;
			for (int i : V2[now]) {
				if (!(--D[i]))	Q.push(i), cnt++;
			}
			if (cnt > 1) ques = 1;
		}

		if (ans.size() != n) { cout << "IMPOSSIBLE\n"; continue; }
		if (ques) { cout << "?\n"; continue; }
		while (!ans.empty())	cout << ans.top() << ' ', ans.pop();
		cout << '\n';

	}

}