#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string man[9][9]{};
	vector<string> mid;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> man[i][j];
			if (i % 3 == 1 && j % 3 == 1) {
				if (i == 4 && j == 4)	continue;
				mid.push_back(man[i][j]);
			}
		}
	}
	sort(mid.begin(), mid.end());
	for (int i = 1; i < 9; i++) {
		cout << '#' << i << ". " << mid[i - 1] << '\n';
		vector<string> low;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if (man[x * 3 + 1][y * 3 + 1] == mid[i - 1]) {
					for (int j = 0; j < 3; j++) {
						for (int k = 0; k < 3; k++) {
							if (j == 1 && k == 1)	continue;
							low.push_back(man[x * 3 + j][y * 3 + k]);
						}
					}
					sort(low.begin(), low.end());
				}
			}
		}
		for (int j = 1; j < 9; j++) {
			cout << '#' << i << '-' << j << ". " << low[j - 1] << '\n';
		}
	}
}