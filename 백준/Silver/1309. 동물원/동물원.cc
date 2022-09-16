#include <iostream>
using namespace std;

int main() {
	int n;
	int d[100001][3]{ {},{1,1,1} };
	cin >> n;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
	}
	cout << (d[n][0] + d[n][1] + d[n][2]) % 9901;
}