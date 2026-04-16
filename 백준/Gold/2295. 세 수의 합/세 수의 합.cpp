#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int &i : A) cin >> i;
	
	set<int> P;
	vector<pair<int,int>> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		P.insert(A[i] + A[j]);
		M.emplace_back(A[i] - A[j], A[j]);
	}
	
	int ans = INT_MIN;
	for (auto[x, v] : M) if (P.count(-x)) ans = max(ans, v);
	cout << ans;

}