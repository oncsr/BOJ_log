#include <iostream>
using namespace std;

int main() {
	int N, s = 1;
	cin >> N;
	for (int i = 2; i <= N; i++)	s *= i;
	cout << s;
}