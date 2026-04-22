#include <iostream>
using namespace std;
using ll = long long;

void solve(int N, int s) {
	if (N == 0) {
		if (s)	cout << '#';
		else	cout << '.';
		return;
	}
	if (N == 1) {
		if (s == 2)	cout << "##";
		else if (s == 1)	cout << "#.";
		else	cout << "..";
		return;
	}
	int L, R;
	if (s <= (1 << (N - 1))) {
		for (int i = 0; i < s; i++)	cout << '#';
		for (int i = s; i < (1 << N); i++)	cout << '.';
		return;
	}
	else {
		R = (1 << (N - 2));
		L = s - R;
		if (L > (1 << (N - 1)))	L = (1 << (N - 1)), R = s - L;
	}
	solve(N - 1, L);
	solve(N - 1, R);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	int G = 1, c = 0;
	while (G < N)	G <<= 1, c++;
	solve(c, N);
}