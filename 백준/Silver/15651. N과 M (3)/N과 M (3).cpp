#include <iostream>
using namespace std;

/*
* 2022.11.15
* [used algorithm]
* => backtracking
* [point]
* => 이게 왜 되는거지???
*/

int visit[9]{};
int N, M;

void R(int n, string ans) {
	for (int i = 1; i <= N; i++) {
		char t = i + '0';
		string temp = "";
		temp += t;
		temp += ' ';
		if (n < M)	R(n + 1, ans + temp);
		else {
			cout << ans + temp << '\n';
		}
	}
}

int main() {
	cin >> N >> M;
	R(1, "");
}