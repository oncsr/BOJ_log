#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[3000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);

	int mx = (arr[1] - arr[0]) >> 1, ans = arr[0] + mx;
	if (ans == arr[0] || ans == arr[1])	ans = -1;
	for (int i = 2; i < N; i++) {
		if (((arr[i] - arr[i - 1]) >> 1) > mx && (arr[i]-arr[i-1] > 1)) {
			mx = (arr[i] - arr[i - 1]) >> 1;
			ans = arr[i - 1] + mx;
		}
	}
	cout << ans;

}