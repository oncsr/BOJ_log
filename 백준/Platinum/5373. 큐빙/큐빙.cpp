#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (cin >> t; t--;) {
		string cube[9]{};
		cube[0] = cube[1] = cube[2] = "ooo";
		cube[3] = cube[4] = cube[5] = "wwwbbbyyyggg";
		cube[6] = cube[7] = cube[8] = "rrr";
		int n;
		for (cin >> n; n--;) {
			char a, o;
			cin >> a >> o;
			if (a == 'U') {
				string temp[3]{}, temp2[2]{};
				if (o == '+') {
					for (int i = 0; i < 3; i++) {
						for (int j = 5; j >= 2; j--)
							temp[i] += cube[j][i];
						temp[i] += cube[6][i];
					}
					for (int i = 5; i >= 3; i--) {
						temp2[0] += cube[i][11];
						temp2[1] += cube[i][3];
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						for (int j = 3; j < 7; j++)
							temp[i] += cube[j][2 - i];
						temp[i] += cube[2][2 - i];
					}
					for (int i = 3; i < 6; i++) {
						temp2[0] += cube[i][3];
						temp2[1] += cube[i][11];
					}
				}
				for (int i = 0; i < 3; i++)	cube[2][i] = temp2[0][i];
				for (int i = 0; i < 3; i++)	cube[6][i] = temp2[1][i];
				for (int i = 3; i <= 5; i++) {
					for (int j = 0; j < 4; j++)
						cube[i][j] = temp[i - 3][j];
					cube[i][11] = temp[i - 3][4];
				}
			}
			if (a == 'D') {
				string temp[3]{}, temp2[2]{};
				if (o == '+') {
					for (int i = 0; i < 3; i++) {
						temp[i] = cube[8][2 - i];
						for (int j = 5; j >= 3; j--)
							temp[i] += cube[j][i + 6];
						temp[i] += cube[0][2 - i];
					}
					for (int i = 3; i <= 5; i++) {
						temp2[0] += cube[i][5];
						temp2[1] += cube[i][9];
					}
				}
				else {
					for (int i = 0; i < 3; i++) {
						temp[i] = cube[0][i];
						for (int j = 3; j < 6; j++)
							temp[i] += cube[j][8 - i];
						temp[i] += cube[8][i];
					}
					for (int i = 5; i >= 3; i--) {
						temp2[0] += cube[i][9];
						temp2[1] += cube[i][5];
					}
				}
				for (int i = 0; i < 3; i++) {
					cube[0][i] = temp2[0][i];
					cube[8][i] = temp2[1][i];
				}
				for (int i = 3; i <= 5; i++) {
					for (int j = 5; j < 10; j++)
						cube[i][j] = temp[i - 3][j - 5];
				}
			}
			if (a == 'F') {
				string temp2 = "", temp[3]{};
				if (o == '+') {
					for (int i = 0; i < 3; i++) {
						for (int j = 8; j >= 6; j--)
							temp[i] += cube[j][i];
					}
					for (int j = 9; j < 21; j++)
						temp2 += cube[5][j % 12];
				}
				else {
					for (int i = 0; i < 3; i++) {
						for (int j = 6; j < 9; j++)
							temp[i] += cube[j][2 - i];
					}
					for (int j = 3; j < 15; j++)
						temp2 += cube[5][j % 12];
				}
				for (int i = 0; i < 12; i++)	cube[5][i] = temp2[i];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++)
						cube[i + 6][j] = temp[i][j];
				}
			}
			if (a == 'B') {
				string temp2 = "", temp[3]{};
				if (o == '+') {
					for (int i = 0; i < 3; i++) {
						for (int j = 2; j >= 0; j--)
							temp[i] += cube[j][i];
					}
					for (int j = 3; j < 15; j++)
						temp2 += cube[3][j % 12];
				}
				else {
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++)
							temp[i] += cube[j][2 - i];
					}
					for (int j = 9; j < 21; j++)
						temp2 += cube[3][j % 12];
				}
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						cube[i][j] = temp[i][j];
				for (int i = 0; i < 12; i++)	cube[3][i] = temp2[i];
			}
			if (a == 'L') {
				string temp2 = "", temp[3]{};
				if (o == '+') {
					for (int i = 0; i < 3; i++) {
						temp[i] += cube[8 - i][0];
						for (int j = 5; j >= 3; j--)
							temp[i] += cube[j][i + 9];
					}
					for (int i = 5; i >= 3; i--)
						temp2 += cube[i][8];
					for (int i = 0; i < 6; i++)
						temp2 += cube[i][0];
				}
				else {
					for (int i = 0; i < 3; i++) {
						temp[i] += cube[2 - i][0];
						for (int j = 3; j < 6; j++)
							temp[i] += cube[j][11 - i];
					}
					for (int i = 3; i < 9; i++)
						temp2 += cube[i][0];
					for (int i = 5; i >= 3; i--)
						temp2 += cube[i][8];
				}
				for (int i = 0; i < 9; i++)	cube[i][0] = temp2[i];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++)
						cube[i + 3][j + 8] = temp[i][j];
				}
			}
			if (a == 'R') {
				string temp2 = "", temp[3]{};
				if (o == '+') {
					for (int i = 0; i < 3; i++) {
						for (int j = 5; j >= 3; j--)
							temp[i] += cube[j][i + 3];
						temp[i] += cube[2 - i][2];
					}
					for (int i = 3; i < 9; i++)
						temp2 += cube[i][2];
					for (int i = 5; i >= 3; i--)
						temp2 += cube[i][6];
				}
				else {
					for (int i = 0; i < 3; i++) {
						for (int j = 3; j < 6; j++)
							temp[i] += cube[j][5 - i];
						temp[i] += cube[8 - i][2];
					}
					for (int i = 5; i >= 3; i--)
						temp2 += cube[i][6];
					for (int i = 0; i < 6; i++)
						temp2 += cube[i][2];
				}
				for (int i = 0; i < 9; i++)	cube[i][2] = temp2[i];
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++)
						cube[i + 3][j + 3] = temp[i][j];
				}
			}
		}
		for (int i = 3; i < 6; i++) {
			for (int j = 0; j < 3; j++)	cout << cube[i][j];
			cout << '\n';
		}
	}
}