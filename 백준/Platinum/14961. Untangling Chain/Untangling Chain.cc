#include <iostream>
using namespace std;

int main() {
	int N, max_up = 0, max_left = 0, max_right = 0, max_down = 0;
	int x = 0, y = 0, a, b, dir = 2, idx = 0, arr[10000]{};
	cin >> N;
	for (; N--;) {
		cin >> a >> b;
		if (dir == 1) {
			arr[idx++] = (++max_up - y);
			y += (max_up - y);
		}
		else if (dir == 2) {
			arr[idx++] = (++max_right - x);
			x += (max_right - x);
		}
		else if (dir == 3) {
			arr[idx++] = (++max_down + y);
			y -= (max_down + y);
		}
		else {
			arr[idx++] = (++max_left + x);
			x -= (max_left + x);
		}


		if (b == 1)	dir--;
		else if (b == -1)	dir++;
		if (!dir)	dir = 4;
		if (dir > 4)	dir = 1;
	}
	for (int i = 0; i < idx; i++)	cout << arr[i] << ' ';
}