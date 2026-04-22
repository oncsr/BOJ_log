#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[2001][2001]{};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int r = (j + i - 1) % N;
			if (!r)	r = N;
			arr[r][j] = (i - 1) * N + j;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	cout << arr[i][j] << ' ';
		cout << '\n';
	}
}