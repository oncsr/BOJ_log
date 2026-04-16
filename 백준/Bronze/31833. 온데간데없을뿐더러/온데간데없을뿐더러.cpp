#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	string a = "", b = "", c;
	for (int i = 0; i < N; i++) {
		cin >> c;
		a += c;
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		b += c;
	}
	if (a.size() < b.size())	cout << a;
	else if (a.size() > b.size())	cout << b;
	else {
		int i = 0;
		while (i < a.size()) {
			if (a[i] == b[i]) { i++; continue; }
			if (a[i] < b[i])	return cout << a, 0;
			return cout << b, 0;
		}
		cout << a;
	}
}