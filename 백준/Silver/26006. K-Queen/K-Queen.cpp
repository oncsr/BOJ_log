#include <iostream>
using namespace std;

/*
* 2022.11.13
* [used algorithm]
* =>
* [point]
* =>
*/

int main() {
	int N, K, R, C, a, b;
	cin >> N >> K >> R >> C;
	bool att = false;
	int arr[8]{}, s = 0;

	for (; K--;) {
		cin >> a >> b;
		if (a == R) {
			att = true;
			if (C - 1 >= 1) {
				if (!arr[3]++)	s++;
			}
			if (C + 1 <= N) {
				if (!arr[4]++)	s++;
			}
		}
		else if (a == R - 1) {
			if (C - 1 >= 1) {
				if (!arr[0]++)	s++;
			}
			if (!arr[1]++)	s++;
			if (C + 1 <= N) {
				if (!arr[2]++)	s++;
			}
		}
		else if (a == R + 1) {
			if (C - 1 >= 1) {
				if (!arr[5]++)	s++;
			}
			if (!arr[6]++)	s++;
			if (C + 1 <= N) {
				if (!arr[7]++)	s++;
			}
		}
		if (b == C) {
			att = true;
			if (R - 1 >= 1) {
				if (!arr[1]++)	s++;
			}
			if (R + 1 <= N) {
				if (!arr[6]++)	s++;
			}
		}
		else if (b == C - 1) {
			if (R - 1 >= 1) {
				if (!arr[0]++)	s++;
			}
			if (!arr[3]++)	s++;
			if (R + 1 <= N) {
				if (!arr[5]++)	s++;
			}
		}
		else if (b == C + 1) {
			if (R - 1 >= 1) {
				if (!arr[2]++)	s++;
			}
			if (!arr[4]++)	s++;
			if (R + 1 <= N) {
				if (!arr[7]++)	s++;
			}
		}
		if (R - 1 >= 1) {
			int tx = (R - 1) - a;
			int ty1 = b + tx, ty2 = b - tx;
			if (ty1 >= 1 && ty1 <= N) {
				if (ty1 == C - 1) {
					if (!arr[0]++)	s++;
				}
				else if (ty1 == C) {
					if (!arr[1]++)	s++;
				}
				else if (ty1 == C + 1) {
					if (!arr[2]++)	s++;
				}
			}
			if (ty2 >= 1 && ty2 <= N) {
				if (ty2 == C - 1) {
					if (!arr[0]++)	s++;
				}
				else if (ty2 == C) {
					if (!arr[1]++)	s++;
				}
				else if (ty2 == C + 1) {
					if (!arr[2]++)	s++;
				}
			}
		}
		int tx = R - a;
		int ty1 = b + tx, ty2 = b - tx;
		if (ty1 >= 1 && ty1 <= N) {
			if (ty1 == C - 1) {
				if (!arr[3]++)	s++;
			}
			else if (ty1 == C + 1) {
				if (!arr[4]++)	s++;
			}
			else if (ty1 == C) {
				att = true;
			}
		}
		if (ty2 >= 1 && ty2 <= N) {
			if (ty2 == C - 1) {
				if (!arr[3]++)	s++;
			}
			else if (ty2 == C + 1) {
				if (!arr[4]++)	s++;
			}
			else if (ty2 == C) {
				att = true;
			}
		}
		if (R + 1 <= N) {
			tx = R + 1 - a;
			ty1 = b + tx, ty2 = b - tx;
			if (ty1 >= 1 && ty1 <= N) {
				if (ty1 == C - 1) {
					if (!arr[5]++)	s++;
				}
				else if (ty1 == C) {
					if (!arr[6]++)	s++;
				}
				else if (ty1 == C + 1) {
					if (!arr[7]++)	s++;
				}
			}
			if (ty2 >= 1 && ty2 <= N) {
				if (ty2 == C - 1) {
					if (!arr[5]++)	s++;
				}
				else if (ty2 == C) {
					if (!arr[6]++)	s++;
				}
				else if (ty2 == C + 1) {
					if (!arr[7]++)	s++;
				}
			}
		}
	}
	int cnt = (R == N || R == 1) + (C == N || C == 1);
	if (cnt == 2)	cnt = 3;
	else if (cnt == 1)	cnt = 5;
	else	cnt = 8;
	if (att && s == cnt)	cout << "CHECKMATE";
	else if (att)	cout << "CHECK";
	else if (s == cnt)	cout << "STALEMATE";
	else	cout << "NONE";
}