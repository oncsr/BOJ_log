#include <bits/stdc++.h>
using namespace std;

int root[100001]{}, cnt[100001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, s = 0;
	cin >> N;
	char a;
	for (; N--;)	cin >> a, s += a - 'A' + 1;
	cout << s;

}