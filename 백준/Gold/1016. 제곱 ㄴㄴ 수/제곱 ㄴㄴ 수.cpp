#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll A, B;
	cin >> A >> B;

	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++)	if (!e[i])	for (int j = i * i; j <= 1000000; j += i)	e[j] = 1;

	int ans = B - A + 1;
	int visit[1000001]{};
	for (ll i = 2; i <= 1000000; i++) {
		if (!e[i]) {
			ll k;
			if (A % (i * i) == 0)	k = A / (i * i) * (i * i);
			else	k = (A / (i * i) + 1) * (i * i);
			while (k <= B) {
				if (!visit[k - A])	ans--, visit[k - A]++;
				k += i * i;
			}
		}
	}
	cout << ans;

}