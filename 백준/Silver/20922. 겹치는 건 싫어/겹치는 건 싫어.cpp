#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	vector<queue<int> > pos(100001);
	int count[100001]{};
	int s = 0, st = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		count[a]++;
		pos[a].push(i + 1);
		if (count[a] > K) {
			st = max(st, pos[a].front());
			pos[a].pop();
			count[a]--;
		}
		s = max(s, i - st + 1);
	}
	cout << s;
}