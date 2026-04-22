#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int Y = 0, K = 0;
	char a;
	while (cin >> a) {
		if (a == 'Y') {
			if (Y == 0)	Y++;
		}
		if (a == 'O') {
			if (Y == 1)	Y++;
			if (K == 1)	K++;
		}
		if (a == 'N') {
			if (Y == 2)	Y++;
		}
		if (a == 'S') {
			if (Y == 3)	Y++;
		}
		if (a == 'E') {
			if (Y == 4)	Y++;
			if (K == 3)	K++;
		}
		if (a == 'I') {
			if (Y == 5) {
				cout << "YONSEI";
				return 0;
			}
		}
		if (a == 'K') {
			if (K == 0)	K++;
		}
		if (a == 'R') {
			if (K == 2)	K++;
		}
		if (a == 'A') {
			if (K == 4) {
				cout << "KOREA";
				return 0;
			}
		}
	}
}