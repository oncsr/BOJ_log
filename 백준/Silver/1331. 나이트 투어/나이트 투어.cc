#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char t1, t2;
	bool r = true;
	int visit[6][6] = { 0 };
	int sum = 0;
	char stx, sty, edx, edy;
	for (int i = 0; i < 36; i++) {
		char a, b;
		cin >> a >> b;
		if (visit[a - 'A'][b - '1'] == 0) {
			visit[a - 'A'][b - '1']++;
			sum++;
		}
		if (i == 0) {
			t1 = a;
			t2 = b;
			stx = a;
			sty = b;
			continue;
		}
		if (i == 35) {
			edx = a;
			edy = b;
		}
		int f = abs(a - t1);
		int g = abs(b - t2);
		if (f == 0 || g == 0 || f + g != 3)	r = false;
		t1 = a;
		t2 = b;
	}
	int f = abs(edx - stx);
	int g = abs(edy - sty);
	if (f == 0 || g == 0 || f + g != 3)	r = false;
	cout << (r && sum == 36 ? "Valid" : "Invalid") << '\n';
}