#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int map[3000][3000]{};
	int n, m, q, o, a, b, c;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	int order[3000]{};
	for (int i = 0; i < n; i++)	order[i] = i;
	for (; q--;) {
		cin >> o >> a >> b;
		if (o)	swap(order[a], order[b]);
		else {
			cin >> c;
			map[order[a]][b] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)	cout << map[order[i]][j] << ' ';
		cout << '\n';
	}
}