#include <iostream>
#include <algorithm>
using namespace std;
using node = pair<pair<double, int>, int>;
bool cmp(node a, node b) { return a.first.second < b.first.second; };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q;
	pair<double, double> dot[100000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> dot[i].first >> dot[i].second;
	sort(dot, dot + N);
	cin >> Q;
	node query[100000]{};
	for (int i = 0; i < Q; i++) {
		cin >> query[i].first.first;
		query[i].first.second = i;
	}
	sort(query, query + Q);
	for (int i = 0, id = 0; i < Q; i++) {
		while (query[i].first.first > dot[id + 1].first)	id++;
		if (dot[id].second > dot[id + 1].second)
			query[i].second = -1;
		else if (dot[id].second < dot[id + 1].second)
			query[i].second = 1;
		else
			query[i].second = 0;
	}
	sort(query, query + Q, cmp);
	for (int i = 0; i < Q; i++)	cout << query[i].second << '\n';
}