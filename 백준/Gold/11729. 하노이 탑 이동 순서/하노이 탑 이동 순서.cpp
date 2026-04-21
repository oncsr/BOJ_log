#include <bits/stdc++.h>
using namespace std;

void Hanoi(int n, int now, int target, int checkpoint) {
	if (n == 1) {
		cout << now << ' ' << target << '\n';
		return;
	}
	Hanoi(n - 1, now, checkpoint, target);
	Hanoi(1, now, target, checkpoint);
	Hanoi(n - 1, checkpoint, target, now);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	cout << (1 << N) - 1 << '\n';
	Hanoi(N, 1, 3, 2);

}