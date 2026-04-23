#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, o;
	char a;
	stack<pair<char, int> > S;	// for delete
	deque<char> D;
	for (cin >> N; N--;) {
		cin >> o;
		if (o == 3) {
			if (!S.empty()) {
				pair<char, int> del = S.top();
				S.pop();
				if (del.second == 1)	D.pop_back();
				else	D.pop_front();
			}
		}
		else {
			cin >> a;
			if (o == 1)	D.push_back(a);
			else	D.push_front(a);
			S.push({ a,o });
		}
	}
	if (D.empty())	cout << 0;
	else {
		while (!D.empty()) {
			cout << D.front();
			D.pop_front();
		}
	}
}