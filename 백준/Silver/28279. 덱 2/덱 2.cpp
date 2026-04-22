#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	deque<int> D;
	for (cin >> N; N--;) {
		int o, x;
		cin >> o;
		if (o < 3) {
			cin >> x;
			o == 1 ? D.push_front(x) : D.push_back(x);
			continue;
		}
		if (o < 5) {
			if (D.empty())	cout << "-1\n";
			else if (o == 3)	cout << D.front() << '\n', D.pop_front();
			else	cout << D.back() << '\n', D.pop_back();
			continue;
		}
		if (o < 7) {
			cout << (o == 5 ? D.size() : (int)D.empty()) << '\n';
			continue;
		}
		cout << (D.empty() ? -1 : (o == 7 ? D.front() : D.back())) << '\n';
	}
}