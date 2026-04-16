#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FenwickTree {
	vector<int> tree;
public:
	FenwickTree(int sz) {
		tree.resize(sz + 1);
	}

	void update(int x) {
		for (; x < tree.size(); x += x & -x) tree[x]++;
	}

	int find(int x) {
		int ret = 0;
		for (; x > 0; x -= x & -x) ret += tree[x];
		return ret;
	}
};

int N;
vector<pair<int, int>> infos;
FenwickTree* seg;

ll process(int coef) {
	if (coef > 0) {
		sort(infos.begin(), infos.end(), greater<>());
	}
	else {
		sort(infos.begin(), infos.end());
	}
	seg = new FenwickTree(N);

	ll ret = 0;
	for (auto [val, idx] : infos) {
		int cur = seg->find(idx);
		int low = 1, high = idx, mid = (low + high) >> 1;
		while (low < high) {
			if (cur - seg->find(mid - 1)) {
				low = mid + 1;
			}
			else {
				high = mid;
			}
			mid = (low + high) >> 1;
		}
		ll le = idx - mid + 1;

		cur = seg->find(idx - 1);
		low = idx, high = N, mid = (low + high + 1) >> 1;
		while (low < high) {
			if (seg->find(mid) - cur) {
				high = mid - 1;
			}
			else {
				low = mid;
			}
			mid = (low + high + 1) >> 1;
		}
		ll ri = mid - idx + 1;

		ret += le * ri * val * coef;

		seg->update(idx);
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1, a; i <= N; i++) {
		cin >> a;
		infos.emplace_back(a, i);
	}
	
	cout << process(-1) + process(1);

}