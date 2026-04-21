#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k = 1, root, temp;
	cin >> n >> root;
	vector<int> par(100001, -1);
	temp = root;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		if (i && par[a] == -1 && a != root) {
			k++;
			par[a] = temp;
		}
		temp = a;
	}
	cout << k << '\n';
	for (int i = 0; i < k; i++)	cout << par[i] << ' ';
}