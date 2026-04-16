#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int& i : A)	cin >> i;

	vector<int> R(N);
	queue<int> Q;
	int prev = A[0];
	for (int i = 0; i < N; i++) {
		if (A[i] != prev) {
			while (!Q.empty())	R[Q.front()] = i + 1, Q.pop();
		}
		Q.push(i);
		prev = A[i];
	}
	while (!Q.empty())	R[Q.front()] = -1, Q.pop();
	for (int i : R)	cout << i << ' ';

}