#include <iostream>
using namespace std;

int main() {
	int h, w, map[100]{}, s = 0;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < w; j++) {
			if (!i) {
				if (a[j] == '.')	continue;
				if (a[j] == '/')	map[j] = 3, s++;
				if (a[j] == '\\')	map[j] = 1, s++;
			}
			else {
				if (a[j] == '.') {
					if (map[j] == 0)	continue;
					else if (map[j] == 3 || map[j] == 1)	map[j] = 3, s += 2;
					else if (map[j] == 2)	map[j] = 0;
				}
				if (a[j] == '/') {
					if (map[j] == 0)	map[j] = 3;
					else if (map[j] == 3 || map[j] == 1)	map[j] = 0;
					else if (map[j] == 2)	map[j] = 3;
					s++;
				}
				if (a[j] == '\\') {
					if (map[j] == 0)	map[j] = 1;
					else if (map[j] == 3 || map[j] == 1)	map[j] = 2;
					s++;
				}
			}
		}
	}
	cout << s / 2;
}