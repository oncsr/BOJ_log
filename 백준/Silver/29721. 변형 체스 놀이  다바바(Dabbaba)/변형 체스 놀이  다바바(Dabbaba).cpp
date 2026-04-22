#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	int dx[4] = { 2,0,-2,0 }, dy[4] = { 0,2,0,-2 };
	set<pair<int, int>> S;
	set<pair<int, int>> S2;
	int x[100000]{}, y[100000]{};
	for (int i = 0; i < K; i++) {
		cin >> x[i] >> y[i];
		S.insert({ x[i],y[i] });
	}
	for (int i = 0; i < K; i++) {
		for (int d = 0; d < 4; d++) {
			int xx = x[i] + dx[d];
			int yy = y[i] + dy[d];
			if (xx >= 1 && xx <= N && yy >= 1 && yy <= N) {
				if (!S.count({ xx,yy }))	S2.insert({ xx,yy });
			}
		}
	}
	cout << S2.size();

}