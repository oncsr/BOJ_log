#include <iostream>
using namespace std;

/*
* 2022.11.13
* [used algorithm]
* =>
* [point]
* =>
*/
int N, arr[11]{}, op[4]{}, mn = 1000000001, mx = -1000000001;

void R(int n, int res) {
	if (n == N) {
		mx = max(mx, res);
		mn = min(mn, res);
		return;
	}
	if (op[0]) {
		op[0]--;
		R(n + 1, res + arr[n]);
		op[0]++;
	}
	if (op[1]) {
		op[1]--;
		R(n + 1, res - arr[n]);
		op[1]++;
	}
	if (op[2]) {
		op[2]--;
		R(n + 1, res * arr[n]);
		op[2]++;
	}
	if (op[3]) {
		op[3]--;
		R(n + 1, res / arr[n]);
		op[3]++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	for (int i = 0; i < 4; i++)	cin >> op[i];
	R(1, arr[0]);
	cout << mx << '\n' << mn;
}