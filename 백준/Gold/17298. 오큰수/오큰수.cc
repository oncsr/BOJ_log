#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[1000000]{}, a;
	stack<pair<int, int> > S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		while (!S.empty() && a > S.top().first) {
			arr[S.top().second] = a;
			S.pop();
		}
		S.push({ a, i });
	}
	for (int i = 0; i < N; i++)	cout << (arr[i] ? arr[i] : -1) << ' ';
}