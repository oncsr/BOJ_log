#include <iostream>
using namespace std;	
int N, T[100001]{}, S[262145]{}, a;

void I(int s, int e, int n) {
	if (s == e) {
		S[n] = 1;
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	S[n] = S[n * 2] + S[n * 2 + 1];
}

int F(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return S[n];
	int m = (s + e) / 2;
	return F(s, m, l, r, n * 2) + F(m + 1, e, l, r, n * 2 + 1);
}
void Q(int s, int e, int i, int n) {
	if (s == e) {
		S[n] = 0;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	Q(s, m, i, n * 2);
	else	Q(m + 1, e, i, n * 2 + 1);
	S[n] = S[n * 2] + S[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	I(1, N, 1);
	for (int i = 1; i <= N; i++) {
		cin >> a;
		T[a] = i;
	}
	int i = 1, j = N;
	while (i <= j) {
		Q(1, N, T[i], 1);
		cout << F(1, N, 1, T[i++], 1) << '\n';
		if (i > j)	break;
		Q(1, N, T[j], 1);
		cout << F(1, N, T[j--], N, 1) << '\n';
	}
}