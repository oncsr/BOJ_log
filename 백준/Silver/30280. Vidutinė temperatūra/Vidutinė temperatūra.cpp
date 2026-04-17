#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, ans = 0, s = 0;
	cin >> N;
	map<int, int> M;
	vector<int> pre;
	vector<char> arr;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		s += (a == '+' ? 1 : -1);
		arr.push_back(a);
		pre.push_back(s);
		M[s] = i;
	}
	for (int i = 0; i < N; i++) {
		int a = pre[i] + (arr[i] == '+' ? -1 : 1);
		if (M[a] < i)	continue;
		ans = max(ans, M[a] - i + 1);
	}
	cout << ans;

}