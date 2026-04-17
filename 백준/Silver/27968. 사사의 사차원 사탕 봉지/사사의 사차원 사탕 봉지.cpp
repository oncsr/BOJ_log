#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<ll> A(M + 1);

	// 누적 합
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}

	for (; N--;)
	{
		ll b;	cin >> b;

		int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
		if (pos == M + 1)	cout << "Go away!\n";
		else	cout << pos << '\n';
	}

}