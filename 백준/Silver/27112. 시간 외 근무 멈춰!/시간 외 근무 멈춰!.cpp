#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, p = 1, time = 1, suc = 1;
	pair<int, int> s[100000]{};
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i].first >> s[i].second;
	sort(s, s + n);
	for (int i = 0; i < n; i++) {
		while (s[i].second && time <= s[i].first) {
			if (!(time % 7 == 6 || time % 7 == 0))
				s[i].second--;
			time++;
		}
		if (s[i].second) {
			if (s[i].first - p + 1 < s[i].second) {
				cout << -1;
				suc = 0;
				break;
			}
			p += s[i].second;
		}
	}
	if (suc)	cout << p - 1;
}