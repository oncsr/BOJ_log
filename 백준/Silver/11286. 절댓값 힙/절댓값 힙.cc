#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a;
	priority_queue<ii, vector<ii>, greater<> > PQ;
	for (cin >> N; N--;) {
		cin >> a;
		if (!a) {
			if (PQ.empty())	cout << 0 << '\n';
			else {
				cout << PQ.top().second << '\n';
				PQ.pop();
			}
			continue;
		}
		PQ.push({ abs(a), a });
	}
}