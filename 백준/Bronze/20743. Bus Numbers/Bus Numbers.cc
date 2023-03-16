#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M;
	cin >> M;
	while (M > 1) {
		int count = 0;
		for (int i = 1; i * i * i <= M; i++)
			for (int j = 1; i * i * i + j * j * j <= M; j++)
				if (i * i * i + j * j * j == M)	count++;
		if (count > 3) {
			cout << M;
			return 0;
		}
		M--;
	}
	cout << "none";
}