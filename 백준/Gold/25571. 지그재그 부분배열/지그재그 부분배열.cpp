#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		int arr[100001]{};
		cin >> N >> arr[1];
		ll ans = 0, cnt = 0;
		int status = -1;
		for (int i = 2; i <= N; i++) {
			cin >> arr[i];
			
			if (status == -1) {
				if (arr[i] > arr[i - 1])	status = 2, cnt++;
				else if (arr[i] < arr[i - 1])	status = 1, cnt++;
				else	status = 0, cnt = 0;
				
			}
			else if (status == 0) {
				if (arr[i] > arr[i - 1])	status = 2, cnt++;
				else if (arr[i] < arr[i - 1])	status = 1, cnt++;
				else	status = 0, cnt = 0;
			}
			else if (status == 1) {
				if (arr[i] > arr[i - 1])	status = 2, cnt++;
				else if (arr[i] < arr[i - 1])	status = 1, cnt = 1;
				else	status = 0, cnt = 0;
			}
			else {
				if (arr[i] > arr[i - 1])	status = 2, cnt = 1;
				else if (arr[i] < arr[i - 1])	status = 1, cnt++;
				else	status = 0, cnt = 0;
			}
			ans += cnt;

		}
		cout << ans << '\n';
	}
}