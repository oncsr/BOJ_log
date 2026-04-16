#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	char A[100][100]{};
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];

	int garo = 0, sero = 0;
	for (int i = 0; i < N; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 'X') {
				if (cnt1 > 1) garo++;
				cnt1 = 0;
			}
			else cnt1++;

			if (A[j][i] == 'X') {
				if (cnt2 > 1) sero++;
				cnt2 = 0;
			}
			else cnt2++;
		}
		if (cnt1 > 1) garo++;
		if (cnt2 > 1) sero++;
	}

	cout << garo << ' ' << sero;

}