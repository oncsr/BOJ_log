#include <iostream>
using namespace std;

int P[1000001]{ 0,1 }, Q[1000001]{ 0,1 }, S, E, N, p;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> S;
	p = S;
	for (int i = 2; i <= N; i++) {
		cin >> E;
		P[i] = P[i - 1] + (E - p >= 0);
		Q[i] = Q[i - 1] + (E - p <= 0);
		p = E;
	}
	if (P[N] == N || Q[N] == N) return cout << 0, 0;
	for (int K = 1; K < N; K++) if ((P[N] - P[K+1] == N - K - 1 && P[K] == K && E <= S) || (Q[N] - Q[K+1] == N - K - 1 && Q[K] == K && E >= S)) return cout << K, 0;
	cout << -1;

}