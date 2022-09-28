#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ii = pair<int, int>;
#define x first
#define y second

int v, e, k, d[20001]{};
vector<vector<ii> > V(20001);
priority_queue<ii, vector<ii>, greater<> > Q;
int a, b, c;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		V[a].push_back({ c,b });
	}
	for (int i = 1; i <= v; i++) {
		if (i == k)	d[i] = 0;
		else	d[i] = -1;
	}
	Q.push({ 0,k });
	while(!Q.empty()) {
		int node = Q.top().y;
		int w = Q.top().x;
		Q.pop();
		if (w > d[node])	continue;
		for (ii next : V[node]) {
			if ((d[next.y] == -1) || (d[node] + next.x < d[next.y])) {
				d[next.y] = d[node] + next.x;
				ii temp = { d[next.y], next.y };
				Q.push(temp);
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == -1)	cout << "INF\n";
		else	cout << d[i] << '\n';
	}
}