#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q, a, s = 0;
	bool arr[200001]{};
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		if ((i % 10) % 3 == 1)	arr[i] = 1, s++;
	}
	for (; Q--;) {
		cin >> a;
		if (arr[a])	s--;
		else	s++;
		arr[a] ^= 1;
		cout << s << '\n';
	}
}