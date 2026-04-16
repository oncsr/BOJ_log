#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N;
	vector<int> V(N);
	for (int& i : V)	cin >> i;
	cin >> M;
	if (M <= N)	return cout << V[M - 1], 0;
	sort(V.begin(), V.end());
	M -= N;
	V.erase(unique(V.begin(), V.end()), V.end());
	int s = V.size();
	int p = lower_bound(V.begin(), V.end(), s) - V.begin();
	if (p == V.size())	return cout << s + M - 1, 0;
	int e = V[p];
	if (M >= e - s + 1)	cout << e;
	else	cout << s + M - 1;

}