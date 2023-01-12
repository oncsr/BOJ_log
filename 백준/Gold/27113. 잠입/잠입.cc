#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	bool yes = true;
	int s = 1;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		int a[2]{};
		char b[2]{};
		for (int j = 0; j < t; j++)
			cin >> a[j] >> b[j];
		if (!yes)	continue;
		if (!t)	continue;
		if (t == 1) {
			if (b[0] == 'R') {
				int poss = a[0] - 1;
				if (s > poss)	yes = false;
			}
			else {
				int poss = a[0] + 1;
				if (poss > m)	yes = false;
				else	s = max(poss, s);
			}
		}
		else {
			if (b[0] == 'L' && b[1] == 'L') {
				int poss = a[1] + 1;
				if (poss > m)	yes = false;
				else	s = max(poss, s);
			}
			else if (b[0] == 'L') {
				int poss = a[0] + 1;
				if (a[0] + 1 == a[1])	yes = false;
				else if (s > a[1] - 1)	yes = false;
				else	s = max(poss, s);
			}
			else if (b[1] == 'L') {
				int poss = a[0] - 1;
				if (s > poss) {
					int poss2 = a[1] + 1;
					if (poss2 > m)	yes = false;
					else	s = max(poss2, s);
				}
			}
			else {
				int poss = a[0] - 1;
				if (s > poss)	yes = false;
			}
		}
	}
	cout << (yes && s <= m ? "YES" : "NO");
}