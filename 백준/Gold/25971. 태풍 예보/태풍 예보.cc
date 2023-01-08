#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct typhoon {
	ll date, x, y, dir;
};
struct people {
	ll date, x, y, idx;
};

bool cmp1(people a, people b) {
	if (a.date == b.date) {
		if (a.x == b.x) {
			if (a.y == b.y)
				return a.idx < b.idx;
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.date < b.date;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K, Q, a, b, c;
	ll R;
	cin >> N >> K >> R >> Q;
	vector<typhoon> T;
	int temp_a, temp_b, temp_c, d = 0;
	for (int i = 0; i < K; i++) {
		cin >> a >> b >> c;
		if (!i) {
			temp_a = a, temp_b = b, temp_c = c;
			continue;
		}
		if (b == temp_b) {
			if (c > temp_c)	d = 1;
			else	d = 3;
		}
		else {
			if (b > temp_b)	d = 2;
			else	d = 4;
		}
		T.push_back({ temp_a, temp_b, temp_c, d });
		temp_a = a, temp_b = b, temp_c = c;
		if (i == K - 1)	T.push_back({ a,b,c,d });
	}
	vector<people> P;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c;
		P.push_back({ a,b,c,i });
	}
	sort(P.begin(), P.end(), cmp1);
	int T_size = K, P_size = Q, pos = 0, T_pos = 0;
	vector<string> ans(Q);
	typhoon cur = T[T_pos];
	while (pos < P_size) {
		people per = P[pos++];
		while (T_pos < K - 1 && T[T_pos + 1].date <= per.date) {
			cur = T[++T_pos];
		}
		int dir = cur.dir, x, y, term = per.date - cur.date;
		if (dir == 1) {
			x = cur.x, y = cur.y + term;
		}
		else if (dir == 2) {
			x = cur.x + term, y = cur.y;
		}
		else if (dir == 3) {
			x = cur.x, y = cur.y - term;
		}
		else {
			x = cur.x - term, y = cur.y;
		}
		ll r = (x - per.x) * (x - per.x) + (y - per.y) * (y - per.y);
		if ((dir == 1 || dir == 3) && per.x == x && r <= R * R)
			ans[per.idx] = "gori";
		else if ((dir == 2 || dir == 4) && per.y == y && r <= R * R)
			ans[per.idx] = "gori";
		else {
			if (r <= R * R) {
				if (dir == 1)
					ans[per.idx] = per.x < x ? "safe" : "unsafe";
				else if (dir == 2)
					ans[per.idx] = per.y > y ? "safe" : "unsafe";
				else if (dir == 3)
					ans[per.idx] = per.x > x ? "safe" : "unsafe";
				else
					ans[per.idx] = per.y < y ? "safe" : "unsafe";
			}
			else	ans[per.idx] = "gori";
		}
	}
	for (int i = 0; i < Q; i++)	cout << ans[i] << '\n';
}