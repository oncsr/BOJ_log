#include <iostream>
using namespace std;

/*
* 2022.11.15
* [used algorithm]
* =>
* [point]
* =>
*/

int visit[9]{};
int N, M;

void R(int n, string ans) {
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i]++;
			char t = i + '0';
			string temp = "";
			temp += t;
			temp += ' ';
			if (n < M)	R(n + 1, ans + temp);
			else {
				cout << ans + temp << '\n';
			}
			visit[i]--;
		}
	}
}

void solve() {
	R(1, "");
}

int main() {
	cin >> N >> M;
	solve();
}