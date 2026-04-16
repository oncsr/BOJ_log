#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[100001]{}, ans[100001]{};
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int K;
	cin >> K;
	priority_queue<tuple<int, int, int>> Q;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		Q.emplace(a, i, 1);
		Q.emplace(b, i, -1);
	}
	int e = get<0>(Q.top()), s = 1, p = e;
	sort(arr + 1, arr + e + 1);
	for (int i = e + 1; i <= N; i++)	ans[i] = arr[i];

	int id = -1, last = -1, inc = 0;
	while (!Q.empty()) {
		auto [x, i, c] = Q.top();
		Q.pop();
		if (i < id || (i == id && c > 0))	continue;
		id = i;
		if (last == -1) {
			last = x;
			if (c > 0)	inc = 1;
			else	inc = 0;
			continue;
		}
		if (inc) {
			for (int i = 0; i < last - x; i++)	ans[p--] = arr[e--];
		}
		else {
			for (int i = 0; i < last - x; i++)	ans[p--] = arr[s++];
		}
		last = x;
		if (c > 0)	inc = 1;
		else	inc = 0;
	}

	if (inc) {
		for (int i = 0; i < last; i++)	ans[p--] = arr[e--];
	}
	else {
		for (int i = 0; i < last; i++)	ans[p--] = arr[s++];
	}

	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';

}