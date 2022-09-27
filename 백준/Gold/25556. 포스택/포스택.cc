#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a;
	bool suc = true;
	cin >> n;
	int V[4]{};
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (!V[0])	V[0] = a;
		else if (a > V[0]) V[0] = a;
		else {
			if (!V[1])	V[1] = a;
			else if (a > V[1])	V[1] = a;
			else {
				if (!V[2])	V[2] = a;
				else if (a > V[2])	V[2] = a;
				else {
					if (!V[3])	V[3] = a;
					else if (a > V[3])	V[3] = a;
					else {
						suc = false;
						break;
					}
				}
			}
		}
	}
	cout << (suc ? "YES" : "NO");
}