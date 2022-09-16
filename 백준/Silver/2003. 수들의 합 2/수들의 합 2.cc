#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int arr[10001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int* one = arr;
	int* two = arr + 1;
	int sum = *one + *two;
	int cnt = 0;
	if (*one == m)
		cnt++;
	while (one != arr + n - 1) {
		if (sum < m) {
			if (two == arr + n - 1)
				break;
			two++;
			sum += *two;
		}
		else if (sum > m) {
			sum -= *one;
			one++;
		}
		else {
			cnt++;
			if (two == arr + n - 1) {
				sum -= *one;
				one++;
			}
			else {
				two++;
				sum += *two;
			}
		}
	}
	if (*one == m && one != arr)
		cnt++;
	cout << cnt << '\n';
}