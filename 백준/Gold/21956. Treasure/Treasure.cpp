#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	string a, ans = "", chk[26]{};
	cin >> N >> K >> a;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < K; j++)	chk[i] += ('a' + i);
	}
	for (char i : a) {
		ans += i;
		if (ans.size() < K)	continue;
		if (ans.substr(ans.size() - K, K) == chk[ans.back() - 'a']) {
			for (int j = 0; j < K; j++)	ans.pop_back();
		}
	}
	cout << ans;
}