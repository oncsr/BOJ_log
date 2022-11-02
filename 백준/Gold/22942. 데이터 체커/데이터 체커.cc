#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b;
	cin >> N;
	pair<int, int> circle[200000]{};
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		circle[i] = { a - b,a + b };
	}
	sort(circle, circle + N);

	bool success = 1;
	stack<pair<int, int>> S;
	S.push(circle[0]);
	for (int i = 1; i < N; i++) {
		pair<int, int> now = circle[i];
		if (now.second < S.top().second)
			S.push(now);
		else if (now.first > S.top().second) {
			while (!S.empty() && now.first > S.top().second)
				S.pop();
			if (S.empty() || now.second < S.top().second)
				S.push(now);
			else {
				success = 0;
				break;
			}
		}
		else {
			success = 0;
			break;
		}
	}

	cout << (success ? "YES" : "NO");
}