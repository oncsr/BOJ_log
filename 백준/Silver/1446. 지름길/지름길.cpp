#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, d;
	cin >> N >> d;
	vector<vector<ii>> V(10001);
	vector<int> temp;
	temp.push_back(0);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		temp.push_back(a);
		temp.push_back(b);
	}
	temp.push_back(d);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++)
		for (int j = i + 1; j < temp.size(); j++)
			V[temp[i]].push_back({ temp[j], temp[j] - temp[i]});

	priority_queue<ii, vector<ii>, greater<>> Q;
	vector<int> D(10001, -1);
	D[0] = 0;
	Q.push({ 0,0 });
	while (!Q.empty()) {
		int now = Q.top().second;
		int dist = Q.top().first;
		Q.pop();
		for (auto e : V[now]) {
			int next = e.first;
			int cost = e.second;
			if (D[next] == -1 || D[next] > dist + cost) {
				D[next] = dist + cost;
				Q.push({ D[next], next });
			}
		}
	}
	cout << D[d];
}