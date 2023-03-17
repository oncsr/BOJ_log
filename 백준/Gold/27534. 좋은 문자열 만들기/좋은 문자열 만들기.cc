#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int t;
		cin >> t;
		string n;
		cin >> n;
		int zero_left = -1, zero_right = -1, one_left = -1, one_right = -1;
		for (int i = 0; i < t; i++) {
			if (n[i] == '0') {
				if (zero_left == -1)	zero_left = i;
				zero_right = i;
			}
			else {
				if (one_left == -1)	one_left = i;
				one_right = i;
			}
		}
		int zero, one;
		if (zero_left == -1)	zero = -1;
		else	zero = zero_right - zero_left;

		if (one_left == -1)	one = -1;
		else	one = one_right - one_left;

		
		if (t == 1 || t == 3)	cout << -1 << '\n';
		else {
			if (one == -1) {
				// 1이 없는 경우
				if (zero == 0)	cout << -1 << '\n';
				else if (zero == 1)	cout << 1 << '\n';
				else if (zero == 2)	cout << -1 << '\n';
				else	cout << 2 << '\n';
			}
			else if (zero == -1) {
				// 0이 없는 경우
				if (one == 0)	cout << -1 << '\n';
				else if (one == 1)	cout << 1 << '\n';
				else if (one == 2)	cout << -1 << '\n';
				else	cout << 2 << '\n';
			}
			else {
				// 둘 다 있는 경우
			
				// 구간이 겹치지 않는 경우
					// 0이 1보다 왼쪽인 경우
				if (zero_right < one_left) {
					if (zero == one)	cout << 0 << '\n';
					else if (abs(zero - one) <= 1)	cout << 2 << '\n';
					else	cout << 1 << '\n';
				}
				else if (one_right < zero_left) {
					if (zero == one)	cout << 0 << '\n';
					else if (abs(zero - one) <= 1)	cout << 2 << '\n';
					else	cout << 1 << '\n';
				}
				else {
					if (zero_left < one_left && one_right < zero_right) {
						// zero_left = 0, zero_right = t-1
						int temp1 = zero_right;
						while (zero_right--) {
							if (n[zero_right] == '0') {
								break;
							}
						}
						if (t - 1 - one_left == zero_right)	cout << 1 << '\n';
						else {
							zero_left++;
							for (;; zero_left++) {
								if (n[zero_left] == '0') {
									break;
								}
							}
							if (temp1 - zero_left == one_right)	cout << 1 << '\n';
							else	cout << 2 << '\n';
						}
					}
					else if (one_left < zero_left && zero_right < one_right) {
						int temp1 = one_right;
						while (one_right--) {
							if (n[one_right] == '1')	break;
						}
						if (t - 1 - zero_left == one_right)	cout << 1 << '\n';
						else {
							one_left++;
							for (;; one_left++) {
								if (n[one_left] == '1')	break;
							}
							if (temp1 - one_left == zero_right)	cout << 1 << '\n';
							else	cout << 2 << '\n';
						}
					}
					else {
						if (zero == one)	cout << 0 << '\n';
						else	cout << 1 << '\n';
					}
				}
			}

		}

	}
}