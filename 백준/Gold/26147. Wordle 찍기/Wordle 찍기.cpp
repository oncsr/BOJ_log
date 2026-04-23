#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string a, ans = "HYEOK", wrong = "ZXCVB";
	char b[100000][6]{};
	bool poss = 1;
	cin >> n;
	for (int j = 0; j < n; j++) {
		int g = 0, y = 0;
		cin >> a;
		vector<int> fix;
		vector<int> none;
		for (int i = 0; i < 5; i++) {
			if (a[i] == 'G') {
				g++;
				b[j][i] = ans[i];
			}
			if (a[i] == 'Y') {
				y++;
				fix.push_back(i);
			}
			if (a[i] == 'B') {
				b[j][i] = wrong[i];
				none.push_back(i);
			}
		}
		if (g == 4 && y == 1)	poss = 0;
		else if (y == 1) {
			b[j][fix[0]] = ans[none[0]];
		}
		else {
			for (int i = 0; i < fix.size(); i++) {
				b[j][fix[i]] = ans[fix[(i + 1) % fix.size()]];
			}
		}
	}
	if (poss) {
		cout << ans << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++)	cout << b[i][j];
			cout << '\n';
		}
	}
	else	cout << "IMPOSSIBLE";
}