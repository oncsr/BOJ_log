#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ii = pair<int, int>;

vector<vector<ii> > V(1001);
vector<vector<int> > R(1001);
int N, M, a, b, c, A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> N >> M; M--;) {
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
	}
	cin >> A >> B;
	priority_queue<ii, vector<ii>, greater<> > Q;
	Q.push({ 0,A });
	int d[1001]{};
	fill(d, d + 1001, -1);
	d[A] = 0;
	while (!Q.empty()) {
		int dist = Q.top().first;
		int node = Q.top().second;
		Q.pop();
		if (dist > d[node])	continue;
		for (ii next : V[node]) {
			if (d[next.first] == -1 || dist + next.second < d[next.first]) {
				d[next.first] = dist + next.second;
				R[next.first] = R[node];
				R[next.first].push_back(node);
				Q.push({ d[next.first], next.first });
			}
		}
	}
	cout << d[B] << '\n' << R[B].size() + 1 << '\n';
	for (int i : R[B])	cout << i << ' ';
	cout << B;
}