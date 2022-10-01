#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double A[1001][1001];
	double I[1001][1001] = { 0 };
	int n;
	cin >> n;
	bool br = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	for (int i = 1; i < n; i++) {
		if (A[i - 1][i - 1] == 0) {
			if (A[i][i - 1] == 0) {
				br = true;
				break;
			}
			else {
				for (int j = i - 1; j < i + 2 && j < n; j++) {
					double tmp = A[i][j];
					A[i][j] = A[i - 1][j];
					A[i - 1][j] = tmp;
				}
			}
		}
		double tmp = A[i][i - 1] / A[i - 1][i - 1];
		I[i][i - 1] = tmp;
		for (int j = i - 1; j < i + 2 && j < n; j++)
			A[i][j] -= (A[i - 1][j] * tmp);
		if (A[i][i] == 0) {
			br = true;
			break;
		}
	}
	if (br)
		cout << -1 << '\n';
	else if (n == 1 && A[0][0] == 0)
		cout << -1 << '\n';
	else {
		cout.setf(ios::fixed);
		cout.precision(3);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					cout << 1.0 << ' ';
				else
					cout << I[i][j] << ' ';
			}
			cout << '\n';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << A[i][j] << ' ';
			cout << '\n';
		}
		cout.unsetf(ios::fixed);
	}
}