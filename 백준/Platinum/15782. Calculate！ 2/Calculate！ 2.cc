#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(100001);
int visit[100001] = { 0 };
pair<int, int> init[100001]{};
int tree[100001];
int segtree[262145] = { 0 };
int lazy[262145] = { 0 };
int real[100001];
int N, D, M, o, x, y, cnt = 0;

// 초기 순서 맞추기
void dfs(int node) {
	if (!visit[node]) {
		visit[node]++;
		cnt++;
		init[node].first = cnt;
		real[cnt] = tree[node];
		for (int i = 0; i < V[node].size(); i++)
			dfs(V[node][i]);
		init[node].second = cnt;
	}
}

// 초기화
void I(int start, int end, int node) {
	if (start == end) {
		segtree[node] = real[start];
		return;
	}
	int mid = (start + end) / 2;
	I(start, mid, node * 2);
	I(mid + 1, end, node * 2 + 1);
	segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

// 레이지 전이
void prop(int start, int end, int node) {
	if (lazy[node]) {
		if ((end - start + 1) % 2)	segtree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

// 자손 xor
void update(int start, int end, int left, int right, int val, int node) {
	prop(start, end, node);
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		if ((end - start + 1) % 2)	segtree[node] ^= val;
		if (start != end) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, left, right, val, node * 2);
	update(mid + 1, end, left, right, val, node * 2 + 1);
	segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

// 정답 출력
int find(int start, int end, int left, int right, int node) {
	prop(start, end, node);
	if (left > end || right < start)	return 0;
	if (left <= start && end <= right)	return segtree[node];
	int mid = (start + end) / 2;
	return find(start, mid, left, right, node * 2) ^ find(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
		cin >> tree[i];
	dfs(1);
	I(1, N, 1);
	while (M--) {
		cin >> o >> x;
		if (o == 1)	cout << find(1, N, init[x].first, init[x].second, 1) << '\n';
		else {
			cin >> y;
			update(1, N, init[x].first, init[x].second, y, 1);
		}
	}
}