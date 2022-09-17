#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> seg(262145);
int tree[100001];
const int MX = 0, MN = 1000000001;

void init(int start, int end, int node) {
	if (start == end)	seg[node] = { tree[start], tree[start] };
	else {
		int mid = (start + end) / 2;
		init(start, mid, node * 2);
		init(mid + 1, end, node * 2 + 1);
		int mn = min(seg[node * 2].first, seg[node * 2 + 1].first);
		int mx = max(seg[node * 2].second, seg[node * 2 + 1].second);
		seg[node].first = mn;
		seg[node].second = mx;
	}
}

pii find(int start, int end, int left, int right, int node) {
	if (left > end || right < start)	return { MN,MX };
	if (left <= start && end <= right)	return seg[node];
	int mid = (start + end) / 2;
	pii t1 = find(start, mid, left, right, node * 2);
	pii t2 = find(mid + 1, end, left, right, node * 2 + 1);
	return { min(t1.first,t2.first),max(t1.second,t2.second) };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> tree[i];
	init(1, N, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		pii ans = find(1, N, a, b, 1);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}