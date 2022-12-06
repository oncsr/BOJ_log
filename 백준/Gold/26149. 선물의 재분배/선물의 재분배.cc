#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;
bool cmp(ii a, ii b) {
	if (a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
}
bool cmp2(int a, int b) { return a > b; }
struct node {
	char op;
	int p, q;
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a[200000]{}, c[200000]{};
	ii b[200000]{};
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> a[i];
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		b[i] = { c[i], i };
	}
	sort(b, b + N, cmp);

	int id = b[0].second;
	vector<node> ans;

	vector<int> temp;
	for (int i = 0; i < N; i++) {
		if (i == id)	continue;
		temp.push_back(a[i]);
	}
	sort(temp.begin(), temp.end(), cmp2);
	for (int i : temp) {
		if (i == 0)	break;
		ans.push_back({ '+',id + 1,i });
	}

	for (int i = 0; i < N; i++) {
		if (i == id)	continue;
		if (c[i] == 0)	continue;
		ans.push_back({ '+', i + 1, c[i] });
	}

	cout << ans.size() << '\n';
	for (node i : ans)
		cout << i.op << ' ' << i.p << ' ' << i.q << '\n';
}