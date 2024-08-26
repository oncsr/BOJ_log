#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, V, arr[200001]{};
	cin >> N >> M >> V;
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int g = N - V + 1;
	for (; M--;) {
		int a;
		cin >> a;
		if (a < N)	cout << arr[a + 1] << '\n';
		else {
			a -= N;
			a %= g;
			cout << arr[V + a] << '\n';
		}
	}

}