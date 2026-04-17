#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, c = 0;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; i++)	cin >> arr[i].first, arr[i].second = i;

	sort(arr.begin(), arr.end());
	vector<int> ans(N);
	ans[arr[0].second] = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i].first != arr[i - 1].first)	c++;
		ans[arr[i].second] = c;
	}
	for (int& i : ans)	cout << i << ' ';

}