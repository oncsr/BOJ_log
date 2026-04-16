#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, K;
	string S;
	cin >> N >> K >> S;

	for (int i = 0; i < N; i++) {
		if (S[i] == 'A')	continue;
		int need = 'Z' - S[i] + 1;
		if (K >= need)	S[i] = 'A', K -= need;
		else	continue;
	}
	K %= 26;
	while (K--) {
		if (S[N - 1] == 'Z')	S[N - 1] = 'A';
		else	S[N - 1]++;
	}
	cout << S;

}