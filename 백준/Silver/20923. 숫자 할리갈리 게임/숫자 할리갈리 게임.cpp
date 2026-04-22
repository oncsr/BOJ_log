#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	deque<int> dodo;
	deque<int> suy;
	int a, b;
	deque<int> grdo;
	deque<int> grsu;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		dodo.push_back(a);
		suy.push_back(b);
	}
	bool order = 0;
	int n1, n2;
	while (M--) {
		if (!order) {
			if (dodo.empty())	break;
			n1 = dodo.back();
			dodo.pop_back();
			if (dodo.empty())	break;
			grdo.push_back(n1);
			n2 = 0;
			if (!grsu.empty())	n2 = grsu.back();
		}
		else {
			if (suy.empty())	break;
			n1 = suy.back();
			suy.pop_back();
			if (suy.empty())	break;
			grsu.push_back(n1);
			n2 = 0;
			if (!grdo.empty())	n2 = grdo.back();
		}

		if (n1 == 5 || n2 == 5) {
			while (!grsu.empty()) {
				dodo.push_front(grsu.front());
				grsu.pop_front();
			}
			while (!grdo.empty()) {
				dodo.push_front(grdo.front());
				grdo.pop_front();
			}
		}
		else if (n1 + n2 == 5 && n1 > 0 && n2 > 0) {
			while (!grdo.empty()) {
				suy.push_front(grdo.front());
				grdo.pop_front();
			}
			while (!grsu.empty()) {
				suy.push_front(grsu.front());
				grsu.pop_front();
			}
		}
		order ^= 1;
	}
	if (suy.size() > dodo.size())	cout << "su";
	else if (suy.size() < dodo.size())	cout << "do";
	else	cout << "dosu";
}