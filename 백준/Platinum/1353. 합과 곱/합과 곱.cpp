#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double S, P;
	cin >> S >> P;
	int find = 0;
	double temp = S, g;
	if (P < S)	cout << 2;
	else if (S == P) cout << 1;
	else if (temp >= P)	cout << 1;
	else {
		for (int i = 1; i <= 18; i++) {
			if (pow(S / i, i) >= P) {
				find = 1;
				cout << i;
				break;
			}
		}
		if (!find)	cout << -1;
	}
}