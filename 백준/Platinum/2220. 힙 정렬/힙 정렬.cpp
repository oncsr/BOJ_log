#include <iostream>
#include <queue>
using namespace std;

int tree[100001] = { 0,2,1 };

void S(int n) {
	if (n == 1)	return;
	swap(tree[n], tree[n / 2]);
	S(n / 2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	if (N <= 2) {
		for (; N--;)	cout << N + 1 << ' ';
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		S(i - 1);
		swap(tree[1], tree[i]);
		tree[1] = i;
	}
	for (int i = 1; i <= N; i++)	cout << tree[i] << ' ';

}