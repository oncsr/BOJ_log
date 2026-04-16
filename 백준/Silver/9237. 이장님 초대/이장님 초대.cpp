#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A)	cin >> i;
	sort(A.begin(), A.end(), greater<>());
	int ans = 0, c = 2;
	for (int i : A)	ans = max(ans, i + (c++));
	cout << ans;

}