#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	bool isStack[100000]{};
	for (int i = 0; i < N; i++)	cin >> isStack[i];
	deque<int> D;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (!isStack[i])	D.push_back(a);
	}
	int M;
	for (cin >> M; M--;) {
		int a;
		cin >> a;
		D.push_front(a);
		cout << D.back() << ' ';
		D.pop_back();
	}
}