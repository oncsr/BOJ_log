#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[10000]{}, N, L, D;
	cin >> N >> L >> D;
	for (int i = 0, t = 0; i < N; i++) {
		for (int j = t; j < t + L; j++) arr[j] = 1;
		t += L + 5;
	}
	for (int t = 0; t < 10000; t += D) {
		if (!arr[t]) return cout << t, 0;
	}

}