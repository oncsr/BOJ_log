#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q, _;
	cin >> N >> Q;
	for (int i = 1; i < N; i++)	cin >> _;
	set<int> P;
	for (; Q--;) {
		int a, b;
		cin >> a >> b;
		if (a == 1)	P.insert(b);
		else {
			int res = -1;
			if (!P.empty()) {
				auto r = P.lower_bound(b);
				if (r != P.end())	res = abs(b - *r);
				if (r != P.begin()) {
					r--;
					int v = abs(b - *r);
					res = res == -1 ? v : min(res, v);
				}
			}
			cout << res << '\n';
		}
	}

}