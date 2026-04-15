#include <iostream>
#include <vector>
using namespace std;

int N, in[500001]{}, out[500001]{}, rev[500001]{}, seg[1048577]{};
int ord = 0, cent = 1, cur = -1;
vector<vector<int>> V(500001);
int sp[500001][19]{};

void SPT() {
	for (int k = 1; k < 19; k++) for (int i = 1; i <= N; i++) sp[i][k] = sp[sp[i][k - 1]][k - 1];
}

void ETT(int n) {
	in[n] = ++ord;
	rev[ord] = n;
	for (int i : V[n]) ETT(i);
	out[n] = ord;
}

void upt(int s, int e, int i, int n, int x) {
	if (s == e) {
		seg[n]++;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m) upt(s, m, i, n * 2, x);
	else upt(m + 1, e, i, n * 2 + 1, x);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 2, a; i <= N; i++) {
		cin >> a;
		V[a].push_back(i);
		sp[i][0] = a;
	}

	SPT();
	ETT(1);

	for (int i = 1; i <= N; i++) {
		upt(1, N, in[i], 1, i);
		int cnt = find(1, N, in[cent], out[cent], 1);
		if (in[cent] <= in[i] && out[i] <= out[cent]) {
			int temp = i;
			for (int k = 18; sp[temp][0] != cent && k >= 0; k--) {
				int start = in[sp[temp][k]];
				if (in[cent] <= start && start <= out[cent] && sp[temp][k] != cent) {
					temp = sp[temp][k];
				}
			}
			int tempcnt = find(1, N, in[temp], out[temp], 1);
			if (tempcnt > i / 2) cent = temp;
		}
		else {
			if (2 * (i - cnt) >= i) cent = sp[cent][0];
		}
		cout << cent << ' ';
	}

}