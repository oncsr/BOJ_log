#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[501][501]{}, H, W, ans = 0;
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)	arr[i][j] = 1;
	}

	for (int j = 0; j < H; j++) {
		int temp = -1;
		for (int i = 0; i < W; i++) {
			if (arr[i][j]) {
				if (temp != -1)	ans += (i - temp - 1);
				temp = i;
			}
		}
	}
	cout << ans;

}