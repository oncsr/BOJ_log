
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, P, E;
int L[20]{}, R[20]{};
bool poss = 0;
int ans[20]{};

void bck(int pos, vector<int> sel, int low, int high) {
	if (pos == N) {
		if (sel.size() == P && low <= E && E <= high) {
			for (int i = 0; i < N; i++)	ans[i] = 0;
			poss = 1;
			int rem = E - low;
			for (int i : sel) {
				int g = min(rem, R[i] - L[i]);
				rem -= g;
				ans[i] = L[i] + g;
			}
		}
		return;
	}
	bck(pos + 1, sel, low, high);
	low += L[pos], high += R[pos];
	sel.push_back(pos);
	bck(pos + 1, sel, low, high);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> P >> E;
	for (int i = 0; i < N; i++)	cin >> L[i] >> R[i];

	bck(0, {}, 0, 0);
	if (!poss)	cout << -1;
	else	for (int i = 0; i < N; i++)	cout << ans[i] << ' ';

}