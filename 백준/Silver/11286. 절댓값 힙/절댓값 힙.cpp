#include <iostream>
#include <queue>
using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		return abs(a) == abs(b) ? a > b:abs(a) > abs(b);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a;
	priority_queue<int, vector<int>, cmp>Q;
	for (cin >> N; N--;) {
		cin >> a;
		if (a)	Q.push(a);
		else if (Q.empty())	cout << "0\n";
		else	cout << Q.top() << '\n', Q.pop();
	}
}