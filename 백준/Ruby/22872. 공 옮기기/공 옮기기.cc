#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define push(b,c)	ans.push_back({b,c})

int n;
vector<ii> ans;

void solve(int len, int s, int e, int f) {
	if (len <= 0)	return;
	int o = 6 - s - e;
	// 처음 1에서 시작하는 공들
	if (!f) {
		if (len == 1) {
			push(s, e);
			return;
		}
		if (len == 2) {
			push(s, e);
			push(s, e);
			return;
		}
		solve(len - 2, s, o, 0);
		push(s, e);
		push(s, e);
		solve(len - 2, o, e, 1);
		return;
	}

	// 짝 -> 짝
	// 이건 반만 구해서 뒤집은거 더하면 됨
	int id = ans.size();
	if (len == 1) {
		push(s, e);
		return;
	}
	if (len == 2) {
		push(s, o);
		push(s, e);
	}
	else if (len == 3) {
		push(s, e);
		push(s, o);
		push(e, o);
		push(s, e);
	}
	else if (len == 4) {
		push(s, o);
		push(s, e);
		push(s, e);
		push(s, o);
		push(e, s);
		push(e, o);
		push(s, e);
	}
	else if (len == 5) {
		push(s, e);
		push(s, o);
		push(e, o);
		push(s, e);
		push(s, e);
		push(o, e);
		push(s, o);
		push(e, o);
		push(e, s);
		push(e, o);
		push(s, e);
	}
	else {
		for (int i = len - 3; i > 0;) {
			solve(i, s, o, 1);
			push(s, e);
			push(s, e);
			i--;
			// s에 하나 남은 경우
			if (!i) {
				push(s, o);
				push(e, s);
				push(e, o);
				push(s, e);
				break;
			}
			solve(i, o, e, 1);
			push(s, o);
			i--;
			// 3이 넘어온 경우
			if (!i) {
				push(e, o);
				push(e, s);
				push(e, o);
				push(s, e);
				break;
			}
			solve(i, e, o, 1);
			push(e, s);
			push(e, s);
			i--;
			// 반대1
			if (!i) {
				push(e, o);
				push(s, e);
				push(s, o);
				push(e, s);
				break;
			}
			solve(i, o, s, 1);
			push(e, o);
			i--;
			//"2
			if (!i) {
				push(s, o);
				push(s, e);
				push(s, o);
				push(e, s);
				break;
			}
		}
	}



	int now = ans.size() - 2;
	for (int i = now; i >= id; i--) {
		int fir = ans[i].second;
		if (fir == s)	fir = e;
		else if (fir == e)	fir = s;
		int sec = ans[i].first;
		if (sec == s)	sec = e;
		else if (sec == e)	sec = s;
		push(fir, sec);
	}
}

void print(bool r) {
	if (!r) {
		for (ii now : ans)
			cout << now.first << ' ' << now.second << '\n';
	}
	else {
		for (int i = ans.size() - 1; i >= 0; i--) {
			int fir = ans[i].second;
			if (fir == 1)	fir = 3;
			else if (fir == 3)	fir = 1;
			int sec = ans[i].first;
			if (sec == 1)	sec = 3;
			else if (sec == 3)	sec = 1;
			cout << fir << ' ' << sec << '\n';
		}
	}
}

int main() {
	cin >> n;
	
	solve(n - 1, 1, 2, 0);
	int s = ans.size() * 2 + 1;

	cout << s << '\n';
	print(0);
	cout << "1 3\n";
	print(1);

}