#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, arr[1000]{}, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int temp = -1, s = 1;
		for (int j = 0; j < n; j++) {
			if (arr[j] == arr[i])	continue;
			if (arr[j] == temp)	s++;
			else	mx = max(mx, s), s = 1, temp = arr[j];
		}
		mx = max(mx, s);
	}
	cout << mx;
}