#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> root(M);
	iota(root.begin(), root.end(), 0);
	function<int(int)> find = [&](int x) -> int {
		if (x == root[x])	return x;
		return root[x] = find(root[x]);
	};

	vector<int> arr(M);
	for (int& i : arr)	cin >> i;
	sort(arr.begin(), arr.end());

	for (; K--;) {
		int a;
		cin >> a;
		int x = find(upper_bound(arr.begin(), arr.end(), a) - arr.begin());
		cout << arr[x] << '\n';
		if (x == M - 1)	continue;
		int y = find(x + 1);
		root[x] = y;
	}

}