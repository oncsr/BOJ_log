#include <iostream>
using namespace std;
using ii = pair<int, int>;

struct node {
	int waiting, going, remain;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int B, P;
	for (cin >> B >> P; B != 0 && P != 0; cin >> B >> P) {
		B = abs(B);
		ii bridge[20]{};
		for (int i = 0; i < B; i++)	cin >> bridge[i].first >> bridge[i].second;
		node S[21]{};
		S[0].waiting = P;
		S[0].going = min(S[0].waiting, bridge[0].first);
		S[0].waiting -= min(S[0].waiting, bridge[0].first);
		S[0].remain = bridge[0].second;
		int t = 0;
		while (S[B].waiting < P) {
			for (int i = 0; i < B; i++) {
				if (S[i].going == 0) {
					// 건너는 사람이 없으면 새로 보낼 사람이 있는 지 확인
					if (S[i].waiting) {
						S[i].going = min(S[i].waiting, bridge[i].first);
						S[i].waiting -= min(S[i].waiting, bridge[i].first);
						S[i].remain = bridge[i].second;
					}
				}
				else {
					S[i].remain--;
					if (S[i].remain == 0) {
						S[i + 1].waiting += S[i].going;
						S[i].going = 0;
						if (S[i].waiting) {
							S[i].going = min(S[i].waiting, bridge[i].first);
							S[i].waiting -= min(S[i].waiting, bridge[i].first);
							S[i].remain = bridge[i].second;
						}
					}
				}
			}
			t++;
		}
		cout << t << '\n';
	}
}