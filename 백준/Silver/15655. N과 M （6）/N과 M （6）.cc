#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8]{};

void solve(int now, int select, vector<int> ans) {
	if (select == M) {
		for (int i : ans)	cout << i << ' ';
		cout << '\n';
		return;
	}
	if (now == N)	return;

	for (int i = now; i < N; i++) {
		ans.push_back(arr[i]);
		solve(i + 1, select + 1, ans);
		ans.pop_back();
	}

}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);

	solve(0, 0, {});

}