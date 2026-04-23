#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, L, arr[1000000]{}, s = 0, c = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s += arr[i];
		if (i >= L)	s -= arr[i - L];
		if (s >= 129 && s <= 138)	c++;
	}
	cout << c;
}