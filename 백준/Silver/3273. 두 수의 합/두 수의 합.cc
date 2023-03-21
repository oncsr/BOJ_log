#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, x;
	int arr[100000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);

	cin >> x;
	int ans = 0;
	int s = 0, e = N - 1;
	while (s < e) {
		if (arr[s] + arr[e] < x)	s++;
		else if (arr[s] + arr[e] > x)	e--;
		else	ans++, s++;
	}
	cout << ans;

}