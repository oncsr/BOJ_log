#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

ll area(vector<pair<ll, ll>>& V) {
	ll ans = 0;
	int N = V.size();
	for (int i = 0; i < N; i++)
		ans += (V[i].x * (V[(i + 1) % N].y - V[(i + N - 1) % N].y));
	return abs(ans);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N;
	cin >> N;
	vector<pair<ll, ll>> arr(N);
	for (auto& [a, b] : arr)	cin >> a >> b;
	ll A = area(arr);
	ll B = 0;
	for (int i = 0; i < N; i++) {
		auto &[a, b] = arr[i];
		auto &[c, d] = arr[(i + 1) % N];
		ll dx = abs(a - c), dy = abs(b - d);
		if (dx == 0)	B += dy;
		else if (dy == 0)	B += dx;
		else	B += gcd(dx, dy);
	}
	cout << (A - B + 2) / 2;

}