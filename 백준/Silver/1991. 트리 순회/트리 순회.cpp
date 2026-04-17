#include <bits/stdc++.h>
using namespace std;

vector<char> L(126, -1), R(126, -1);
string pre = "", in = "", post = "";

void dfs(char a) {
	pre += a;
	if (L[a] != '.')	dfs(L[a]);
	in += a;
	if (R[a] != '.')	dfs(R[a]);
	post += a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		char A, B, C;
		cin >> A >> B >> C;
		L[A] = B, R[A] = C;
	}
	dfs('A');
	cout << pre << '\n' << in << '\n' << post;
}