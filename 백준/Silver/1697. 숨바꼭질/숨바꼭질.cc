#include <iostream>
#include <queue>

using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	int visit[100001] = { 0 };
	queue<pair<int, int> > Q;
	Q.push({ N,0 });
	visit[N]++;
	int time = 0;
	while (!Q.empty()) {
		int c = Q.front().first;
		time = Q.front().second;
		Q.pop();
		if (c == K)
			break;
		int xx = c + 1;
		int zz = c - 1;
		int yy = 2 * c;
		if (xx <= 100000 && xx >= 0 && visit[xx] == 0) {
			Q.push({ xx,time + 1 });
			visit[xx]++;
		}
		if (zz <= 100000 && zz >= 0 && visit[zz] == 0) {
			Q.push({ zz,time + 1 });
			visit[zz]++;
		}
		if (yy <= 100000 && yy >= 0 && visit[yy] == 0) {
			Q.push({ yy,time + 1 });
			visit[yy]++;
		}
	}
	cout << time << '\n';
}