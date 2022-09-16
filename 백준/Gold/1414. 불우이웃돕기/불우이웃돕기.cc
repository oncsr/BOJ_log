#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> li;

vector<vector<li> > V(51);
priority_queue<li, vector<li>, greater<> > Q;
int visit[51] = { 0 };
int N, cnt = 0;
string a;
ll cost = 0, sum = 0;

void dfs(int node) {
	if (!visit[node]) {
		visit[node]++;
		if (!V[node].empty()) {
			while (cnt < N - 1) {
				for (int i = 0; i < V[node].size(); i++) {
					li temp = V[node][i];
					if (!visit[temp.second])	Q.push(temp);
				}
				if (!Q.empty()) {
					li temp = Q.top();
					Q.pop();
					while (!Q.empty() && visit[temp.second]) {
						temp = Q.top();
						Q.pop();
					}
					if (Q.empty() && visit[temp.second])	return;
					cost += temp.first;
					cnt++;
					dfs(temp.second);
				}
				else return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			char ch = a[j];
			if (ch == '0')	continue;
			int m;
			if (ch > 90)	m = ch - 96;
			else	m = ch - 38;
			sum += m;
			if (i == j + 1)	continue;
			V[i].push_back({ m, j + 1 });
			V[j + 1].push_back({ m,i });
		}
	}
	dfs(1);
	if (cnt != N - 1)	cout << "-1\n";
	else	cout << sum - cost << '\n';
}