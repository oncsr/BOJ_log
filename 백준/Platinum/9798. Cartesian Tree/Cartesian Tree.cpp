#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

ii seg[131073]{};
vector<tuple<int, int, int>> arr;
int par[50001]{}, L[50001]{}, R[50001]{}, N;

ii mrg(ii a, ii b) {
	if (a.first < b.first)	return a;
	return b;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { get<1>(arr[s - 1]), s };
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

ii find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { 1e9,-1 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return mrg(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

void sol(int s, int e, int o, int p) {
	if (s > e)	return;
	ii mid = find(1, N, s, e, 1);
	auto [_, v, r] = arr[mid.second - 1];
	par[r] = p;
	if (o == 1)	L[p] = r;
	if (o == 2)	R[p] = r;
	sol(s, mid.second - 1, 1, r);
	sol(mid.second + 1, e, 2, r);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	arr.resize(N);
	int s = 0;
	for (auto& [a, b, c] : arr)	cin >> a >> b, c = ++s;
	sort(arr.begin(), arr.end());

	init(1, N, 1);
	sol(1, N, 0, 0);

	cout << "YES\n";
	for (int i = 1; i <= N; i++)	cout << par[i] << ' ' << L[i] << ' ' << R[i] << '\n';

}