#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a;
	ll ans = 0;
	cin >> N;
	stack<int> S;
	for (int i = 0; i < N; i++) {
		cin >> a;
		int same = 0, temp = -1;
		while (!S.empty() && a > S.top()) {
			if (temp == S.top())	same++;
			else	same = 0;
			temp = S.top();
			S.pop();
			if (S.empty())	ans += (1LL + same);
			else	ans += (2LL + same);
		}
		if (same && S.empty())	ans -= (ll)same;
		S.push(a);
	}
	int same = 0, temp = -1;
	while (S.size() > 1) {
		if (temp == S.top())	same++;
		else {
			if (same)	ans += (ll)same * ((ll)same + 1) / 2;
			same = 0;
		}
		temp = S.top();
		S.pop();
		ans++;
	}
	ans += (ll)same * ((ll)same + 1) / 2;

	cout << ans;
}