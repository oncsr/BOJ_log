#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[1000]{}, N, a, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i < 1000; i++) {
		if (!arr[i])	continue;
		arr[i]--;
		for (int j = 1; j < 1000; j++) {
			if (!arr[j])	continue;
			int G = i * j, t = 0;
			while (G > 0) {
				t += G % 10;
				G /= 10;
			}
			mx = max(mx, t);
		}
		arr[i]++;
	}
	cout << mx;
}