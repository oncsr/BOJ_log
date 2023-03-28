#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[200001]{}, Q, s = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] < arr[i - 1])	s++;
	}
	if (N == 1)	cout << 1 << '\n';
	else if (N == 2) {
		if (arr[2] > arr[1])	cout << 1 << '\n';
		else	cout << 2 << '\n';
	}
	else {
		if (!s)	cout << 1 << '\n';
		else if (s == 1) {
			if (arr[1] > arr[N])	cout << 2 << '\n';
			else	cout << 3 << '\n';
		}
		else	cout << 3 << '\n';
	}
}