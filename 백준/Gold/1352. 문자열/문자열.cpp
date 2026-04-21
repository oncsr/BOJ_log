#include <bits/stdc++.h>
using namespace std;

string S = "";
int N;

string make(vector<int> L) {
	string a = "";
	int i = 0, pos = 0;
	int arr[26]{};
	char ch = 'B', add = 'A';
	while (a.size() < N) {
		if (i < L.size() && L[i] - 1 == a.size()) {
			a += add;
			arr[add - 'A']++;
			add++;
			i++;
		}
		else {
			a += ch;
			arr[ch - 'A']++;
			if (arr[ch - 'A'] == L[ch - 'A'])	ch++;
		}
	}
	return a;
}

void solve(int n, vector<int> L, int k) {
	if (n < 0)	return;
	if (n == 0) {
		string a = make(L);
		if (S == "")	S = a;
		else if (a < S)	S = a;
		return;
	}
	int last = L.back();
	if (n < last + 1)	return;
	if (n <= last + k + 1) {
		L.push_back(n);
		solve(0, L, k + last);
		return;
	}
	for (int i = last + 1; i <= last + k + 1; i++) {
		// i를 추가하겠다.
		L.push_back(i);
		solve(n - i, L, k + last);
		L.pop_back();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	solve(N - 1, { 1 }, 0);
	if (S == "")	cout << -1;
	else	cout << S;
}