#include <bits/stdc++.h>
using namespace std;

int root[501]{};
int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	iota(root, root + N + 1, 0);
	map<string, int> K;
	string arr[501]{};
	for (int i = 1; i <= N; i++) {
		string a;
		cin >> a >> a >> a;
		K[a] = i;
		arr[i] = a;
	}

	for (; M--;) {
		string a;
		cin >> a >> a >> a;
		string A = "";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == ',')	break;
			A += a[i];
		}
		cin >> a >> a;
		string B = "";
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == ',')	break;
			B += a[i];
		}
		int w = a.back() - '0';
		int x = find(K[A]), y = find(K[B]);
		if (x == y) {
			if (w == 1)	root[x] = root[y] = root[K[A]] = root[K[B]] = K[A];
			else	root[x] = root[y] = root[K[A]] = root[K[B]] = K[B];
		}
		else {
			if (w == 1)	root[x] = root[y] = x;
			else	root[x] = root[y] = y;
		}
	}

	vector<string> ans;
	for (int i = 1; i <= N; i++) {
		int x = find(i);
		if (x == i)	ans.push_back(arr[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans)	cout << "Kingdom of " << i << '\n';


}