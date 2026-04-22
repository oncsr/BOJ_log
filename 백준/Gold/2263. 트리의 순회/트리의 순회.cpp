#include <bits/stdc++.h>
using namespace std;

int N;
int ind[100001]{}, pod[100001]{}, ind2[100001]{};

void solve(int s1, int e1, int s2, int e2, int n) {
	if (s1 > e1 || s2 > e2)	return;
	cout << pod[e2] << ' ';
	int m = ind2[pod[e2]];
	solve(s1, m - 1, s2, s2 + m - 1 - s1, n * 2);
	solve(m + 1, e1, s2 + m - s1, e2 - 1, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ind[i];
		ind2[ind[i]] = i;
	}
	for (int i = 1; i <= N; i++)	cin >> pod[i];
	solve(1, N, 1, N, 1);
}