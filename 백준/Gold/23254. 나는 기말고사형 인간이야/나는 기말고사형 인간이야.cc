#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, ans = 0, a[200000], b[200000];
	cin >> n >> m;
	priority_queue<ii, vector<ii>, less<> > Q;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 0; i < m; i++)	cin >> b[i];
	for (int i = 0; i < m; i++)	Q.push({ b[i],100 - a[i] });
	n *= 24;
	while (!Q.empty() && n > 0) {
		ii now = Q.top();
		Q.pop();
		int g = now.second / now.first;
		if (g > n) {
			ans += now.first * n;
			n = 0;
		}
		else {
			ans += now.first * g;
			n -= g;
			if (now.second % now.first) {
				Q.push({ now.second - now.first * g,now.second - now.first * g });
			}
		}
	}
	cout << ans;
}