#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[100000]{}, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++)
		mx = max(mx, arr[i] + arr[n - 1] - arr[i + 1] * 2);
	for (int i = 1; i < n - 1; i++)
		mx = max(mx, arr[i] * 2 - arr[0] - arr[i + 1]);
	cout << mx;
}