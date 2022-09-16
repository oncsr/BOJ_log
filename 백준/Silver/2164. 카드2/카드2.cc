#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		Q.push(i);

	while (Q.size() != 1) {
		Q.pop();
		int a = Q.front();
		Q.pop();
		Q.push(a);
	}
	cout << Q.front() << '\n';
}