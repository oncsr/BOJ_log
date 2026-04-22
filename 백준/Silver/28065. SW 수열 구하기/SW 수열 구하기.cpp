#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;	cin >> N;
	int a = 1, b = N;
	for (int i = 0; i < N; i++) {
		if (i & 1)	cout << b-- << ' ';
		else	cout << a++ << ' ';
	}
}