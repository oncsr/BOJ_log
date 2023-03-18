#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a;
	cin >> N >> M;
	deque<int> DQ;
	for (int i = 1; i <= N; i++)	DQ.push_back(i);
	int s = 0;
	for (; M--;) {
		cin >> a;
		deque<int> left = DQ;
		deque<int> right = DQ;
		int le = 0, ri = 0;
		
		while (left.front() != a) {
			le++;
			left.push_back(left.front());
			left.pop_front();
		}
		while (right.front() != a) {
			ri++;
			right.push_front(right.back());
			right.pop_back();
		}
		if (le > ri) {
			DQ = right;
			s += ri;
		}
		else {
			DQ = left;
			s += le;
		}
		DQ.pop_front();
	}
	cout << s;
}