#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	queue<int> A, B;
	int sa = 0, sb = 0;
	int Q;
	for (cin >> Q; Q--;) {
		int o, x;
		cin >> o;
		if (o == 1) {
			cin >> x;
			if (A.size() != B.size()) {
				A.push(B.front()), sa += B.front(), sb -= B.front();
				B.pop();
			}
			B.push(x), sb += x;
		}
		else {
			cout << min(sa, sb) << '\n';
			if (sa > sb) swap(A, B), swap(sa, sb);
			A = queue<int>();
			sa = 0;
			while (B.size() - A.size() > 1) {
				A.push(B.front()), sa += B.front(), sb -= B.front();
				B.pop();
			}
		}
	}
	while (!A.empty()) cout << A.front() << ' ', A.pop();
	while (!B.empty()) cout << B.front() << ' ', B.pop();

}