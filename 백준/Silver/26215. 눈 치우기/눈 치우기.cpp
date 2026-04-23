#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[100]{};
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	int e = n - 1, c = 0;
	while (arr[e] && c <= 1440) {
		int t;
		if (e - 1 >= 0) {
			if (arr[e - 1]) {
				arr[e - 1]--;
				arr[e]--;
				c++;
			}
			else {
				c += arr[e];
				arr[e] = 0;
			}
		}
		else {
			c += arr[e];
			arr[e] = 0;
		}
		sort(arr, arr + n);
	}
	cout << (c > 1440 ? -1 : c);
}