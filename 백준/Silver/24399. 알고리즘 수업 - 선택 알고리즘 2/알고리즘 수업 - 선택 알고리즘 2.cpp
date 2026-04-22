#include <iostream>
using namespace std;

int arr[10001]{}, N, Q, K, sw = 0;

int partition(int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (arr[j] <= x)	swap(arr[++i], arr[j]), sw++;
		if (sw == K)	return -1;
	}
	if (i + 1 != r)	swap(arr[i + 1], arr[r]), sw++;
	if (sw == K)	return -1;
	return i + 1;
}

int select(int p, int r, int q) {
	if (p == r)	return arr[p];
	int t = partition(p, r);
	if (t == -1)	return -1;
	int k = t - p + 1;
	if (q < k)	return select(p, t - 1, q);
	if (q == k)	return arr[t];
	return select(t + 1, r, q - k);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	if (select(1, N, Q) == -1) {
		for (int i = 1; i <= N; i++)	cout << arr[i] << ' ';
	}
	else	cout << -1;
}