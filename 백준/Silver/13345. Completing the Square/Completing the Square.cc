#include <iostream>
using namespace std;
struct dot {
	int x, y;
};
int main() {
	dot arr[3]{};
	int d[3]{};
	for (int i = 0; i < 3; i++)	cin >> arr[i].x >> arr[i].y;
	for (int i = 0; i < 3; i++) {
		d[i] += (arr[i].x - arr[(i + 1) % 3].x) * (arr[i].x - arr[(i + 1) % 3].x);
		d[i] += (arr[i].y - arr[(i + 1) % 3].y) * (arr[i].y - arr[(i + 1) % 3].y);
	}
	if (d[0] == d[1]) {
		cout << arr[0].x + arr[2].x - arr[1].x << ' ';
		cout << arr[0].y + arr[2].y - arr[1].y;
	}
	else if (d[1] == d[2]) {
		cout << arr[0].x + arr[1].x - arr[2].x << ' ';
		cout << arr[0].y + arr[1].y - arr[2].y;
	}
	else {
		cout << arr[1].x + arr[2].x - arr[0].x << ' ';
		cout << arr[1].y + arr[2].y - arr[0].y;
	}
}