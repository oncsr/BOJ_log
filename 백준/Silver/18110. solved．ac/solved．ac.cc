#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[300000]{};
	cin >> N;
	if (N) {
		for (int i = 0; i < N; i++)	cin >> arr[i];
		sort(arr, arr + N);
		int g = round(N * 15 / 100.0);
		int sum = 0;
		for (int i = g; i < N - g; i++)	sum += arr[i];
		int ave = round((double)sum / (N - 2 * g));
		cout << ave;
	}
	else	cout << 0;
}