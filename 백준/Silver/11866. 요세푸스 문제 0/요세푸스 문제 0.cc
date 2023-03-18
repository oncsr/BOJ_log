#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	queue<int> Q;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)	Q.push(i);
	cout << '<';
	while (Q.size() > 1) {
		for (int i = 0; i < K - 1; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << Q.front() << '>';
}