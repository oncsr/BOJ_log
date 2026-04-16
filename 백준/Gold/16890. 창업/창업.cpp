#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string A, B;
	cin >> A >> B;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	int x = 1, m = A.size();
	string ans = "";
	for (int i = 0; i < m; i++)	ans.push_back('?');

	int s1 = 0, e1 = m - 1, s2 = 0, e2 = m - 1, s = 0, e = m - 1;

	int v1[300001]{}, v2[300001]{};
	while (m--) {
		char p = A[s1], q = B[s2];
		if (x) {
			int last = m >> 1;
			if (p >= q)	ans[e--] = A[s1 + last];	//
			else {
				ans[s++] = A[s1];
				while (v1[++s1]);
			}
		}
		else {
			int last = m >> 1;
			if (q <= p)	ans[e--] = B[s2 + last];	//
			else {
				ans[s++] = B[s2];
				while (v2[++s2]);
			}
		}

		x ^= 1;
	}
	cout << ans;


}