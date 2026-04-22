#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[1 << 20 + 1]{}, N, K;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	cin >> K;
	for (int i = 0; i < K; i++)
		sort(arr + N / K * i, arr + N / K * (i + 1));
	for (int i = 0; i < N; i++)	cout << arr[i] << ' ';
}