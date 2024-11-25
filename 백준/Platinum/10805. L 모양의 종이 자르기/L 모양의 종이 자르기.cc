#include <bits/stdc++.h>
using namespace std;

int C[51][51]{}, D[51][51][51][51]{};

int cal_C(int h, int w);
int cal_D(int h1, int w1, int h2, int w2);

int cal_C(int h, int w) {
	if (C[h][w])	return C[h][w];
	if (h == 1)	return C[h][w] = w;
	if (w == 1)	return C[h][w] = h;
	if (h == w)	return C[h][w] = 1;
	int &res = C[h][w];
	res = 1e9;
	for (int i = 1; i < w; i++) {
		res = min(res, cal_C(h, i) + cal_C(h, w - i));
	}
	for (int i = 1; i < h; i++) {
		res = min(res, cal_C(i, w) + cal_C(h - i, w));
	}
	return C[w][h] = res;
}

int cal_D(int h1, int w1, int h2, int w2) {
	if (D[h1][w1][h2][w2])	return D[h1][w1][h2][w2];
	int& res = D[h1][w1][h2][w2];
	res = min(cal_C(h1, w1 - w2) + cal_C(h1 - h2, w2), cal_C(h2, w1 - w2) + cal_C(h1 - h2, w1));
	for (int i = 1; i < w2; i++) {
		res = min(res, cal_C(i, h1 - h2) + cal_D(h1, w1 - i, h2, w2 - i));
	}
	for (int i = w2 + 1; i < w1; i++) {
		res = min(res, cal_C(h1, w1 - i) + cal_D(h1, i, h2, w2));
	}
	
	for (int i = 1; i < h2; i++) {
		res = min(res, cal_C(i, w1 - w2) + cal_D(h1 - i, w1, h2 - i, w2));
	}
	for (int i = h2 + 1; i < h1; i++) {
		res = min(res, cal_C(h1 - i, w1) + cal_D(i, w1, h2, w2));
	}
	return D[w1][h1][w2][h2] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	C[1][1] = 1;

	int h1, w1, h2, w2;
	cin >> h1 >> w1 >> h2 >> w2;

	cout << cal_D(h1, w1, h2, w2);

}