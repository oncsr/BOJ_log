#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[500000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	int mn1 = 2000000001, mn2 = 2000000001;
	int hall = 1000000001, jjak = 1000000001;
	if (arr[0] % 2)	hall = arr[0];
	else	jjak = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] % 2) {
			if (hall != 1000000001)	mn2 = min(mn2, arr[i] - hall);
			if (jjak != 1000000001)	mn1 = min(mn1, arr[i] - jjak);
			hall = arr[i];
		}
		else {
			if (hall != 1000000001)	mn1 = min(mn1, arr[i] - hall);
			if (jjak != 1000000001)	mn2 = min(mn2, arr[i] - jjak);
			jjak = arr[i];
		}
	}
	cout << (mn2 == 2000000001 ? -1 : mn2) << ' ' << (mn1 == 2000000001 ? -1 : mn1);
}