#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
ll arr[300001]{};
ll A[262145]{}, B[262145]{}, C[262145]{};
ll lazyA[262145]{}, lazyB[262145]{}, lazyC[262145]{}, lc[262145]{};
ll Aidx[100001]{}, Bidx[100001]{}, Cidx[100001]{};

void Aprop(int s, int e, int n) {
	if (lazyA[n]) {
		A[n] += lazyA[n] * ((ll)e - s + 1);
		if (s != e) {
			lazyA[n * 2] += lazyA[n];
			lazyA[n * 2 + 1] += lazyA[n];
		}
		lazyA[n] = 0;
	}
}

void Bprop(int s, int e, int n) {
	if (lazyB[n]) {
		B[n] += lazyB[n] * ((ll)e - s + 1);
		if (s != e) {
			lazyB[n * 2] += lazyB[n];
			lazyB[n * 2 + 1] += lazyB[n];
		}
		lazyB[n] = 0;
	}
}

void Cprop(int s, int e, int n) {
	if (lc[n]) {
		C[n] = 0;
		if (s != e) {
			lc[n * 2] = lc[n * 2 + 1] = 1;
			lazyC[n * 2] = lazyC[n * 2 + 1] = 0;
		}
		lc[n] = 0;
	}
	if (lazyC[n]) {
		C[n] += lazyC[n] * ((ll)e - s + 1);
		if (s != e) {
			lazyC[n * 2] += lazyC[n];
			lazyC[n * 2 + 1] += lazyC[n];
		}
		lazyC[n] = 0;
	}
}

void init(int s, int e, int n) {
	if (s == e) {
		A[n] = arr[Aidx[s]];
		B[n] = arr[Bidx[s]];
		C[n] = arr[Cidx[s]] - arr[Aidx[s]] - arr[Bidx[s]];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	A[n] = A[n * 2] + A[n * 2 + 1];
	B[n] = B[n * 2] + B[n * 2 + 1];
	C[n] = C[n * 2] + C[n * 2 + 1];
}

void Aupt(int s, int e, int l, int r, ll v, int n) {
	Aprop(s, e, n);
	if (l > r || l > e || r < s)	return;
	int m = (s + e) >> 1;
	if (l <= s && e <= r) {
		A[n] += v * ((ll)e - s + 1);
		if (s != e) {
			lazyA[n * 2] += v;
			lazyA[n * 2 + 1] += v;
		}
		return;
	}
	Aupt(s, m, l, r, v, n * 2);	Aupt(m + 1, e, l, r, v, n * 2 + 1);
	A[n] = A[n * 2] + A[n * 2 + 1];
}

void Bupt(int s, int e, int l, int r, ll v, int n) {
	Bprop(s, e, n);
	if (l > r || l > e || r < s)	return;
	int m = (s + e) >> 1;
	if (l <= s && e <= r) {
		B[n] += v * ((ll)e - s + 1);
		if (s != e) {
			lazyB[n * 2] += v;
			lazyB[n * 2 + 1] += v;
		}
		return;
	}
	Bupt(s, m, l, r, v, n * 2);	Bupt(m + 1, e, l, r, v, n * 2 + 1);
	B[n] = B[n * 2] + B[n * 2 + 1];
}

void Cupt(int s, int e, int l, int r, ll v, int n) {
	Cprop(s, e, n);
	if (l > r || l > e || r < s)	return;
	int m = (s + e) >> 1;
	if (l <= s && e <= r) {
		C[n] += v * ((ll)e - s + 1);
		if (s != e) {
			lazyC[n * 2] += v;
			lazyC[n * 2 + 1] += v;
		}
		return;
	}
	Cupt(s, m, l, r, v, n * 2);	Cupt(m + 1, e, l, r, v, n * 2 + 1);
	C[n] = C[n * 2] + C[n * 2 + 1];
}

void Cupt2(int s, int e, int l, int r, int n) {
	Cprop(s, e, n);
	if (l > r || l > e || r < s)	return;
	int m = (s + e) >> 1;
	if (l <= s && e <= r) {
		C[n] = 0;
		if (s != e) {
			lc[n * 2] = lc[n * 2 + 1] = 1;
			lazyC[n * 2] = lazyC[n * 2 + 1] = 0;
		}
		return;
	}
	Cupt2(s, m, l, r, n * 2);	Cupt2(m + 1, e, l, r, n * 2 + 1);
	C[n] = C[n * 2] + C[n * 2 + 1];
}

ll Asum(int s, int e, int l, int r, int n) {
	Aprop(s, e, n);
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return A[n];
	int m = (s + e) >> 1;
	return Asum(s, m, l, r, n * 2) + Asum(m + 1, e, l, r, n * 2 + 1);
}

ll Bsum(int s, int e, int l, int r, int n) {
	Bprop(s, e, n);
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return B[n];
	int m = (s + e) >> 1;
	return Bsum(s, m, l, r, n * 2) + Bsum(m + 1, e, l, r, n * 2 + 1);
}

ll Csum(int s, int e, int l, int r, int n) {
	Cprop(s, e, n);
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return C[n];
	int m = (s + e) >> 1;
	return Csum(s, m, l, r, n * 2) + Csum(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	int aid = 1, bid = 1, cid = 1;
	for (int i = 1; i <= N; i++) {
		char a;
		cin >> a;
		if (a == 'A')	Aidx[aid++] = i;
		if (a == 'B')	Bidx[bid++] = i;
		if (a == 'C')	Cidx[cid++] = i;
	}
	init(1, N / 3, 1);
	int Q;
	for (cin >> Q; Q--;) {
		int o, i, j;
		cin >> o >> i >> j;
		int LA = lower_bound(Aidx, Aidx + N / 3 + 1, i) - Aidx;
		int RA = upper_bound(Aidx, Aidx + N / 3 + 1, j) - Aidx;
		int LB = lower_bound(Bidx, Bidx + N / 3 + 1, i) - Bidx;
		int RB = upper_bound(Bidx, Bidx + N / 3 + 1, j) - Bidx;
		int LC = lower_bound(Cidx, Cidx + N / 3 + 1, i) - Cidx;
		int RC = upper_bound(Cidx, Cidx + N / 3 + 1, j) - Cidx;
		RA--, RB--, RC--;
		if (o == 1) {
			ll k;
			cin >> k;
			Aupt(1, N / 3, LA, RA, k, 1);
			Bupt(1, N / 3, LB, RB, k, 1);
			Cupt(1, N / 3, LA, RA, -k, 1);
			Cupt(1, N / 3, LB, RB, -k, 1);
			Cupt(1, N / 3, LC, RC, k, 1);
		}
		else if (o == 2) {
			Cupt2(1, N / 3, LC, RC, 1);
		}
		else {
			ll G = 0;
			G += Asum(1, N / 3, LA, RA, 1);
			G += Bsum(1, N / 3, LB, RB, 1);
			G += Csum(1, N / 3, LC, RC, 1);
			G += Asum(1, N / 3, LC, RC, 1);
			G += Bsum(1, N / 3, LC, RC, 1);
			cout << G << '\n';
		}
	}
}