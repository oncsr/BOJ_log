#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	int arr[200000]{};
	for (int i = 0; i < N; i++)	cin >> arr[i];
	int s = 0, e = N - M - 1;
	int mx = arr[e] - arr[s];
	for (; e < N; e++) {
		if (arr[e - N + M + 1] < arr[s])	s = e - N + M + 1;
		mx = max(mx, arr[e] - arr[s]);
	}
	cout << mx;
}