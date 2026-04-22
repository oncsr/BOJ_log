#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[50001]{}, N, a, sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		arr[i] = arr[i - 1] + a;
		sum += a;
	}
	int s = 1, e = 1, mx = 0;
	while (s <= N) {
		int g = min(arr[e] - arr[s - 1], sum - (arr[e] - arr[s - 1]));
		mx = max(mx, g);
		if (arr[e] - arr[s - 1] > sum / 2)	s++;
		else {
			if (e == N)	break;
			e++;
		}
	}
	cout << mx;
}