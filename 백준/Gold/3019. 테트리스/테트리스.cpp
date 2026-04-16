#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int info[100]{}, c, p;
	cin >> c >> p;
	for (int i = 0; i < c; i++)	cin >> info[i];

	int ans = 0;
	if (p == 1) {
		ans = c;
		for (int i = 0; i < c - 3; i++) {
			if (info[i] != info[i + 1])	continue;
			if (info[i + 1] != info[i + 2])	continue;
			if (info[i + 2] != info[i + 3])	continue;
			ans++;
		}
	}

	if (p == 2) {
		for (int i = 0; i < c - 1; i++) {
			if (info[i] == info[i + 1])	ans++;
		}
	}

	if (p == 3) {
		for (int i = 0; i < c - 2; i++) {
			if (info[i] != info[i + 1])	continue;
			if (info[i + 1] + 1 != info[i + 2])	continue;
			ans++;
		}
		for (int i = 0; i < c - 1; i++) {
			if (info[i] - 1 == info[i + 1])	ans++;
		}
	}

	if (p == 4) {
		for (int i = 0; i < c - 2; i++) {
			if (info[i + 1] != info[i + 2])	continue;
			if (info[i + 1] + 1 != info[i])	continue;
			ans++;
		}
		for (int i = 0; i < c - 1; i++) {
			if (info[i] + 1 == info[i + 1])	ans++;
		}
	}

	if (p == 5) {
		for (int i = 0; i < c - 2; i++) {
			if (info[i] == info[i + 1] && info[i + 1] == info[i + 2])	ans++;
			if (info[i] == info[i + 1] + 1 && info[i + 1] + 1 == info[i + 2])	ans++;
		}
		for (int i = 0; i < c - 1; i++) {
			if (info[i] + 1 == info[i + 1])	ans++;
			if (info[i] - 1 == info[i + 1])	ans++;
		}
	}

	if (p == 6) {
		for (int i = 0; i < c - 2; i++) {
			if (info[i] == info[i + 1] && info[i + 1] == info[i + 2])	ans++;
			if (info[i] + 1 == info[i + 1] && info[i + 1] == info[i + 2])	ans++;
		}
		for (int i = 0; i < c - 1; i++) {
			if (info[i] - 2 == info[i + 1])	ans++;
			if (info[i] == info[i + 1])	ans++;
		}
	}

	if (p == 7) {
		for (int i = 0; i < c - 2; i++) {
			if (info[i] == info[i + 1] && info[i + 1] == info[i + 2])	ans++;
			if (info[i + 2] + 1 == info[i + 1] && info[i + 1] == info[i])	ans++;
		}
		for (int i = 0; i < c - 1; i++) {
			if (info[i] + 2 == info[i + 1])	ans++;
			if (info[i] == info[i + 1])	ans++;
		}
	}

	cout << ans;

}