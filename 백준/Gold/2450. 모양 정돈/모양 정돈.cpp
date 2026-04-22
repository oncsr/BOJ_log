#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		a += d == 1;
		b += d == 2;
		c += d == 3;
		arr[i] = d;
	}
	int one = 0, two = 0, thr = 0;
	for (int i = 0; i < a; i++) {
		two += arr[i] == 2;
		thr += arr[i] == 3;
	}
	int cnt = two + thr;

	int ccnt = cnt;
	for (int i = a; i < a + b; i++) {
		if (arr[i] == 1) {
			if (two)	two--;
			else	cnt++;
			continue;
		}
		if (arr[i] == 2)	continue;
		cnt++;
	}
	int mn = cnt;

	cnt = ccnt;
	for (int i = a; i < a + c; i++) {
		if (arr[i] == 1) {
			if (thr)	thr--;
			else	cnt++;
			continue;
		}
		if (arr[i] == 3)	continue;
		cnt++;
	}
	mn = min(mn, cnt);

	one = 0, two = 0, thr = 0;
	for (int i = 0; i < b; i++) {
		one += arr[i] == 1;
		thr += arr[i] == 3;
	}
	cnt = one + thr;

	ccnt = cnt;
	for (int i = b; i < a + b; i++) {
		if (arr[i] == 2) {
			if (one)	one--;
			else	cnt++;
			continue;
		}
		if (arr[i] == 1)	continue;
		cnt++;
	}
	mn = min(mn, cnt);

	cnt = ccnt;
	for (int i = b; i < c + b; i++) {
		if (arr[i] == 2) {
			if (thr)	thr--;
			else	cnt++;
			continue;
		}
		if (arr[i] == 3)	continue;
		cnt++;
	}
	mn = min(mn, cnt);

	one = 0, two = 0, thr = 0;
	for (int i = 0; i < c; i++) {
		one += arr[i] == 1;
		two += arr[i] == 2;
	}
	cnt = one + two;

	ccnt = cnt;
	for (int i = c; i < a + c; i++) {
		if (arr[i] == 3) {
			if (one)	one--;
			else	cnt++;
			continue;
		}
		if (arr[i] == 1)	continue;
		cnt++;
	}
	mn = min(mn, cnt);

	cnt = ccnt;
	for (int i = c; i < c + b; i++) {
		if (arr[i] == 3) {
			if (two)	two--;
			else	cnt++;
			continue;
		}
		if (arr[i] == 2)	continue;
		cnt++;
	}
	mn = min(mn, cnt);

	cout << mn;
}