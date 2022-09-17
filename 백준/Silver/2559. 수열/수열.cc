#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[100001];
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i < k) {
			sum += a[i];
			max += a[i];
		}
		else {
			sum = sum + a[i] - a[i - k];
			max = (sum > max ? sum : max);
		}
	}
	cout << max << '\n';
}