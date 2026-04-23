#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	string m[100]{};
	for (int i = 0; i < N; i++)	cin >> m[i];
	bool suc = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (m[i][j] != m[j][i]) {
				suc = false;
				break;
			}
	}
	cout << (suc ? "YES" : "NO");
}