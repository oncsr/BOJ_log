#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<ii> ans;

void one_two(int a, int b);
void one_three(int a, int b);
void two_one(int a, int b);
void two_three(int a, int b);
void three_one(int a, int b);
void three_two(int a, int b);

void one_two(int a, int b) {
	if (a == b) {
		ans.push_back({ 1,2 });
		return;
	}
	if (a == b - 1) {
		ans.push_back({ 1,2 });
		ans.push_back({ 1,2 });
		return;
	}
	one_three(a + 1, b - 1);
	ans.push_back({ 1,2 });
	ans.push_back({ 1,2 });
	three_two(a + 1, b - 1);
}

void one_three(int a, int b) {
	if (a == b) {
		ans.push_back({ 1,3 });
		return;
	}
	if (a == b - 1) {
		ans.push_back({ 1,3 });
		ans.push_back({ 1,3 });
		return;
	}
	one_two(a + 1, b - 1);
	ans.push_back({ 1,3 });
	ans.push_back({ 1,3 });
	two_three(a + 1, b - 1);
}

void two_one(int a, int b) {
	if (a == b) {
		ans.push_back({ 2,1 });
		return;
	}
	two_three(a + 1, b);
	ans.push_back({ 2,1 });
	three_one(a + 1, b);
}

void two_three(int a, int b) {
	if (a == b) {
		ans.push_back({ 2,3 });
		return;
	}
	two_one(a, b - 1);
	ans.push_back({ 2,3 });
	one_three(a, b - 1);
}

void three_one(int a, int b) {
	if (a == b) {
		ans.push_back({ 3,1 });
		return;
	}
	three_two(a, b - 1);
	ans.push_back({ 3,1 });
	two_one(a, b - 1);
}

void three_two(int a, int b) {
	if (a == b) {
		ans.push_back({ 3,2 });
		return;
	}
	three_one(a + 1, b);
	ans.push_back({ 3,2 });
	one_two(a + 1, b);
}

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n1 3";
		return 0;
	}
	one_two(2, n);
	cout << ans.size() * 2 + 1 << '\n';
	for (ii now : ans)
		cout << now.first << ' ' << now.second << '\n';
	cout << 1 << ' ' << 3 << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) {
		int fir = ans[i].first;
		int sec = ans[i].second;
		if (sec == 1)	cout << 3 << ' ';
		else if (sec == 3)	cout << 1 << ' ';
		else	cout << sec << ' ';
		if (fir == 1)	cout << 3 << '\n';
		else if (fir == 3)	cout << 1 << '\n';
		else	cout << fir << '\n';
	}
}