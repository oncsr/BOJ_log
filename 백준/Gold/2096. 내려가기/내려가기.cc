#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[3][2]{}, d1[3][2]{}, d2[3][2]{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[0][i%2] >> arr[1][i%2] >> arr[2][i%2];
		d1[0][i%2] = min(d1[0][((i + 1)%2)], d1[1][(i + 1)%2]) + arr[0][i%2];
		d1[1][i%2] = min({ d1[0][(i + 1)%2], d1[1][(i + 1)%2], d1[2][(i + 1)%2] }) + arr[1][i%2];
		d1[2][i%2] = min(d1[1][(i + 1)%2], d1[2][(i + 1)%2]) + arr[2][i%2];
		d2[0][i%2] = max(d2[0][(i + 1)%2], d2[1][(i + 1)%2]) + arr[0][i%2];
		d2[1][i%2] = max({ d2[0][(i + 1)%2], d2[1][(i + 1)%2], d2[2][(i + 1)%2] }) + arr[1][i%2];
		d2[2][i%2] = max(d2[1][((i + 1)%2)], d2[2][(i + 1)%2]) + arr[2][i%2];
	}
	cout << max({ d2[0][N%2], d2[1][N%2], d2[2][N%2] }) << ' ';
	cout << min({ d1[0][N%2], d1[1][N%2], d1[2][N%2] });
}