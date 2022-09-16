#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int> > > V(40001);
int arr[40001][3];	// first = depth, second = ancestor, third = cost
int visit[40001] = { 0 };

int lca(int a, int b) {
	int ans = 0;
	if (a == b)	return ans;
	if (arr[a][0] > arr[b][0]) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (arr[b][0] != arr[a][0]) {
		ans += arr[b][2];
		b = arr[b][1];
	}
	if (a == b)	return ans;
	while (a != b) {
		ans += arr[a][2] + arr[b][2];
		a = arr[a][1];
		b = arr[b][1];
	}
	return ans;
}

void init(int d, int a, int c, int n) {
	if (!visit[n]) {
		visit[n]++;
		arr[n][0] = d + 1, arr[n][1] = a, arr[n][2] = c;
		for (int i = 0; i < V[n].size(); i++) {
			int g = V[n][i].first;
			if (!visit[g])	init(d + 1, n, V[n][i].second, g);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b, c, M;
	cin >> N;
	N--;
	while (N--) {
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	init(0, 0, 0, 1);
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}