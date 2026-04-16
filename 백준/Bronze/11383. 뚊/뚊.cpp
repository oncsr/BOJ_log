#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, r = 1;
	cin >> N >> M;
	string arr[10]{};
	for (int i = 0; i < N; i++) {
		string s, t = "";
		cin >> s;
		for (char j : s)	t += j, t += j;
		arr[i] = t;
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		r &= arr[i] == s;
	}
	cout << (r ? "Eyfa" : "Not Eyfa");

}