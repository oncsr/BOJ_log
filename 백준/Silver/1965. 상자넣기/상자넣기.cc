#include <iostream>
using namespace std;

int main() {
	int N, d[1001][1001]{}, a[1001]{}, mx = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> a[i];
	for (int i = 1; i <= N; i++) {
		d[i][i] = d[i - 1][i];
		for (int j = i + 1; j <= N; j++) {
			if (a[j] > a[i])
				d[i][j] = max(d[i - 1][j], d[i][i] + 1);
			else
				d[i][j] = d[i - 1][j];
			mx = max(mx, d[i][j]);
		}
	}
	cout << mx + 1;
}