#include <bits/stdc++.h>
using namespace std;
#define pr(x) cout<<x<<' '
#define rep(x) for(int i=0;i<x;i++)

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1) { pr(m); return 0; }
	int g = sqrt(m);
	for (int c = -1; c <= 1; c++) {
		int s = g + c, t = m - s * s + 1;
		if (0 <= t && t <= s) {
			rep(s - 1)pr(1); pr(0); rep(s - 1)pr(s); pr(t); rep(n - 2 * s)pr(0);
			return 0;
		}
		if (t <= 2 * s) {
			rep(s - 1)pr(1); pr(0); rep(s)pr(s); pr(t - s); rep(n - 2 * s - 1)pr(0);
			return 0;
		}
	}
}