#include <iostream>
#include <stack>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	stack<ii> S;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (S.empty()) {
			S.push({ a,i });
			cout << 0 << ' ';
			continue;
		}
		if (a > S.top().first) {
			while (!S.empty() && a > S.top().first)	S.pop();
			cout << (S.empty() ? 0 : S.top().second) << ' ';
			S.push({ a,i });
			continue;
		}
		cout << S.top().second << ' ';
		S.push({ a,i });
	}
}