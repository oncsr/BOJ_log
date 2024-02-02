#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> Q;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Q.push(a);
	}
	k = n - k;
	for (int i = 0; i < k; i++)
		Q.pop();
	cout << Q.top() << '\n';
}