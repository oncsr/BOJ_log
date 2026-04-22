#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;
	int arr[20003]{}, ro = 0, cnt[20002]{};
	ll sum = 0;
	arr[0] = 1;
	int G = N + M - 1, m = max(N, M) - 1;
	vector<int> pos;
	pos.push_back(0);
	while (m) {
		if (G < 0)	break;
		if (!ro) {
			int now = G;
			if (!arr[now]) {
				arr[now]++;
				m--;
				pos.push_back(now);
			}
			if (!cnt[G]) {
				cnt[G]++;
				sum += (ll)G;
			}
			G--;
			
			for (int i : pos) {
				if (i == now)	continue;
				if (!cnt[abs(i - now)]) {
					cnt[abs(i - now)]++;
					sum += abs((ll)i - now);
					if (abs(i - now) == G)	G--;
				}
			}
		}
		else {
			int now = N + M - 1 - G;
			if (!arr[now]) {
				arr[now]++;
				m--;
				pos.push_back(now);
			}
			if (!cnt[G]) {
				cnt[G]++;
				sum += (ll)G;
			}
			G--;
			for (int i : pos) {
				if (i == now)	continue;
				if (!cnt[abs(i - now)]) {
					cnt[abs(i - now)]++;
					sum += abs((ll)i - now);
					if (abs(i - now) == G)	G--;
				}
			}
		}
		ro ^= 1;
	}
	int id = 0;
	while (m) {
		if (!arr[id])	arr[id]++, m--;
		id++;
	}
	vector<int> pos2;
	for (int i = 0; i < N + M; i++)
		if (!arr[i]) 
			pos2.push_back(i);

	for (int i = 0; i < pos2.size(); i++) {
		for (int j = i + 1; j < pos2.size(); j++) {
			if (!cnt[abs(pos2[i] - pos2[j])]) {
				cnt[abs(pos2[i] - pos2[j])]++;
				sum += abs((ll)pos2[i] - pos2[j]);
			}
		}
	}
	char x = (N > M ? 'a' : 'b');
	char y = (x == 'a' ? 'b' : 'a');
	cout << sum << '\n';
	for (int i = 0; i < N + M; i++)
		cout << (arr[i] ? x : y);
}