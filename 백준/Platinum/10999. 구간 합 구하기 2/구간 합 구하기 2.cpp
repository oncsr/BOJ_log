#include <iostream>
using namespace std;
using ll = long long;
ll T[1000001]{}, S[2097153]{}, L[2097153]{};
int N, M, K, a, b, c;
ll d;
void I(int s, int e, int n) {
	if (s == e) {
		S[n] = T[s];
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	S[n] = S[n * 2] + S[n * 2 + 1];
}
void P(int s, int e, int n) {
	if (L[n]) {
		S[n] += L[n] * ((ll)e - s + 1);
		if (s != e) {
			L[n * 2] += L[n];
			L[n * 2 + 1] += L[n];
		}
		L[n] = 0;
		return;
	}
}
void Q(int s, int e, int l, int r, ll v, int n) {
	P(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		S[n] += v * ((ll)e - s + 1);
		if (s != e) {
			L[n * 2] += v;
			L[n * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	Q(s, m, l, r, v, n * 2);	Q(m + 1, e, l, r, v, n * 2 + 1);
	S[n] = S[n * 2] + S[n * 2 + 1];
}
ll F(int s, int e, int l, int r, int n) {
	P(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return S[n];
	int m = (s + e) / 2;
	return F(s, m, l, r, n * 2) + F(m + 1, e, l, r, n * 2 + 1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)	cin >> T[i];
	I(1, N, 1);
	for (M += K; M--;) {
		cin >> a >> b >> c;
		if (a % 2) {
			cin >> d;
			Q(1, N, b, c, d, 1);
		}
		else	cout << F(1, N, b, c, 1) << '\n';
	}
}