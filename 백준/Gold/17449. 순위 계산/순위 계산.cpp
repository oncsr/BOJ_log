#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int R, N;
	cin >> R >> N;
	int arr[200001]{};
	for (int i = 1; i <= N; i++)	cin >> arr[i];

	int mx = R, mn = R, cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] <= mn)	mn++;

		if (arr[i] < mx)	mx++;
		else if (arr[i] == mx)	cnt++;
		else {
			if (mx < arr[i] && arr[i] <= mx + cnt) {
				cnt -= arr[i] - mx - 1;
				mx = arr[i];
			}
		}
	}
	cout << mx << ' ' << mn;

}