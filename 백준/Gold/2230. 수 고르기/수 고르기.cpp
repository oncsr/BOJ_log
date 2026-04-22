#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, arr[100000]{}, ans = 2000000001;
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	int s = 0, e = 0;
	while (s < N) {
		if (abs(arr[e] - arr[s]) >= M) {
			ans = min(ans, abs(arr[e] - arr[s]));
			if (s == e)	e++;
			else	s++;
		}
		else {
			if (e == N - 1)	s++;
			else	e++;
		}
	}
	cout << ans;
}