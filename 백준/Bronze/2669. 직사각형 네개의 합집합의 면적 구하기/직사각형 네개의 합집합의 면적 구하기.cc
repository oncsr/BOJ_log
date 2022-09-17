#include <iostream>
using namespace std;
bool map[101][101] = { false };
int main() {
	int n = 4;
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				map[i][j] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j])
				sum++;
	cout << sum << '\n';
}