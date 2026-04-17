#include <bits/stdc++.h>
using namespace std;

int N;
int seg[262145]{};
int arr[100001]{};

int init(int s, int e, int n) {
	if (s == e)	return seg[n] = 1;
	int m = (s + e) >> 1;
	return seg[n] = init(s, m, n * 2) + init(m + 1, e, n * 2 + 1);
}

void upt(int s, int e, int i, int n) {
	if (s == e) {
		seg[n]--;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int s, int e, int v, int n) {
	if (s == e)	return s;
	int m = (s + e) >> 1;
	if (seg[n * 2] >= v)	return find(s, m, v, n * 2);
	return find(m + 1, e, v - seg[n * 2], n * 2 + 1);
}

vector<vector<int>> ans;
vector<int> temp;
int vis[100001]{};

void dfs(int n) {
	if (vis[n]) {
		ans.push_back(temp);
		temp = vector<int>();
		return;
	}
	vis[n]++;
	temp.push_back(n);
	dfs(arr[n]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	init(1, N, 1);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		int pos = find(1, N, a + 1, 1);
		arr[pos] = i;
		upt(1, N, pos, 1);
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i])	continue;
		dfs(i);
	}
	for (auto V : ans) {
		cout << '(';
		for (int i = 0; i < V.size(); i++) {
			cout << V[i];
			if (i != V.size() - 1)	cout << ' ';
		}
		cout << ") ";
	}

}