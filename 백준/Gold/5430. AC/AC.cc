#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		string P;
		int N, a;
		cin >> P >> N;
		bool rv = 0;
		char trash;
		deque<int> DQ;
		for (int i = 0; i < N; i++) {
			cin >> trash >> a;
			DQ.push_back(a);
		}
		cin >> trash;
		if (!N)	cin >> trash;

		bool error = 0;

		for (char i : P) {
			if (i == 'R') {
				rv ^= 1;
				continue;
			}
			if (DQ.empty()) {
				error = 1;
				cout << "error\n";
				break;
			}
			if (rv)	DQ.pop_back();
			else	DQ.pop_front();
			
		}
		if (error)	continue;
		cout << '[';
		while (DQ.size() > 1) {
			if (rv) {
				cout << DQ.back() << ',';
				DQ.pop_back();
			}
			else {
				cout << DQ.front() << ',';
				DQ.pop_front();
			}
		}
		if (DQ.empty())	cout << "]\n";
		else {
			cout << DQ.front() << "]\n";
		}
	}
}