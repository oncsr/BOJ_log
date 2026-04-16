#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int arr[2001]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];

	sort(arr, arr + N);

	int ans = 0;
	for (int k = 0; k < N; k++) {
		int s = 0, e = N - 1;
		while (s < e) {
			if (arr[s] + arr[e] == arr[k]) {
				if (s != k && e != k) {
					ans++;
					break;
				}
				else {
					if (s == k)	s++;
					else if (e == k)	e--;
				}
			}
			else if (arr[s] + arr[e] > arr[k]) {
				e--;
			}
			else {
				s++;
			}
		}
	}
	cout << ans;

}