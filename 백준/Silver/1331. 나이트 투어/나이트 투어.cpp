#include <iostream>
using namespace std;

int main() {
	char t1, t2;
	bool r = true;
	int visit[6][6] = { 0 };
	int sum = 1;
	char stx, sty, edx, edy;
	cin >> stx >> sty;
	t1 = stx, t2 = sty;
	for (int i = 0; i < 35; i++) {
		char a, b;
		cin >> a >> b;
		if (visit[a - 'A'][b - '1'] != 0) {
			cout << "Invalid";
			return 0;
		}
		visit[a - 'A'][b - '1']++;
		if (i == 34) {
			edx = a;
			edy = b;
		}
		int f = abs(a - t1);
		int g = abs(b - t2);
		if (f == 0 || g == 0 || f + g != 3) {
			cout << "Invalid";
			return 0;
		}
		t1 = a;
		t2 = b;
		sum++;
	}
	int f = abs(edx - stx);
	int g = abs(edy - sty);
	if (f == 0 || g == 0 || f + g != 3) {
		cout << "Invalid";
		return 0;
	}
	cout << (sum == 36 ? "Valid" : "Invalid");
}