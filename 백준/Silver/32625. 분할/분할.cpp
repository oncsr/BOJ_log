#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A)	cin >> i;

	for (int j = 1; j < N; j++) {
		if (N % j)	continue;
		int l = 1e9, r = 0, p = 1;
		for (int i = 0; i < j; i++)	l = min(l, A[i]), r = max(r, A[i]);
		for (int i = j; i < N; i += j) {
			int s = 1e9, e = 0;
			for (int k = i; k < i + j; k++)	s = min(s, A[k]), e = max(e, A[k]);
			if (l + r != s + e) { p = 0; break; }
		}
		if (p)	return cout << 1, 0;
	}
	cout << 0;
	
}