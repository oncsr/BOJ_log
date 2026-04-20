#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int W, L, N, a;
	cin >> W >> L >> N;
	set<vector<pair<int, int>>> CHK;
	int cnt = 0;
	for (int i = 0; i < N; i++) {

		vector<int> arr;
		for (int j = 0; j < L; j++) {
			cin >> a;
			arr.emplace_back(W - a);
		}
		cin >> a;
		int pos = a;
		int pos2 = arr[0];
		vector<pair<int, int>> V, X, Y, XY;
		V.emplace_back(a - pos, arr[0] - a);
		X.emplace_back(W - arr[0] - pos2, arr[0] - a);
		for (int j = 1; j < L; j++) {
			cin >> a;
			V.emplace_back(a - pos, arr[j] - a);
			X.emplace_back(W - arr[j] - pos2, arr[j] - a);
		}

		Y = V, XY = X;
		reverse(Y.begin(), Y.end());
		reverse(XY.begin(), XY.end());
		int gap1 = Y[0].first, gap2 = XY[0].first;
		for (int j = 0; j < L; j++) {
			Y[j].first -= gap1;
			XY[j].first -= gap2;
		}

		if (CHK.count(V) || CHK.count(X) || CHK.count(Y) || CHK.count(XY))	continue;
		CHK.insert(V);
		CHK.insert(X);
		CHK.insert(Y);
		CHK.insert(XY);

		cnt++;
	}
	cout << cnt;
}