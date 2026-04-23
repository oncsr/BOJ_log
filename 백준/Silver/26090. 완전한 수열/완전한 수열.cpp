#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[501]{};
	int e[1000001]{};
	for (int i = 2; i * i <= 1000000; i++) {
		if (!e[i]) {
			for (int j = i * 2; j <= 1000000; j += i)	e[j] = 1;
		}
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int s = 0;
	for (int i = 2; i <= N; i++) {
		if (!e[i]) {
			for (int j = i; j <= N; j++) {
				int g = arr[j] - arr[j - i];
				if (!e[g] && g > 1)	s++;
			}
		}
	}
	cout << s;
}