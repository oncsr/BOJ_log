#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, arr[100000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	int mn = 2000000001;
	int a = -1000000001, b = 1000000001;
	int s = 0, e = N - 1;
	while (s < e) {
		if (abs(arr[s] + arr[e]) < mn) {
			a = arr[s], b = arr[e];
			mn = abs(arr[s] + arr[e]);
		}
		
		if (arr[s] + arr[e] < 0)	s++;
		else	e--;

	}
	cout << a << ' ' << b;
}