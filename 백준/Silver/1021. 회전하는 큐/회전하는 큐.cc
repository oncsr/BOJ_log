#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M, a, s = 0;
	cin >> N >> M;
	deque<int> D;
	for (int i = 1; i <= N; i++)	D.push_back(i);
	for (; M--;) {
		deque<int> D1;
		deque<int> D2;
		D1 = D2 = D;
		int t1 = 0, t2 = 0;
		cin >> a;
		while (D1.front() != a) {
			D1.push_back(D1.front());
			D1.pop_front();
			t1++;
		}
		D1.pop_front();
		while (D2.front() != a) {
			D2.push_front(D2.back());
			D2.pop_back();
			t2++;
		}
		D2.pop_front();
		if (t1 < t2) {
			s += t1;
			D = D1;
		}
		else {
			s += t2;
			D = D2;
		}
	}
	cout << s;
}