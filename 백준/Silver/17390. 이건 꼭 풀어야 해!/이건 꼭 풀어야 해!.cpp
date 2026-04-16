#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int& i : A) cin >> i;
	sort(A.begin(), A.end());
	for (int i = 1; i < N; i++) A[i] += A[i - 1];
	for (int a, b; M--;) {
		cin >> a >> b;
		cout << A[b - 1] - (a == 1 ? 0 : A[a - 2]) << '\n';
	}

}