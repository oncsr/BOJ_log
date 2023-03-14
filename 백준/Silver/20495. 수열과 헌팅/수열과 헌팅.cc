#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	ii start[500000]{}, end[500000]{};	//	{ value, index }
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		start[i] = { a - b,i }, end[i] = { a + b,i };
	}
	sort(start, start + N);
	sort(end, end + N);

	ii ans[500000]{};

	int p = 0;
	for (int i = 0; i < N; i++) {
		int value = start[i].first;
		int id = start[i].second;
		while (p < N && value > end[p].first)	p++;
		ans[id].first = min(N, p + 1);
	}
	p = 0;
	for (int i = 0; i < N; i++) {
		int value = end[i].first;
		int id = end[i].second;
		while (p < N && value >= start[p].first)	p++;
		ans[id].second = p;
	}
	for (int i = 0; i < N; i++)	cout << ans[i].first << ' ' << ans[i].second << '\n';

}