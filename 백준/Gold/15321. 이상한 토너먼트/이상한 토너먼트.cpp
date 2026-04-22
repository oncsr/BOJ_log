#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N, a, ans = 0;
	stack<int> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (S.empty())	S.push(a);
		else {
			if (a < S.top())	S.push(a);
			else {
				while (!S.empty() && a > S.top()) {
					int now = S.top();
					S.pop();
					if (S.empty()) {
						ans += a - now, S.push(a);
						break;
					}
					else {
						int before = S.top();
						if (a > before)
							ans += before - now;
						else {
							ans += a - now;
							S.push(a);
							break;
						}
					}
				}
			}
		}
	}
	while (!S.empty()) {
		int now = S.top();
		S.pop();
		if (S.empty())	break;
		int before = S.top();
		ans += before - now;
	}
	cout << ans;
}