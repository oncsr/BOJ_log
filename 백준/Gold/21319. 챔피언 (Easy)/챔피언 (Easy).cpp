#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[200001]{};
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int c = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == arr[i - 1])	continue;
		int j = i, S = arr[i] + i - 1;
		while (j < N) {
			int pos = lower_bound(arr, arr + N + 1, S) - arr - 1;
			S += pos - j;
			if (j == pos)	break;
			j = pos;
		}
		if (j != N)	continue;
		c++;
		cout << i << ' ';
	}
	if (!c)	cout << -1;

}