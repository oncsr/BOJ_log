#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	int arr[1002][1002]{};
	int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
	int dy[8] = { 1,0,-1,1,-1,1,0,-1 };
	for (int i = 1; i <= N; i++)	for (int j = 1; j <= N; j++) {
		char a;
		cin >> a;
		if (a == '.')	arr[i][j] = 0;
		else	arr[i][j] = a - '0';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j]) {
				cout << '*';
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < 8; k++)	cnt += arr[i + dx[k]][j + dy[k]];
			if (cnt > 9)	cout << 'M';
			else	cout << cnt;
		}
		cout << '\n';
	}

}