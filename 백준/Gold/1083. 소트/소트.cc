#include <iostream>
using namespace std;
int main() {
	int n, s;
	int arr[51]{};
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	cin >> s;
	int end = 0, mx = 0, mxid = 0;
	while (s > 0 && end < n) {
		for (int i = end; i < min(end+s+1,n); i++) {
			if (arr[i] > mx) {
				mx = arr[i];
				mxid = i;
			}
		}
		if (mxid == end) {
			end++;
			mx = mxid = 0;
			continue;
		}
		for (int i = mxid; i > end; i--) {
			swap(arr[i], arr[i - 1]);
			s--;
		}
		end++;
		mx = mxid = 0;
	}
	for (int i = 0; i < n; i++)cout << arr[i] << ' ';
}