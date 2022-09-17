#include <iostream>
using namespace std;

int arr1[101][101];
int arr2[101][101];

int main() {
	int n, m1;
	int m2, k;
	cin >> n >> m1;
	int m = m1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr1[i][j];

	cin >> m2 >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> arr2[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int s = 0;
			for (int p = 0; p < m; p++)
				s += (arr1[i][p] * arr2[p][j]);
			cout << s << ' ';
		}
		cout << '\n';
	}
}