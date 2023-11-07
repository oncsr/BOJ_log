#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int num = 2;
vector<ii> tree(23);
vector<int> arr(23);

void push(int v, int n) {

	if (!arr[n]) { arr[n] = v; return; }
	if (v < arr[n]) {
		if (!tree[n].first) {
			tree[n].first = num;
			arr[num] = v;
			num++;
			return;
		}
		push(v, tree[n].first);
	}
	else {
		if (!tree[n].second) {
			tree[n].second = num;
			arr[num] = v;
			num++;
			return;
		}
		push(v, tree[n].second);
	}

}
string way = "";
void find(int n) {
	if (tree[n].first) {
		way += 'L';
		find(tree[n].first);
		way += 'U';
	}
	if (tree[n].second) {
		way += 'R';
		find(tree[n].second);
		way += 'U';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	set<string> S;
	for (int i = 0; i < n; i++) {
		num = 2;
		tree = vector<ii>(23);
		arr = vector<int>(23);
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			push(a, 1);
		}
		way = "";
		find(1);
		S.insert(way);
	}
	cout << S.size();

}