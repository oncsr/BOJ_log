#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q, S = 0;
	cin >> N >> Q;
	vector<int> A(N, 1);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		for (int j = i; j > i - 4; j--) {
			int x = (j + N) % N;
			A[x] *= a;
		}
	}
	for (int i = 0; i < N; i++)	S += A[i];

	for (; Q--;) {
		int a;
		cin >> a;
		a--;
		for (int j = a; j > a - 4; j--) {
			int x = (j + N) % N;
			S -= A[x];
			A[x] *= -1;
			S += A[x];
		}
		cout << S << '\n';
	}

}