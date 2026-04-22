#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, arr[100000]{}, same = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);
	bool up = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])	same++;
		if (arr[i] / 2 < arr[i - 1] && arr[i] != arr[i - 1]) {
			cout << arr[i - 1] / 2;
			return 0;
		}
		if (arr[i] != arr[i-1] && !up) {
			cout << arr[i - 1];
			return 0;
		}
	}
	cout << arr[0];
}