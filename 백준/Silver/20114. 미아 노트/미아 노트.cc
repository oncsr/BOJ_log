#include <iostream>
using namespace std;

int main() {
	int n, h, w;
	cin >> n >> h >> w;
	string m[10]{};
	for (int i = 0; i < h; i++)	cin >> m[i];
	for (int i = 0; i < n; i++) {
		char ch = '?';
		for (int j = 0; j < h; j++) {
			for (int k = i * w; k < (i + 1) * w; k++) {
				if (m[j][k] != '?')	ch = m[j][k];
			}
		}
		cout << ch;
	}
}