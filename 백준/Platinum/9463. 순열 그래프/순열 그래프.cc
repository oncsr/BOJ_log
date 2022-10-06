#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> arr(100001);
vector<int> b(100001);
vector<int> seg(262145);

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

void update(int s, int e, int p, int n) {
	if (s == e) {
		seg[n] = 1;
		return;
	}
	int m = (s + e) / 2;
	if (p <= m)	update(s, m, p, n * 2);
	else	update(m + 1, e, p, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;	cin >> T;
	while (T--) {
		arr = vector<int>(100001);
		b = vector<int>(100001);
		seg = vector<int>(262145);
		int N, a;
		ll s = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)	cin >> arr[i];
		for (int i = 1; i <= N; i++) {
			cin >> a;
			b[a] = i;
		}

		for (int i = 1; i <= N; i++) {
			int g = b[arr[i]];
			s += (ll)find(1, N, g + 1, N, 1);
			update(1, N, g, 1);
		}
		cout << s << '\n';
	}
}