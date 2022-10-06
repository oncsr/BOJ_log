#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(1001);
vector<long long> seg(2050);

long long find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

void upt(int s, int e, int id, int n) {
	if (s == e) {
		seg[n]++;
		return;
	}
	int m = (s + e) / 2;
	if (id <= m)	upt(s, m, id, n * 2);
	else	upt(m + 1, e, id, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T, N, M, K, a, b;	cin >> T;
	for (int g = 1; g <= T; g++) {
		V = vector<vector<int> >(1001);
		seg = vector<long long>(2049);
		cin >> N >> M >> K;
		for (int i = 1; i <= K; i++) {
			cin >> a >> b;
			V[b].push_back(a);
		}
		long long s = 0;
		for (int i = 1; i <= M; i++) {
			if (!V[i].empty()) {
				for (int next : V[i]) {
					s += find(1, 1000, next + 1, 1000, 1);
				}
				for (int next : V[i]) {
					upt(1, 1000, next, 1);
				}
			}
		}
		cout << "Test case " << g << ": " << s << '\n';
	}
}