#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;
#define x first
#define y second

int N;
ii dot[100000]{};

bool cmp(ii a, ii b) {
	if (a.second == b.second)	return a.first < b.first;
	return a.second < b.second;
}

int dist(ii a, ii b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int solve(int s, int e) {
	if (e - s == 1)	return dist(dot[s], dot[e]);
	if (e - s == 2)	return min({ dist(dot[s], dot[e]), dist(dot[s], dot[s + 1]), dist(dot[s + 1],dot[e]) });
	int m = (s + e) >> 1;
	int left = solve(s, m), right = solve(m + 1, e);
	int mn = min(left, right);

	vector<ii> L, R;

	// 왼쪽 탐색
	for (int i = m; i >= s; i--) {
		int temp = dot[m + 1].first - dot[i].first;
		if (temp * temp >= mn)	break;
		L.push_back(dot[i]);
	}
	for (int i = m + 1; i <= e; i++) {
		int temp = dot[i].first - dot[m].first;
		if (temp * temp >= mn)	break;
		R.push_back(dot[i]);
	}
	int LL = L.size(), RR = R.size();
	if (!(LL && RR))	return mn;

	sort(L.begin(), L.end(), cmp);
	sort(R.begin(), R.end(), cmp);

	int pol = 0, por = 0;
	int ch = R.back().second;
	for (; pol < LL; pol++) {
		if (por == RR)	break;

		int temp = L[pol].second - ch;
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
	cout << solve(0, N - 1);
}