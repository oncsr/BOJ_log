#include <iostream>
using namespace std;

int map[128][128];
int white = 0, blue = 0;

void divide(int a, int b, int c, int d) {
	int w = 0, u = 0;
	for (int i = a; i < c; i++) {
		for (int j = b; j < d; j++) {
			if (map[i][j])	u++;
			else	w++;
		}
	}
	if (u == 0)	white++;
	else if (w == 0)	blue++;
	else {
		divide(a, b, (a + c) / 2, (b + d) / 2);
		divide((a + c) / 2, b, c, (b + d) / 2);
		divide(a, (b + d) / 2, (a + c) / 2, d);
		divide((a + c) / 2, (b + d) / 2, c, d);
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	cin >> map[i][j];
	divide(0, 0, n, n);
	cout << white << '\n' << blue;
}