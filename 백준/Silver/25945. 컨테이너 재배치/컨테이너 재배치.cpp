#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long N, arr[1000000]{}, s = 0, g = 0, h = 0, r = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s += arr[i];
	}
	sort(arr, arr + N);
	g = s % N;
	h = N - g;
	s /= N;
	for (int i = 0; i < N; i++) {
		if (i < h)	r += (abs(arr[i] - s));
		else	r += (abs(arr[i] - (s + 1)));
	}
	cout << r / 2;
}