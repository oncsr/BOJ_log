#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

void solve(int now, int select, vector<int> ans) {
	if (select == 6) {
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

	for (cin >> N; N; cin >> N) {

		arr.resize(N);
		for (int& i : arr)	cin >> i;

		solve(0, 0, {});
		cout << '\n';
	}

}