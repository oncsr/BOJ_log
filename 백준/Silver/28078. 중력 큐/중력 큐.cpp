#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	deque<int> D;
	int Q, w = 0;
	string dir[4] = { "right", "up","left","down" };
	int pos = 0;
	for (cin >> Q; Q--;) {
		string a;
		cin >> a;
		if (a == "pop") {
			if (D.empty())	continue;
			int t = D.front();
			D.pop_front();
			if (t == 1)	continue;
			w--;
			if (pos == 3) {
				while (!D.empty() && D.front() != 2)	D.pop_front();
			}
		}
		else {
			char b;
			cin >> b;
			if (a == "push") {
				if (b == 'w')	D.push_back(2), w++;
				else {
					if (pos != 1 && (pos != 3 || w))	D.push_back(1);
				}
			}
			if (a == "rotate") {
				if (b == 'l')	pos = (pos + 1) % 4;
				else	pos = (pos + 3) % 4;
				if (pos == 1) {
					while (!D.empty() && D.back() != 2)	D.pop_back();
				}
				if (pos == 3) {
					while (!D.empty() && D.front() != 2)	D.pop_front();
				}
			}
			if (a == "count") {
				if (b == 'w')	cout << w << '\n';
				else	cout << D.size() - w << '\n';
			}
		}
	}
}