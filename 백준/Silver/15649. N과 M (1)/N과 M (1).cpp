#include <iostream>
#include <vector>
using namespace std;

int visit[9]{};
int N, M;

void R(int n, vector<int> ans) {
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i]++;
			ans.push_back(i);
			if (n < M)	R(n + 1, ans);
			else {
				for (int i : ans)	cout << i << ' ';
				cout << '\n';
			}
			visit[i]--;
			ans.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	vector<int> a;
	R(1, a);
}