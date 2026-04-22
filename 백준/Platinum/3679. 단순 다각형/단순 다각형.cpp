#include <bits/stdc++.h>
using namespace std;

// BOJ 3679
// convex hull
// ㅅ@ㅂ 반례가 뭘까 도대체

#define x first
#define y second
using ii = pair<int, int>;
vector<ii> arr;
int ccw(ii a, ii b) {
	ii P = { a.x - arr[0].x, a.y - arr[0].y };
	ii Q = { b.x - a.x,b.y - a.y };
	return P.x * Q.y - P.y * Q.x;
}
bool cmp(ii a, ii b) {
	int num = ccw(a, b);
	if (num > 0)	return true;
	if (num < 0)	return false;
	int dist_a = (a.x - arr[0].x) * (a.x - arr[0].x) + (a.y - arr[0].y) * (a.y - arr[0].y);
	int dist_b = (b.x - arr[0].x) * (b.x - arr[0].x) + (b.y - arr[0].y) * (b.y - arr[0].y);
	return dist_a < dist_b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		arr = vector<ii>(n);
		map<ii, int> M;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].x >> arr[i].y;
			M[arr[i]] = i;
		}
		sort(arr.begin(), arr.end());
		sort(arr.begin() + 1, arr.end(), cmp);
		int p1 = n - 1, p2 = n - 2;
		if (ccw(arr[p1], arr[p2]) == 0) {
			p1--, p2--;
			while (ccw(arr[p1], arr[p2]) == 0)	p1--, p2--;
		}
		for (int i = 0; i < p1; i++)
			cout << M[arr[i]] << ' ';
		for (int i = n - 1; i >= p1; i--)
			cout << M[arr[i]] << ' ';
		cout << '\n';
	}
}