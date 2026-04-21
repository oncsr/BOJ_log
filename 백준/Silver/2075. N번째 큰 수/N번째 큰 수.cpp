#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	
	priority_queue<int, vector<int>, greater<>> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			Q.push(a);
		}
		while (Q.size() > N)	Q.pop();
	}
	cout << Q.top();

}