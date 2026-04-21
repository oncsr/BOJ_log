#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

struct cmp {
	bool operator()(ii b, ii a) {
		if (a.second == b.second)	return a.first < b.first;
		return a.second < b.second;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int L[300000]{}, R[300000]{};
	vector<tuple<int, int, int>> V;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		V.push_back({ s,1,i + 1 });
		V.push_back({ e + 1,-1,i + 1 });
	}
	sort(V.begin(), V.end());
	int mx = 1, cnt = 1, temp = get<0>(V[0]);
	int pos = 1;
	while (pos < V.size()) {
		while (pos < V.size() && temp == get<0>(V[pos]))	cnt += get<1>(V[pos++]);
		if (pos == V.size())	break;
		mx = max(mx, cnt);
		temp = get<0>(V[pos]);
	}
	cout << mx << '\n';

	int ans[300002]{};
	cnt = 1, temp = get<0>(V[0]), pos = 1;
	bool trig = 0;
	ans[get<2>(V[0])] = 1;
	while (pos < V.size()) {
		while (pos < V.size() && temp == get<0>(V[pos])) {
			int g = get<1>(V[pos]);
			if (g == 1)	ans[get<2>(V[pos])] = 1;
			else	ans[get<2>(V[pos])] = 0;
			cnt += g;
			if (cnt == mx) {
				trig = 1;
				break;
			}
			pos++;
		}
		if (pos == V.size())	break;
		if (trig)	break;
		temp = get<0>(V[pos]);
	}

	for (int i = 1; i <= N; i++)	if (ans[i])	cout << i << ' ';
}