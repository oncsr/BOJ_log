#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int TC;
	for (cin >> TC; TC--;) {
		int N;
		deque<char> D;
		for (cin >> N; N--;) {
			char a;
			cin >> a;
			if (D.empty() || a <= D.front())	D.push_front(a);
			else	D.push_back(a);
		}
		for (char i : D)	cout << i;
		cout << '\n';
	}
}