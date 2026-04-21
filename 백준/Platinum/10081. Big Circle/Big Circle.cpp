#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using dd = pair<ld, ld>;
#define x first
#define y second

int N;
dd dot[100000]{};

bool cmp(dd a, dd b) {
	if (a.second == b.second)	return a.first < b.first;
	return a.second < b.second;
}

ld dist(dd a, dd b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ld solve(int s, int e) {
	if (e - s == 1)	return dist(dot[s], dot[e]);
	if (e - s == 2)	return min({ dist(dot[s], dot[e]), dist(dot[s], dot[s + 1]), dist(dot[s + 1],dot[e]) });
	int m = (s + e) >> 1;
	ld left = solve(s, m), right = solve(m + 1, e);
	ld mn = min(left, right);

	vector<dd> L, R;

	// 왼쪽 탐색
	for (int i = m; i >= s; i--) {
		ld temp = dot[m + 1].first - dot[i].first;
		if (temp * temp >= mn)	break;
		L.push_back(dot[i]);
	}
	for (int i = m + 1; i <= e; i++) {
		ld temp = dot[i].first - dot[m].first;
		if (temp * temp >= mn)	break;
		R.push_back(dot[i]);
	}
	int LL = L.size(), RR = R.size();
	if (!(LL && RR))	return mn;

	sort(L.begin(), L.end(), cmp);
	sort(R.begin(), R.end(), cmp);

	int pol = 0, por = 0;
	ld ch = R.back().second;
	for (; pol < LL; pol++) {
		if (por == RR)	break;

		ld temp = L[pol].second - ch;
		if (temp > 0 && temp * temp >= mn)	break;

		for (int i = por; i < RR; i++) {

			temp = R[i].second - L[pol].second;
			if (temp > 0 && temp * temp >= mn)	break;

			temp = L[pol].second - R[i].second;
			if (temp < 0 && temp * temp >= mn) {
				por++;
				continue;
			}

			mn = min(mn, dist(L[pol], R[i]));
		}
	}

	return mn;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> dot[i].first >> dot[i].second;
	sort(dot, dot + N);

    cout.precision(2);
	cout << fixed << sqrt(solve(0, N - 1));
}