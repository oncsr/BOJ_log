#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[1000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	int s = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] > s + 1)	break;
		s += arr[i];
	}
	cout << s + 1;
}