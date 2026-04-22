#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[200001]{}, Q, sum[200001]{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] < arr[i - 1]) {
			sum[i] = sum[i - 1] + 1;
		}
		else	sum[i] = sum[i - 1];
	}
	for (cin >> Q; Q--;) {
		int l, r;
		cin >> l >> r;
		int cnt = sum[r] - sum[l];
		if (l == r)	cout << 1 << '\n';
		else if (r - l == 1) {
			if (arr[r] > arr[l])	cout << 1 << '\n';
			else	cout << 2 << '\n';
		}
		else {
			if (!cnt)	cout << 1 << '\n';
			else if (cnt == 1) {
				if (arr[l] > arr[r])	cout << 2 << '\n';
				else	cout << 3 << '\n';
			}
			else	cout << 3 << '\n';
		}
	}
}