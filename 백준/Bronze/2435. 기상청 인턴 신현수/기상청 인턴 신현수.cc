#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[101];
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i == 0)
			arr[i] = a;
		else
			arr[i] = arr[i - 1] + a;
	}
	int max = arr[k-1];
	for (int i = 0; i < n - k; i++) {
		if (arr[i + k] - arr[i] > max)
			max = arr[i + k] - arr[i];
	}
	cout << max << '\n';
}