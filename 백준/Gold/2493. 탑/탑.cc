#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	stack<pair<int, int> > S;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (S.empty()) {
			S.push({ a,i });
			cout << "0 ";
		}
		else if (a < S.top().first) {
			cout << S.top().second << ' ';
			S.push({ a,i });
		}
		else {
			while (!S.empty()) {
				if (a < S.top().first)	break;
				S.pop();
			}
			if (S.empty()) {
				cout << "0 ";
			}
			else
				cout << S.top().second << ' ';
			S.push({ a,i });
		}
	}
	cout << '\n';
}