#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(50001);
pair<int, int> arr[50001]{};	// first = depth, second = ancestor
int visit[50001] = { 0 };

int lca(int a, int b) {
	if (a == b)	return a;
	if (arr[a].first > arr[b].first) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (arr[b].first != arr[a].first) {
		b = arr[b].second;
	}
	if (a == b)	return a;
	while (arr[a].second != arr[b].second) {
		a = arr[a].second;
		b = arr[b].second;
	}
	return arr[a].second;
}

void init(int d, int a, int n) {
	if (!visit[n]) {
		visit[n]++;
		arr[n] = { d + 1,a };
		for (int i = 0; i < V[n].size(); i++) {
			int g = V[n][i];
			if (!visit[g])	init(d + 1, n, g);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b, M;
	cin >> N;
	N--;
	while (N--) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	init(0, 0, 1);
	cin >> M;
	while (M--) {
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}