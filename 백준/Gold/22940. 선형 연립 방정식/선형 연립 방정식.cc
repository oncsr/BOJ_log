#include <iostream>
using namespace std;

int main() {
	int N;
	double map[6][6]{};
	double ans[6]{};
	double real[6]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> map[i][j];
		cin >> ans[i];
	}
	for (int i = 0; i < N; i++) {
		double pivot = map[i][i];
		if (pivot == 0) {
			for (int temp = i + 1; temp < N; temp++) {
				if (map[temp][i]) {
					for (int k = i; k < N; k++)	swap(map[i][k], map[temp][k]);
					swap(ans[i], ans[temp]);
					pivot = map[i][i];
					break;
				}
			}
		}
		for (int j = i + 1; j < N; j++) {
			double now = map[j][i];
			for (int k = i; k < N; k++) {
				map[j][k] += (map[i][k] * -1 * now / pivot);
			}
			ans[j] += (ans[i] * -1 * now / pivot);
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		double g = ans[i];
		for (int j = N - 1; j > i; j--) {
			g -= real[j] * map[i][j];
		}
		real[i] = g / map[i][i];
	}
	for (int i = 0; i < N; i++)	cout << real[i] << ' ';
}