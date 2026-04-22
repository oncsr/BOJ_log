#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string a;
	cin >> N >> a;
	int A = 0, B = 0, SET = 1, SCORE_A = 0, SCORE_B = 0, DUCE = 0;
	for (char i : a) {
		if (i == 'A')	A++;
		else	B++;
		if (DUCE) {
			if (A > B + 1)	SCORE_A++, SET++, A = 0, B = 0, DUCE = 0;
			else if (B > A + 1)	SCORE_B++, SET++, A = 0, B = 0, DUCE = 0;
		}
		else {
			if (SET <= 2) {
				if (A == 24 && B == 24)	DUCE = 1, A = 0, B = 0;
				else if (A == 25)	SCORE_A++, SET++, A = 0, B = 0;
				else if (B == 25)	SCORE_B++, SET++, A = 0, B = 0;
			
			}
			else {
				if (A == 14 && B == 14)	DUCE = 1, A = 0, B = 0;
				else if (A == 15) {
					SCORE_A++;
					break;
				}
				else if (B == 15) {
					SCORE_B++;
					break;
				}
			}
		}
		if (abs(SCORE_A - SCORE_B) > 1)	break;
	}
	cout << SCORE_A << ' ' << SCORE_B;
}