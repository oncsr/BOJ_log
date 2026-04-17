#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set OS;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	vector<int> M(1000001);
	for (cin >> N; N--;) {
		char o;
		int a, b;
		cin >> o >> a;
		if (o == 'Q')	cout << (*OS.find_by_order(a - 1)).second << '\n';
		else {
			cin >> b;
			if (o == 'N')	OS.insert({ b,a }), M[a] = b;
			else {
				int temp = M[a];
				M[a] = b;
				OS.erase({ temp,a });
				OS.insert({ b,a });
			}
		}
	}

}