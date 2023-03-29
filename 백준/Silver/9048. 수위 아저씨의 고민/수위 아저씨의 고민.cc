#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int F, R, N;
		cin >> F >> R >> N;
		vector<vector<int> > office(31);
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			office[a].push_back(b);
		}
		for (int i = 1; i <= F; i++)	sort(office[i].begin(), office[i].end());
		int s = 2 * F + R + 1;
		for (int i = 1; i <= F; i++) {
			if (!office[i].size())	continue;
			if (office[i].size() == 1) {
				s += min(R - office[i][0] + 1, office[i][0]) * 2;
				continue;
			}
			int v = min(office[i].back(), R - office[i][0] + 1);
			for (int t = 0; t < office[i].size() - 1; t++)
				v = min(v, office[i][t] + R - office[i][t + 1] + 1);
			s += v * 2;
		}
		cout << s << '\n';
	}
}