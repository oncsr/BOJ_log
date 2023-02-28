#include <iostream>
using namespace std;

int main() {
	int arr[10]{}, L, a, temp = 0;
	bool suc = true;
	for (cin >> L, suc = (L > 2 && L < 10); L--;) {
		cin >> a;
		if (temp) {
			int mx = max(a, temp), mn = min(a, temp);
			if (mn == 2 && mx == 8 && !arr[5])	suc = 0;
			else if (mn == 4 && mx == 6 && !arr[5])	suc = 0;
			else if (mn == 1 || mn == 3) {
				if ((mx % 2) && mx != 5 && !arr[(mx + mn) / 2])	suc = 0;
			}
			else if (mn == 7 && mx == 9 && !arr[8])	suc = 0;
		}
		arr[a]++;
		if (arr[a] > 1)	suc = 0;
		temp = a;
	}
	cout << (suc ? "YES" : "NO");
}