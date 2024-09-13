#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N, arr[500][500]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++)	cin >> arr[i][j];

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	int d = 0, v = 1, c = 1;

	int x = (N + 1) >> 1, y = x;

	auto chk = [&](int x, int y) -> bool {
		return 1 <= x && x <= N && 1 <= y && y <= N;
	};

	int ans = 0;

	while (x != 1 || y != 1) {
		int xx = x + dx[d], yy = y + dy[d], s = arr[xx][yy], m = 0;
		arr[xx][yy] = 0;
		
		m += s / 100;
		m += s / 100;
		m += s * 7 / 100;
		m += s * 7 / 100;
		m += s / 50;
		m += s / 50;
		m += s / 10;
		m += s / 10;
		m += s / 20;

		int xxx = x + dx[(d + 1) % 4], yyy = y + dy[(d + 1) % 4];
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 100;
		else	ans += s / 100;
		xxx = x + dx[(d + 3) % 4], yyy = y + dy[(d + 3) % 4];
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 100;
		else	ans += s / 100;
		xxx = x + dx[d] + dx[(d + 1) % 4], yyy = y + dy[d] + dy[(d + 1) % 4];
		if (chk(xxx, yyy))	arr[xxx][yyy] += s * 7 / 100;
		else	ans += s * 7 / 100;
		xxx = x + dx[d] + dx[(d + 3) % 4], yyy = y + dy[d] + dy[(d + 3) % 4];
		if (chk(xxx, yyy))	arr[xxx][yyy] += s * 7 / 100;
		else	ans += s * 7 / 100;
		xxx = x + dx[d] + dx[(d + 1) % 4] * 2, yyy = y + dy[d] + dy[(d + 1) % 4] * 2;
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 50;
		else	ans += s / 50;
		xxx = x + dx[d] + dx[(d + 3) % 4] * 2, yyy = y + dy[d] + dy[(d + 3) % 4] * 2;
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 50;
		else	ans += s / 50;
		xxx = x + dx[d] * 2 + dx[(d + 1) % 4], yyy = y + dy[d] * 2 + dy[(d + 1) % 4];
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 10;
		else	ans += s / 10;
		xxx = x + dx[d] * 2 + dx[(d + 3) % 4], yyy = y + dy[d] * 2 + dy[(d + 3) % 4];
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 10;
		else	ans += s / 10;
		xxx = x + dx[d] * 3, yyy = y + dy[d] * 3;
		if (chk(xxx, yyy))	arr[xxx][yyy] += s / 20;
		else	ans += s / 20;
		xxx = x + dx[d] * 2, yyy = y + dy[d] * 2;
		if (chk(xxx, yyy))	arr[xxx][yyy] += s - m;
		else	ans += s - m;

		c--;
		if (!c) {
			d = (d + 1) % 4;
			if (d & 1 ^ 1)	v++;
			c = v;
		}

		x = xx, y = yy;

	}
	cout << ans;

}