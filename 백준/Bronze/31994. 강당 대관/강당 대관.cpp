#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	priority_queue<pair<int, string>> Q;
	for (int i = 7; i--;) {
		string a;
		int b;
		cin >> a >> b;
		Q.emplace(b, a);
	}
	cout << Q.top().second;

}