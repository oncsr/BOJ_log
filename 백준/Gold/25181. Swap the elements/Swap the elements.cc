#include <iostream>
using namespace std;

int main() {
	int N, arr[5000]{}, cnt[100001]{}, mx = 0, arr2[5000]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
		cnt[arr[i]]++;
		mx = max(mx, cnt[arr[i]]);
	}
	if (mx > N / 2) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		bool find = 0;
		for (int j = i + 1; j < N; j++) {
			if (arr2[i] == arr[i] || arr2[j] == arr[j]) {
				if (arr2[i] != arr[j] && arr2[j] != arr[i]) {
					swap(arr2[i], arr2[j]);
					find = 1;
					break;
				}
			}
		}
		if (!find) {
			for (int j = i - 1; j >= 0; j--) {
				if (arr2[i] == arr[i] || arr2[j] == arr[j]) {
					if (arr2[i] != arr[j] && arr2[j] != arr[i]) {
						swap(arr2[i], arr2[j]);
						find = 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)	cout << arr2[i] << ' ';
}