#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, a[100000]{}, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> a[i];
	sort(a, a + N);
	int st = 0, e = N - 1;
	while (st < e) {
		s += a[e] * 2;
		st++, e--;
	}
	if (st == e)	s += a[e];
	cout << s;
}