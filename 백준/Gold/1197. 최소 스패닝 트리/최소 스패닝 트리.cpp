#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N값으로 크기 조정해
#define N 300000
constexpr ll MST_FAIL = -9e18;

int root[N]{};
vector<tuple<ll, int, int>> E;

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

// MST의 가중치 합 반환, MST_FAIL이면 생성 실패
ll create_MST(int n, int m) {
	for (int i = 1; i <= n; i++)	root[i] = i;

	// 간선 입력받기
	for (; m--;) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		E.push_back({ c,a,b });
	}
	sort(E.begin(), E.end());

	int cnt = 0;	// MST 간선 개수
	ll sum = 0;

	// 크루스칼 알고리즘
	for (auto &e : E) {
		ll cost = get<0>(e);
		int a = get<1>(e), b = get<2>(e);

		int x = find(a), y = find(b);
		if (x == y)	continue;
		root[x] = y;
		sum += cost;
		cnt++;
		if (cnt == n - 1)	break;
	}

	if (cnt != n - 1)	return MST_FAIL;
	return sum;

}

int main() {

	// 그래프의 모든 간선 집합 {가중치, 정점1, 정점2}
	vector<tuple<int, int, int>> E;
	int n, m;
	cin >> n >> m;

	cout << create_MST(n, m);
	
	
}