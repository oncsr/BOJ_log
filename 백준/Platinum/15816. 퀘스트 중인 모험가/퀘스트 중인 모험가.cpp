#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set OS;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		OS.insert(a);
	}

	int M;
	for (cin >> M; M--;) {
		int o, a, b;
		cin >> o >> a;
		if (o == 1) { OS.insert(a); continue; }
		cin >> b;
		cout << b-a+1 - OS.order_of_key(b + 1) + OS.order_of_key(a) << '\n';
	}


}