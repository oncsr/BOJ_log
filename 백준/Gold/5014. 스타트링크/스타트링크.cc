#include <iostream>
#include <queue>
using namespace std;

int main() {
	int f, s, g, u, d, time, now, next;
	cin >> f >> s >> g >> u >> d;
	queue<pair<int, int> > Q;
	vector<int> visit(f + 1);
	Q.push({ s,0 });
	visit[s]++;
	bool find = false;
	while (!Q.empty()) {
		now = Q.front().first;
		time = Q.front().second;
		Q.pop();
		if (now == g) {
			find = true;
			break;
		}
		next = now + u;
		if (next <= f && !visit[next]) {
			visit[next]++;
			Q.push({ next,time + 1 });
		}
		next = now - d;
		if (next > 0 && !visit[next]) {
			visit[next]++;
			Q.push({ next,time + 1 });
		}
	}
	if (find)	cout << time;
	else	cout << "use the stairs";
}