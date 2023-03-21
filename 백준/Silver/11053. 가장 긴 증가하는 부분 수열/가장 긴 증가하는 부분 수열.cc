#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[1001]{}, d[1001]{}, N, mx = 1;
	cin >> N;
	for (int i = 1; i <= N; i++)	d[i] = 1;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (arr[j] > arr[i])	d[j] = max(d[j], d[i] + 1);
			mx = max(mx, d[j]);
		}
	}
	cout << mx;
}