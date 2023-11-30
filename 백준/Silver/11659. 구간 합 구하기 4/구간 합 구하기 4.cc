#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[100001]{}, N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i], arr[i] += arr[i - 1];
	
	for (; M--;) {
		int L, R;
		cin >> L >> R;
		cout << arr[R] - arr[L - 1] << '\n';
	}

}