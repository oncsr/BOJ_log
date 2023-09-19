#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define x first
#define y second

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ii arr[52]{};
	int N;
	ll S, E;
	cin >> N;
	pair<ll, ll> SY, EY;
	for (int i = 0; i < N + 1; i++)	cin >> arr[i].x >> arr[i].y;
	cin >> S >> E;

	int pos = 0;
	while (pos < N) {
		if (arr[pos].x <= S && S <= arr[pos + 1].x)	break;
		pos++;
	}
	SY.x = (arr[pos + 1].y - arr[pos].y) * (S - arr[pos].x) + (arr[pos + 1].x - arr[pos].x) * arr[pos].y;
	SY.y = arr[pos + 1].x - arr[pos].x;

	while (pos < N) {
		if (arr[pos].x <= E && E <= arr[pos + 1].x)	break;
		pos++;
	}
	EY.x = (arr[pos + 1].y - arr[pos].y) * (E - arr[pos].x) + (arr[pos + 1].x - arr[pos].x) * arr[pos].y;
	EY.y = arr[pos + 1].x - arr[pos].x;

	pair<ll, ll> ans;
	ans.x = EY.x * SY.y - SY.x * EY.y;
	ans.y = (E - S) * EY.y * SY.y;

	if (ans.x == 0) {
		cout << 0;
		return 0;
	}
	ll g = gcd(abs(ans.x), abs(ans.y));
	ans.x /= g, ans.y /= g;
	cout << abs(ans.x);
	if (ans.y != 1)	cout << '/' << ans.y;

}