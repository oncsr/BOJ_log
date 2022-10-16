#include <iostream>
#include <queue>
using namespace std;

int main() {
	long long N;
	double arr[100000][2];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0] >> arr[i][1];
	double ans = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0)	ans += (arr[i][0] * (arr[i + 1][1] - arr[N - 1][1]));
		else if (i == N - 1)	ans += (arr[i][0] * (arr[0][1] - arr[i - 1][1]));
		else	ans += (arr[i][0] * (arr[i + 1][1] - arr[i - 1][1]));
	}
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << abs(ans) / 2;
}