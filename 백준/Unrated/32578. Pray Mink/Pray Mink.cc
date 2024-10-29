#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(int x) {
	if (x == 1)	return false;
	for (int j = 2; j * j <= x; j++)	if (x % j == 0)	return false;
	return true;
}

int ans = 0;

void bck(int now, int res) {
	ans = max(ans, res);
	if (now < 10)	return;
	string n = to_string(now);
	for (int i = 0; i < n.size(); i++) {
		int x = stoi(n.substr(0, i) + n.substr(i + 1, n.size() - i - 1));
		if (is_prime(x))	bck(x, res + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	if(is_prime(N))	bck(N, 1);
	cout << ans;

}