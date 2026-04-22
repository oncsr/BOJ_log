#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	char arr[100][100][100]{};
	int r, c, h, ans[100][100][100]{};
	int dx[26] = { 1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int dy[26] = { 1,0,-1,1,0,-1,1,0,-1,1,0,-1,1,-1,1,0,-1,1,0,-1,1,0,-1,1,0,-1 };
	int dz[26] = { -1,-1,-1,0,0,0,1,1,1,-1,-1,-1,0,0,1,1,1,-1,-1,-1,0,0,0,1,1,1 };
	
	cin >> r >> c >> h;
	vector<pair<int, pair<int, int>>> Q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++) {
				cin >> arr[j][k][i];
				if (arr[j][k][i] == '*')	Q.push_back({ j,{k,i} });
			}
	for (auto s : Q) {
		int x = s.first, y = s.second.first, z = s.second.second;
		for (int i = 0; i < 26; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int zz = z + dz[i];
			if (xx >= 0 && xx < r && yy >= 0 && yy < c && zz >= 0 && zz < h) {
				ans[xx][yy][zz]++;
				ans[xx][yy][zz] %= 10;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (arr[j][k][i] == '*')	cout << '*';
				else	cout << ans[j][k][i];
			}
			cout << '\n';
		}
	}
}