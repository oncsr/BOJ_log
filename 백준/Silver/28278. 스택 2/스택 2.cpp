#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	stack<int> S;
	for (cin >> N; N--;) {
		int o;
		cin >> o;
		switch (o) {
		case 1:
			int x;
			cin >> x;
			S.push(x);
			break;
		case 2:
			if (S.empty())	cout << "-1\n";
			else	cout << S.top() << '\n', S.pop();
			break;
		case 3:
			cout << S.size() << '\n';
			break;
		case 4:
			cout << (int)S.empty() << '\n';
			break;
		case 5:
			cout << (S.empty() ? -1 : S.top()) << '\n';
		}
	}
}