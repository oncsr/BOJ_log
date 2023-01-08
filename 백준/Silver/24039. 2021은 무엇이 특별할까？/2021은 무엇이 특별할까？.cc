#include <iostream>
using namespace std;

int main() {
	int e[200]{}, n, sosu[200]{}, id = 0;
	for (int i = 2; i * i < 200; i++)
		if (!e[i]) {
			for (int j = i * 2; j < 200; j += i)
				e[j]++;
		}
	for (int i = 2; i < 200; i++)
		if (!e[i])
			sosu[id++] = i;
	cin >> n;
	for (int i = 0; i < id - 1; i++) {
		if (sosu[i] * sosu[i + 1] > n) {
			cout << sosu[i] * sosu[i + 1];
			break;
		}
	}
}