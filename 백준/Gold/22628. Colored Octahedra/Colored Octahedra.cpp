#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	map<string, int> color;
	map<vector<int>, bool> chk;
	int cnt = 1;
	vector<int> V;
	vector<int> ord = { 0, 1, 2, 3, 4, 5, 6, 7 };
	for (int i = 0; i < 8; i++) {
		string a;
		cin >> a;
		if (color.find(a) == color.end())	color[a] = cnt++;
		V.push_back(color[a]);
	}
	sort(V.begin(), V.end());
	int ans = 0;
	do {
		bool exist = 0;
		vector<int> R;
		for (int i = 0; i < 8; i++)	R.push_back(V[ord[i]]);

		exist |= chk.find(R) != chk.end();
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			exist |= chk.find(R) != chk.end();
		}
		reverse(R.begin(), R.end());
		exist |= chk.find(R) != chk.end();
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			exist |= chk.find(R) != chk.end();
		}

		R = { R[0], R[4], R[5], R[1], R[3], R[7], R[6], R[2] };

		exist |= chk.find(R) != chk.end();
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			exist |= chk.find(R) != chk.end();
		}
		reverse(R.begin(), R.end());
		exist |= chk.find(R) != chk.end();
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			exist |= chk.find(R) != chk.end();
		}

		if (exist)	continue;
		ans++;
		chk[R] = 1;
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			chk[R] = 1;
		}
		reverse(R.begin(), R.end());
		chk[R] = 1;
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			chk[R] = 1;
		}

		R = { R[0], R[4], R[5], R[1], R[3], R[7], R[6], R[2] };

		chk[R] = 1;
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			chk[R] = 1;
		}
		reverse(R.begin(), R.end());
		chk[R] = 1;
		for (int j = 0; j < 3; j++) {
			int temp1 = R[0], temp2 = R[4];
			R[0] = R[1], R[1] = R[2], R[2] = R[3], R[3] = temp1;
			R[4] = R[5], R[5] = R[6], R[6] = R[7], R[7] = temp2;
			chk[R] = 1;
		}

	} while (next_permutation(ord.begin(), ord.end()));

	cout << ans;
}