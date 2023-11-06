#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll ans = 0;
	ll N, M, K;
	cin >> N >> M >> K;
	string arr[26]{};
	int idx[26][200001]{};
	int idx2[26][200001]{};
	int idx3[26][200001]{};
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		int last = 0;
		int last2 = -1;
		int last3 = 0;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'U') {
				idx[i][j] = last + 1;
				last = j + 1;
			}
			else	idx[i][j] = last + 1;

			if (arr[i][j] == 'U') {
				last2 = j;
				idx2[i][j] = last2 + 1;
			}
			else	idx2[i][j] = last2 + 1;

			if (arr[i][j] == 'U') {
				for (int k = last3; k <= j; k++)	idx3[i][k] = j + 1;
				last3 = j + 1;
			}
		}
	}
	string dungeon;
	cin >> dungeon;
	int s = M, e = M;
	for (int i = M - 1; i >= 1; i--) {
		s--;
		if (arr[dungeon.back() - 'A'][i - 1] == 'U') {
			s++;
			break;
		}
	}
	if (s < 1)	s = 1;
	ans += (ll)e - s + 1;
	for (int i = dungeon.size() - 2; i >= 0; i--) {

		int num = dungeon[i] - 'A';
		
		int e1 = idx2[num][e - 1];
		if (s > e1 || e < e1)	break;
		e = e1;
		
		int s1 = idx3[num][s - 1];
		if (!s1)	break;
		s = idx[num][s1 - 1];

		ans += (ll)e - s + 1;
	}

	cout << ans;

}