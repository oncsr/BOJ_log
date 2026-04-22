#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int N;
		double arr[500]{};
		cin >> N;
		for (int i = 0; i < N; i++)	cin >> arr[i];
		if (N <= 4) {
			cout << "YES\n";
			continue;
		}
		long double a = (arr[3] - 3 * arr[2] + 3 * arr[1] - arr[0]) / 6;
		long double b = (arr[2] - 2 * arr[1] + arr[0] - 12 * a) / 2;
		long double c = arr[1] - arr[0] - 7 * a - 3 * b;
		long double d = arr[0] - a - b - c;
		bool right = 1;
		for (int i = 4; i < N; i++) {
			double g = i;
			g += 1;
			double F = a * g * g * g + b * g * g + c * g + d;
			if (abs(F - arr[i]) < 0.0000001)	continue;
			right = 0;
			cout << "NO\n";
			break;
		}
		if (right)	cout << "YES\n";
	}
}