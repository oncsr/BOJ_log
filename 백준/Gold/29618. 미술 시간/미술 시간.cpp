#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q, r[100001]{}, s[100001]{};
	cin >> N >> Q;
	iota(r, r + N + 2, 0);

	function<int(int)> f = [&](int x) -> int {return x == r[x] ? x : r[x] = f(r[x]); };

	for (int a, b, x; Q--;) {
		cin >> a >> b >> x;
		b++;
		while (f(a) != f(b)) {
			a = f(a);
			s[a] = x;
			r[a] = f(r[a + 1]);
		}
	}

	for (int i = 1; i <= N; i++) cout << s[i] << ' ';

}