#include <iostream>
using namespace std;

int main() {
	int N, L[50]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> L[i];
	int s = N - 1 + L[0];
	for (int i = 1; i < N; i++) {
		if (L[i] > L[i - 1]) {
			s += L[i] - L[i - 1];
		}
	}
	cout << s;
}