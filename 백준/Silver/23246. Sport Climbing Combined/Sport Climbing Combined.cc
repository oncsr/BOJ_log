#include <iostream>
#include <queue>
using namespace std;
using iii = pair<int, pair<int, int> >;

int main() {
	int N, a, b, c, d;
	priority_queue<iii, vector<iii>, greater<> > Q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		Q.push({ b * c * d,{b + c + d,a} });
	}
	for (int i = 0; i < 3; i++) {
		cout << Q.top().second.second << ' ';
		Q.pop();
	}
}