#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, B[5000]{}, P[5000]{};
	vector<int> A(5001, 1);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> B[i];
	for (int i = N - 1; i >= 0; i--) {
		int pos = 0;
		for (int j = 1; j <= N; j++) {
			if (!A[j])	continue;
			B[pos++] ^= j;
		}
		P[i] = B[i];
		A[B[i]] = 0;
	}
	for (int i = 0; i < N; i++)	cout << P[i] << ' ';

}