#include <iostream>
using namespace std;

int main() {
	bool arr[101][101]{};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				arr[j][k] = 1;
			}
		}
	}
	int s = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			s += arr[i][j];
		}
	}
	cout << s;
}