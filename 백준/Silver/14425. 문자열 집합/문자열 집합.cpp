#include <iostream>
#include <set>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	set<string> A;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		A.insert(a);
	}

	int answer = 0;
	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		if (A.count(a))	answer++;
	}

	cout << answer;

}