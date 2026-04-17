#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int e[100001]{};
	for (int i = 2; i * i <= 100000; i++) {
		if (!e[i]) {
			for (int j = i * i; j <= 100000; j += i)	e[j] = 1;
		}
	}

	for (int i = 3, j = N; j > 0; i++) {
		if (!e[i])	cout << i << ' ', j--;
	}
}