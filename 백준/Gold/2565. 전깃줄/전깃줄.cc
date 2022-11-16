#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

int main() {
	ii arr[100]{};
	int n, d[100]{}, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		d[i] = 1;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j].second > arr[i].second)
				d[j] = max(d[j], d[i] + 1);
			mx = max(mx, d[j]);
		}
	}
	cout << n - mx;
}