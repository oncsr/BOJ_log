#include <iostream>
using namespace std;

int main() {
	int arr[1000][3]{}, N;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	int s = 2000000000, d[1000][3]{}, mn = s;
	d[0][0] = arr[0][0], d[0][1] = s, d[0][2] = s;
	d[1][0] = s, d[1][1] = min(d[0][0], d[0][2]) + arr[1][1];
	d[1][2] = min(d[0][0], d[0][1]) + arr[1][2];
	for (int i = 2; i < N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + arr[i][2];
	}
	mn = min(mn, min(d[N - 1][1], d[N - 1][2]));

	d[0][1] = arr[0][1], d[0][0] = s, d[0][2] = s;
	d[1][1] = s, d[1][0] = min(d[0][1], d[0][2]) + arr[1][0];
	d[1][2] = min(d[0][0], d[0][1]) + arr[1][2];
	for (int i = 2; i < N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + arr[i][2];
	}
	mn = min(mn, min(d[N - 1][0], d[N - 1][2]));

	d[0][2] = arr[0][2], d[0][1] = s, d[0][0] = s;
	d[1][2] = s, d[1][1] = min(d[0][0], d[0][2]) + arr[1][1];
	d[1][0] = min(d[0][2], d[0][1]) + arr[1][0];
	for (int i = 2; i < N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + arr[i][2];
	}
	mn = min(mn, min(d[N - 1][1], d[N - 1][0]));

	cout << mn;
}