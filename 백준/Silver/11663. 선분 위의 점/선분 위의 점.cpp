#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	sort(A.begin(), A.end());
	for (int a, b; M--;) {
		cin >> a >> b;
		cout << upper_bound(A.begin(), A.end(), b) - lower_bound(A.begin(), A.end(), a) << '\n';
	}

}