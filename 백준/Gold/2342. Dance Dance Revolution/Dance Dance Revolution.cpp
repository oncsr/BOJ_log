#include <iostream>
#include <vector>
using namespace std;

int cal(int now, int dest) {
	if (now == 0)	return 2;
	if (now == 1) {
		if (dest == 1)	return 1;
		if (dest == 2 || dest == 4)	return 3;
		if (dest == 3)	return 4;
	}
	if (now == 2) {
		if (dest == 2)	return 1;
		if (dest == 1 || dest == 3)	return 3;
		if (dest == 4)	return 4;
	}
	if (now == 3) {
		if (dest == 3)	return 1;
		if (dest == 2 || dest == 4)	return 3;
		if (dest == 1)	return 4;
	}
	if (dest == 4)	return 1;
	if (dest == 1 || dest == 3)	return 3;
	if (dest == 2)	return 4;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<int> arr;
	arr.push_back(0);
	int a;
	for (cin >> a; a; cin >> a)	arr.push_back(a);
	int n = arr.size() - 1;
	vector<vector<int> > d(5, vector<int>(5));
	d[0][arr[1]] = d[arr[1]][0] = 2;
	for (int i = 2; i <= n; i++) {
		int next = arr[i];
		vector<vector<int> > t(5, vector<int>(5));
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (!d[x][y])	continue;
				int v1 = d[x][y] + cal(x, next);
				if (!t[next][y])	t[next][y] = v1;
				else	t[next][y] = min(t[next][y], v1);
				int v2 = d[x][y] + cal(y, next);
				if (!t[x][next])	t[x][next] = v2;
				else	t[x][next] = min(t[x][next], v2);
			}
		}
		d = t;
	}
	int mn = 1e9;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!d[i][j])	continue;
			mn = min(mn, d[i][j]);
		}
	}
	cout << mn;
}