#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, d, arr[100001]{}, a, s = 0;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 0; i <= n; i++) {
		if (arr[i] <= d)	continue;
		int temp = arr[i] / d;
		s += temp;
		arr[i] = temp + arr[i] % d;
		while (arr[i] > d) {
			temp = arr[i] / d;
			s += temp;
			arr[i] = temp + arr[i] % d;
		}
	}
	cout << s;
}