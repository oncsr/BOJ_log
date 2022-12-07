#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	cout << (N == 1 ? 1 : 2 * N - 2) << '\n';
	for (int i = 1; i <= N; i++)	cout << "1 " << i << '\n';
	for (int i = 2; i < N; i++)	cout << N << ' ' << i << '\n';
}