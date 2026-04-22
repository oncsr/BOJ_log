#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[256]{}, N, M, B, a, Time = 0, Break = 0, CNT = 0, Stack = 0;
	cin >> N >> M >> B;
	for (int i = 0; i < N * M; i++) {
		cin >> a;
		arr[a]++;
		Break += a;
	}
	CNT = N * M;
	B += Break;
	Time = Break * 2;
	int ans = Time, H = 0;
	for (int i = 1; i <= 256; i++) {
		CNT -= arr[i - 1];
		Break -= CNT;
		Stack += (N * M - CNT);
		B -= N * M;
		Time = Break * 2 + Stack;
		if (B < 0)	break;
		if (Time <= ans) {
			ans = Time;
			H = i;
		}
	}
	cout << ans << ' ' << H;
}