#include "monkey.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long max_bananas(std::vector<int> A, std::vector<int> B,
            std::vector<std::pair<int, int> > P) {
    ll N = A.size();
	for (auto& [a, b] : P)	a--, b--;
	sort(P.begin(), P.end(), [&](auto a, auto b) -> bool {
		auto [xa, ya] = a;
		auto [xb, yb] = b;
		if (min(xa, ya) == min(xb, yb))	return max(xa, ya) < max(xb, yb);
		return min(xa, ya) < min(xb, yb);
	});
	vector<ll> L(N), R(N);
	for (auto& [x, y] : P) {
		ll v = max({ R[y] + A[x], L[x] + B[y], ll(A[x] + B[y]) });
		L[x] = max(L[x], v);
		R[y] = max(R[y], v);
	}
	return max(*max_element(L.begin(), L.end()), *max_element(R.begin(), R.end()));
}
