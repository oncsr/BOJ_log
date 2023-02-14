#include <bits/stdc++.h>
using namespace std;

int main() {
	int map[19][19]{}, win = 0, x, y;
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> map[i][j];

	// 가로
	for (int i = 0; i < 19; i++) {
		int b = 0, w = 0;
		if (win)	break;
		for (int j = 0; j < 19; j++) {
			if (win)	break;
			if (map[i][j] == 1) {
				b++;
				if (w == 5) {
					win = 2;
					break;
				}
				if (b == 1)	x = i, y = j;
			}
			else {
				if (b == 5)	win = 1;
				else	b = 0;
			}
			if (map[i][j] == 2) {
				w++;
				if (b == 5) {
					win = 1;
					break;
				}
				if (w == 1)	x = i, y = j;
			}
			else {
				if (w == 5)	win = 2;
				else	 w = 0;
			}
		}
		if (win)	break;
		if (w == 5) {
			win = 2;
			x = i, y = 14;
		}
		if (b == 5) {
			win = 1;
			x = i, y = 14;
		}
	}

	// 세로
	if (!win) {
		for (int j = 0; j < 19; j++) {
			if (win)	break;
			int b = 0, w = 0;
			for (int i = 0; i < 19; i++) {
				if (win)	break;
				if (map[i][j] == 1) {
					b++;
					if (w == 5) {
						win = 2;
						break;
					}
					if (b == 1)	x = i, y = j;
				}
				else {
					if (b == 5)	win = 1;
					else	b = 0;
				}
				if (map[i][j] == 2) {
					w++;
					if (b == 5) {
						win = 1;
						break;
					}
					if (w == 1)	x = i, y = j;
				}
				else {
					if (w == 5)	win = 2;
					else	w = 0;
				}
			}
			if (win)	break;
			if (w == 5) {
				win = 2;
				x = 14, y = j;
			}
			if (b == 5) {
				win = 1;
				x = 14, y = j;
			}
		}
	}

	// 대각선 1
	if (!win) {
		for (int i = 14; i >= 0; i--) {
			int b = 0, w = 0;
			if (win)	break;
			for (int k = 0; i + k <= 18; k++) {
				if (win)	break;
				if (map[i + k][k] == 1) {
					b++;
					if (w == 5) {
						win = 2;
						break;
					}
					if (b == 1)	x = i+k, y = k;
				}
				else {
					if (b == 5)	win = 1;
					else	b = 0;
				}
				if (map[i + k][k] == 2) {
					w++;
					if (b == 5) {
						win = 1;
						break;
					}
					if (w == 1)	x = i+k, y = k;
				}
				else {
					if (w == 5)	win = 2;
					else	w = 0;
				}
			}
			if (win)	break;
			if (w == 5) {
				win = 2;
				x = 14, y = 14 - i;
			}
			if (b == 5) {
				win = 1;
				x = 14, y = 14 - i;
			}
		}
		for (int j = 1; j <= 14; j++) {
			if (win)	break;
			int b = 0, w = 0;
			for (int k = 0; k + j <= 18; k++) {
				if (win)	break;
				if (map[k][j + k] == 1) {
					b++;
					if (w == 5) {
						win = 2;
						break;
					}
					if (b == 1)	x = k, y = j + k;
				}
				else {
					if (b == 5)	win = 1;
					else	b = 0;
				}
				if (map[k][j + k] == 2) {
					w++;
					if (b == 5) {
						win = 1;
						break;
					}
					if (w == 1)	x = k, y = j + k;
				}
				else {
					if (w == 5)	win = 2;
					else	w = 0;
				}
			}
			if (win)	break;
			if (w == 5) {
				win = 2;
				x = 14 - j, y = 14;
			}
			if (b == 5) {
				win = 1;
				x = 14 - j, y = 14;
			}
		}
	}

	// 대각선 2
	if (!win) {
		for (int i = 14; i >= 0; i--) {
			int b = 0, w = 0;
			for (int k = 0; k + i <= 18; k++) {
				if (win)	break;
				if (map[i + k][18 - k] == 1) {
					b++;
					if (w == 5) {
						win = 2;
						x = i + k - 1, y = 18 - k + 1;
						break;
					}
				}
				else {
					if (b == 5) {
						win = 1;
						x = i + k - 1, y = 18 - k + 1;
					}
					else	b = 0;
				}
				if (map[i + k][18 - k] == 2) {
					w++;
					if (b == 5) {
						win = 1;
						x = i + k - 1, y = 18 - k + 1;
						break;
					}
					if (w == 1)	x = i + k, y = 18 + k;
				}
				else {
					if (w == 5) {
						win = 2;
						x = i + k - 1, y = 18 - k + 1;
					}
					else	w = 0;
				}
			}
			if (win)	break;
			if (w == 5) {
				win = 2;
				x = 18, y = i;
			}
			if (b == 5) {
				win = 1;
				x = 18, y = i;
			}
			if (win)	break;
		}
		for (int j = 17; j >= 4; j--) {
			if (win)	break;
			int b = 0, w = 0;
			for (int k = 0; j - k >= 0; k++) {
				if (win)	break;
				if (map[k][j - k] == 1) {
					b++;
					if (w == 5) {
						win = 2;
						x = k - 1, y = j - k + 1;
						break;
					}
				}
				else {
					if (b == 5) {
						win = 1;
						x = k - 1, y = j - k + 1;
					}
					else	b = 0;
				}
				if (map[k][j - k] == 2) {
					w++;
					if (b == 5) {
						win = 1;
						x = k - 1, y = j - k + 1;
						break;
					}
				}
				else {
					if (w == 5) {
						win = 2;
						x = k - 1, y = j - k + 1;
					}
					else	w = 0;
				}
			}
			if (win)	break;
			if (w == 5) {
				win = 2;
				x = j, y = 0;
			}
			if (b == 5) {
				win = 1;
				x = j, y = 0;
			}
		}
	}

	if (win) {
		cout << win << '\n' << x + 1 << ' ' << y + 1;
	}
	else	cout << 0;
}