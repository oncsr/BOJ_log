#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int arr[100]{}, box[4]{}, ball[10]{}, ans = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	fill(ball, ball + 10, -1);
	fill(box, box + 4, -1);
	for (int i = 0; i < n; i++) {
		int a = arr[i];
		if (ball[a] != -1)	continue;
		ans++;
		int fir[4]{};
		fill(fir, fir + 4, n + 1);
		int flag = 0;
		for (int j = 0; j < 4; j++) {
			if (box[j] == -1) {
				box[j] = a;
				ball[a] = j;
				flag = 1;
				break;
			}
			int now = box[j];
			for (int k = n - 1; k > i; k--) {
				if (arr[k] == now)	fir[j] = k;
			}
		}
		if (flag)	continue;
		int p = max_element(fir, fir + 4) - fir;
		int orig = box[p];
		ball[orig] = -1;
		box[p] = a;
		ball[a] = p;
	}
	cout << ans;

}