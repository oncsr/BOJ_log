#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, temp;
	cin >> N >> temp;
	int s = 1;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		if (a >= temp)	s++;
		temp = a;
	}
	cout << s;
}