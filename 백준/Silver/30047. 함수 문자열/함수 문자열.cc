#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

string S;
int id = 0, N;

int F();
int G();

int F() {
	int s = 0;
	char ch1 = S[id];
	id++;
	if (id == N)	return -1;
	if (ch1 == 'x')	s = 0;
	else if (ch1 == 'f')	s = F();
	else	s = G();

	if (id >= N)	return -1;

	int t = 0;
	char ch2 = S[id];
	id++;
	if (ch2 == 'x')	t = 0;
	else {
		if (id == N)	return -1;
		if (ch2 == 'f')	t = F();
		else	t = G();
	}

	return min(s, t);
}

int G() {
	int s = 0;
	char ch = S[id];
	id++;
	if (ch == 'x')	s = 0;
	else {
		if (id == N)	return -1;
		if (ch == 'f')	s = F();
		else	s = G();
	}
	if (s == -1)	return -1;
	return s + 1;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> S;
	N = S.size();

	int start = S[0], ans = 0;
	id++;
	if (start == 'x')	ans = 0;
	else {
		if (id == N) {
			cout << -1;
			return 0;
		}
		if (start == 'f')	ans = F();
		else	ans = G();
	}
	if (id < N)	cout << -1;
	else	cout << ans;

}