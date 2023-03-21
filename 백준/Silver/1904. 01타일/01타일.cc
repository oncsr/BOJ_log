#include <iostream>
using namespace std;

int main() {
	int N, s = 2, b = 1, a = 1;
	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		int temp = b;
		b = s;
		a = temp;
		s = (a + b) % 15746;
	}
		
	cout << s;
}