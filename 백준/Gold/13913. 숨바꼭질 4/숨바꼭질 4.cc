#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K, t, n, x;
	bool find = false;
	int visit[100001]{};
	string s;
	queue<pair<pair<int, int>, string>>Q;
	cin >> N >> K;
	if (N > K) {
		cout << N - K << '\n';
		for (; N >= K; N--)	cout << N << ' ';
	}
	else {
		visit[N]++;
		Q.push({ {N,0},"" });
		while (!Q.empty()) {
			n = Q.front().first.first;
			t = Q.front().first.second;
			s = Q.front().second;
			Q.pop();
			if (n == K)	break;
			x = n - 1;
			if (x >= 0 && !visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + '1' });
			}
			x = n + 1;
			if (x <= 100000 && !visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + '2' });
			}
			x = n * 2;
			if (x <= 100000 && !visit[x]) {
				visit[x]++;
				Q.push({ {x,t + 1},s + '3' });
			}
		}
		cout << t << '\n';
		cout << N << ' ';
		for (char i : s) {
			if (i == '1')	N--;
			else if (i == '2')	N++;
			else	N *= 2;
			cout << N << ' ';
		}
	}
}