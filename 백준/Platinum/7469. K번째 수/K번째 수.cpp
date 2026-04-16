#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, A[100000]{};
vector<vector<int>> B;
const int sz = 400;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	B.resize(N / sz + 1);
	for (int i = 0; i < N; i++) cin >> A[i], B[i / sz].push_back(A[i]);
	for (auto &i : B) sort(i.begin(), i.end());

	for (int a, b, c; M--;) {
		cin >> a >> b >> c;
		a--, b--;
		int st = a / sz, ed = b / sz;
		int s = -1e9, e = 1e9, m = (s + e + 1) >> 1;
		while (s < e) {
			int l = 0;
			for (int j = a % sz; j < sz; j++) {
				if (st*sz + j > b) break;
				if (A[st*sz + j] < m) l++;
			}
			if (st != ed) for (int j = 0; j <= b%sz; j++) {
				if (A[ed*sz + j] < m) l++;
			}
			for (int j = st + 1; j < ed; j++) l += lower_bound(B[j].begin(), B[j].end(), m) - B[j].begin();

			if (l < c) s = m;
			else e = m - 1;
			m = (s + e + 1) >> 1;
		}
		cout << m << '\n';
	}

}