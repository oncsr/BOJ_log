#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	int s = 0, gaji = 0;
	priority_queue<int, vector<int>, less<> > Q;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		s += a;
		Q.push(a);
		while (!Q.empty() && s >= M) {
			s -= Q.top() * 2;
			Q.pop();
			gaji++;
		}
	}
	cout << gaji;
}