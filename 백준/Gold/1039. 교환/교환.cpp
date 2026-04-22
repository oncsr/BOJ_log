#include <iostream>
#include <queue>
using namespace std;

int toint(string a) {
	int s = 0, g = 1;
	for (int i = a.size() - 1; i >= 0; i--) {
		s += g * (a[i] - '0');
		g *= 10;
	}
	return s;
}

int main() {
	string N, mx = "";
	int K, poss = 0;
	cin >> N >> K;
	int len = N.size();
	if (len == 1) {
		cout << -1;
		return 0;
	}
	if (len == 2 && N[1] == '0') {
		cout << -1;
		return 0;
	}
	queue<pair<string, int> > Q;
	Q.push({ N, 0 });
	int visit[1000001][2]{};
	while (!Q.empty()) {
		string now = Q.front().first;
		int dep = Q.front().second;
		Q.pop();
		if ((K - dep) % 2 == 0) {
			mx = max(mx, now);
		}
		if (dep == K) {
			mx = max(mx, now);
			continue;
		}
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (i == 0 && now[j] == '0')	continue;
				string temp = now;
				swap(temp[i], temp[j]);
				int next = toint(temp);
				if (!visit[next][(K - (dep + 1)) % 2]) {
					visit[next][(K - (dep + 1)) % 2]++;
					Q.push({ temp, dep + 1 });
				}
			}
		}
	}
	cout << mx;
}