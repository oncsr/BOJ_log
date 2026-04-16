#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N, M;
		cin >> N >> M;
		vector<int> A(N), B(M);
		for (int& i : A)	cin >> i;
		for (int& i : B)	cin >> i;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int a = 0, b = 0, ans = 0;
		while (b < M) {
			while (a < N && B[b] >= A[a])	a++;
			ans += (N - a);
			b++;
		}
		cout << ans << '\n';
	}

}