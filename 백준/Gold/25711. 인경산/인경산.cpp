#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q;
	cin >> N >> Q;
	double X[200001]{}, Y[200001]{}, R[200001]{}, L[200001]{};
	for (int i = 1; i <= N; i++)	cin >> X[i];
	for (int i = 1; i <= N; i++) {
		cin >> Y[i];
		if (i == 1)	continue;
		double d = sqrt((X[i] - X[i - 1]) * (X[i] - X[i - 1]) + (Y[i] - Y[i - 1]) * (Y[i] - Y[i - 1]));
		R[i] += R[i - 1];
		if (Y[i] > Y[i - 1])	R[i] += 3 * d;
		else if (Y[i] < Y[i - 1])	R[i] += d;
		else	R[i] += 2 * d;
	}
	for (int i = N - 1; i >= 1; i--) {
		double d = sqrt((X[i] - X[i + 1]) * (X[i] - X[i + 1]) + (Y[i] - Y[i + 1]) * (Y[i] - Y[i + 1]));
		L[i] += L[i + 1];
		if (Y[i] > Y[i + 1])	L[i] += 3 * d;
		else if (Y[i] < Y[i + 1])	L[i] += d;
		else	L[i] += 2 * d;
	}
	cout.setf(ios::fixed);
	cout.precision(9);
	for (; Q--;) {
		int a, b;
		cin >> a >> b;
		if (a < b)	cout << R[b] - R[a] << '\n';
		else	cout << L[b] - L[a] << '\n';
	}
	cout.unsetf(ios::fixed);
}