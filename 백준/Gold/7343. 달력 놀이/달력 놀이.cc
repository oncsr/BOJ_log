#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// d[i][j][k] = (1900+i)년 j월 k일에서 시작했을 때 이길 수 있나?
	bool d[102][13][32]{};
	for (int i = 0; i < 102; i++)
		for (int j = 1; j < 13; j++)
			for (int k = 1; k < 32; k++)
				d[i][j][k] = 1;
	d[101][11][4] = 0;
	int i = 101, j = 11, k = 3;
	while (i >= 0) {
		if (i != 101 || j != 11 || k != 3)
			d[i][j][k] ^= 1;
		if (k == 1) {
			// 전 달 말일로 넘어가기
			if (i == 0 && j == 1)	break;
			if (j == 1)	d[i - 1][12][31] &= d[i][j][k];
			else {
				if (j == 3) {
					// 윤년이면 2/29로
					int year = i + 1900;
					if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
						d[i][2][29] &= d[i][j][k];
					else
						d[i][2][28] &= d[i][j][k];
				}
				else if (j == 5 || j == 7 || j == 10 || j == 12)	d[i][j - 1][30] &= d[i][j][k];
				else	d[i][j - 1][31] &= d[i][j][k];
			}
		}
		else	d[i][j][k - 1] &= d[i][j][k];
		// 전 달의 같은 날짜가 존재하는지
		/*
		* 1. 3/29에서 못감(윤년 제외)
		* 2. 3,5,7,10,12/31에서 못감
		*/
		if (!(j == 3 && k > 29) && !(j == 3 && k == 29 && !(i % 4 == 0 && (!(i % 100 == 0) || i % 400 == 0)))) {
			if (!((j == 3 || j == 5 || j == 7 || j == 10 || j == 12) && k == 31) && !(i == 0 && j == 1)) {
				if (j == 1)	d[i - 1][12][k] &= d[i][j][k];
				else	d[i][j - 1][k] &= d[i][j][k];
			}
		}

		// 날짜 줄이기
		if (k == 1) {
			if (i == 0 && j == 1)	break;
			if (j == 1)	i--, j = 12, k = 31;
			else {
				if (j == 3) {
					int year = i + 1900;
					if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
						k = 29;
					else
						k = 28;
				}
				else if (j == 5 || j == 7 || j == 10 || j == 12)	k = 30;
				else	k = 31;
				j--;
			}
		}
		else	k--;
	}
	d[101][11][4] = 1;
	int N;
	for (cin >> N; N--;) {
		int a, b, c;
		cin >> a >> b >> c;
		a -= 1900;
		cout << (d[a][b][c] ? "YES\n" : "NO\n");
	}
}