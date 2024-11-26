#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K, T;
	cin >> N >> K >> T;
	vector<int> A(N);
	for (int& i : A)	cin >> i, i %= K;
	sort(A.begin(), A.end());
	for (int s = 0, a; T--;) {
		cin >> a;
		s = (s + a) % K;
		auto p = lower_bound(A.begin(), A.end(), K - s);
		if (p == A.begin())	p = A.end() - 1;
		else	p--;
		cout << (*p + s) % K << ' ';
	}

}