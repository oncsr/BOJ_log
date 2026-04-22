#include <iostream>
#include <queue>
using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	ll arr[100]{};
	priority_queue<ll, vector<ll>, greater<> > Q;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		Q.push(arr[i]);
	}
	for (int i = 1; i < K; i++) {
		ll G = Q.top();
		Q.pop();
		int j = N - 1;
		while (j >= 0) {
			if (G % arr[j] == 0)	break;
			j--;
		}
		j = max(0, j);
		for (; j < N; j++) {
			if (G * arr[j] > 2147483647)	break;
			Q.push(G * arr[j]);
		}
	}
	cout << Q.top();
}