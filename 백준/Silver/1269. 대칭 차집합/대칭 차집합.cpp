#include <iostream>
#include <set>
using namespace std;

int main() {
	////////////////////////////
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	///////////////////////////
	cin.tie(0)->sync_with_stdio(0);
	///////////////////////////

	set<int> A;
	set<int> B;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.insert(a);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (A.count(a) == 1)	cnt++;
	}

	cout << N + M - 2 * cnt;

}