#include <bits/stdc++.h>
#include <random>
using namespace std;
using ii = pair<int, int>;

int gcd(int a, int b) {
	if (a < b)	swap(a, b);
	while (a % b) {
		int ta = b, tb = a % b;
		a = ta, b = tb;
	}
	return b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m;
	cin >> n;
	m = (n + 1) / 2;
	vector<ii> arr(n);
	for (auto& i : arr)	cin >> i.first >> i.second;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> RN(0, n - 1);
	if (n <= 4) { cout << "success"; return 0; }
	bool exist = 0;
	int vis[100000]{};
	for (int G = 200; G--;) {
		int a = RN(gen), b;
		do b = RN(gen);	while (a == b);
		int cnt = 2;
		ii d = { 0,0 };
		if (!(arr[a].first == arr[b].first)) {
			if (arr[a].second == arr[b].second) d = { 0,1 };
			else {
				int dx = arr[a].first - arr[b].first, dy = arr[a].second - arr[b].second;
				int g = gcd(abs(dx), abs(dy));
				if (dy < 0)	dx *= -1, dy *= -1;
				d = { dx / g, dy / g };
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == a || i == b)	continue;
			int dx = arr[a].first - arr[i].first, dy = arr[a].second - arr[i].second;
			ii dn = { 0,0 };
			if (dx) {
				if (!dy)	dn = { 0,1 };
				else {
					int g = gcd(abs(dx), abs(dy));
					if (dy < 0)	dx *= -1, dy *= -1;
					dn = { dx / g, dy / g };
				}
			}
			if (d == dn)	cnt++;
			
		}
		if (cnt >= m) {
			vis[a]++, vis[b]++;
			for (int i = 0; i < n; i++) {
				if (i == a || i == b)	continue;
				int dx = arr[a].first - arr[i].first, dy = arr[a].second - arr[i].second;
				ii dn = { 0,0 };
				if (dx) {
					if (!dy)	dn = { 0,1 };
					else {
						int g = gcd(abs(dx), abs(dy));
						if (dy < 0)	dx *= -1, dy *= -1;
						dn = { dx / g, dy / g };
					}
				}
				if (d == dn)	vis[i]++;

			}
			exist = 1;
			break;
		}
	}
	if (!exist) { cout << "failure"; return 0; }
	ii A = { 1e9 + 1, 1e9 + 1 };
	ii B = A;
	ii d = { 0,0 };
	for (int i = 0; i < n; i++) {
		if (vis[i])	continue;
		if (A.first == 1e9 + 1)	A = arr[i], vis[i]++;
		else if (B.first == 1e9 + 1) {
			B = arr[i];
			if (A.first != B.first) {
				if (A.second == B.second)	d = { 0,1 };
				else {
					int dx = A.first - B.first, dy = A.second - B.second;
					int g = gcd(abs(dx), abs(dy));
					if (dy < 0)	dx *= -1, dy *= -1;
					d = { dx / g, dy / g };
				}
			}
			vis[i]++;
		}
		else {
			int dx = arr[i].first - A.first, dy = arr[i].second - A.second;
			ii dn = { 0,0 };
			if (dx) {
				if (!dy)	dn = { 0,1 };
				else {
					int g = gcd(abs(dx), abs(dy));
					if (dy < 0)	dx *= -1, dy *= -1;
					dn = { dx / g, dy / g };
				}
			}
			if (d == dn)	vis[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) { cout << "failure"; return 0; }
	}
	cout << "success";

	

}