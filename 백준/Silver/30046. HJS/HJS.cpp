#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	string P, Q, R;
	string yes = "HJS! HJS! HJS!";
	string no = "Hmm...";
	cin >> N >> P >> Q >> R;
	int i = 0;
	for (; i < N; i++) {
		if (P[i] == Q[i] && Q[i] == R[i])	continue;
		break;
	}
	if (i == N) {
		cout << no;
		return 0;
	}

	if (P[i] == Q[i] && Q[i] != R[i]) {
		int j = i;
		for (; j < N; j++) {
			if (P[j] == Q[j])	continue;
			break;
		}
		if (j == N) {
			cout << no;
			return 0;
		}
		if (P[j] == R[i] && Q[j] == Q[i])	cout << no;
		else	cout << yes;
	}
	else if (P[i] != Q[i] && Q[i] == R[i]) {
		int j = i;
		for (; j < N; j++) {
			if (Q[j] == R[j])	continue;
			break;
		}
		if (j == N) {
			cout << no;
			return 0;
		}
		if (Q[j] == Q[i] && R[j] == P[i])	cout << no;
		else	cout << yes;
	}
	else if (P[i] == R[i] && P[i] != Q[i]) {
		cout << no;
	}
	else {
		cout << yes;
	}
}