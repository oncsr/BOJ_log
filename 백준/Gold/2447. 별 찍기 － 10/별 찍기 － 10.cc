#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int> M;
	M[3] = 0, M[9] = 1, M[27] = 2, M[81] = 3;
	M[243] = 4, M[729] = 5, M[2187] = 6;
	int N;
	cin >> N;
	string a[7][2187]{};
	a[0][0] = "***", a[0][1] = "* *", a[0][2] = "***";
	for (int i = 1; i < 7; i++) {
		int k = 3, temp = i;
		while (temp--)	k *= 3;
		for (int g = 0; g < k; g++) {
			if (g < k / 3)
				a[i][g] = a[i - 1][g % (k / 3)] + a[i - 1][g % (k / 3)] + a[i - 1][g % (k / 3)];
			else if (g < k / 3 * 2) {
				a[i][g] = a[i - 1][g % (k / 3)];
				for (int h = 0; h < k / 3; h++)	a[i][g] += ' ';
				a[i][g] += a[i - 1][g % (k / 3)];
			}
			else {
				a[i][g] = a[i - 1][g % (k / 3)] + a[i - 1][g % (k / 3)] + a[i - 1][g % (k / 3)];
			}
		}
	}
	for (int i = 0; i < N; i++)	cout << a[M[N]][i] << '\n';
}