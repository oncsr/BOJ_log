#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int visit[100001]{}, D[100001]{}, T[100001]{};
	queue<pair<int, int> > Q;
	visit[N]++;
	D[N] = 1, T[N] = 0;
	Q.push({ N,0 });
	int ans = -1;
	while (!Q.empty()) {
		int now = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		if (now == K) {
			if (ans == -1)	ans = time;
			else if (time > ans)	break;
		}
		if (now - 1 >= 0) {
			if (visit[now - 1] && T[now - 1] == time + 1) {
				D[now - 1] += D[now];
			}
			if (!visit[now - 1]) {
				T[now - 1] = time + 1;
				D[now - 1] = D[now];
				Q.push({ now - 1,time + 1 });
				visit[now - 1]++;
			}
		}
		if (now + 1 <= 100000) {
			if (visit[now + 1] && T[now + 1] == time + 1) {
				D[now + 1] += D[now];
			}
			if (!visit[now + 1]) {
				T[now + 1] = time + 1;
				D[now + 1] = D[now];
				Q.push({ now + 1,time + 1 });
				visit[now + 1]++;
			}
		}
		if (now * 2 <= 100000) {
			if (visit[now * 2] && T[now * 2] == time + 1) {
				D[now * 2] += D[now];
			}
			if (!visit[now * 2]) {
				T[now * 2] = time + 1;
				D[now * 2] = D[now];
				Q.push({ now * 2,time + 1 });
				visit[now * 2]++;
			}
		}
	}
	cout << ans << ' ';
	if (ans != -1)	cout << D[K];
}