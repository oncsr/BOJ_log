#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, s, Q = 15000, p, next = 2;
	cin >> N >> s;
	int A[1001]{};	// 목걸이 A의 i번 보석의 종류 번호(1 ~ 26)
	A[1] = 1;
	vector<int> num1(27);	// 목걸이 A의 보석 종류 번호 중 대표 1개
	num1[1] = 1;

	int B[1001]{};
	B[1] = 1;
	vector<int> num2(27);
	num2[1] = 1;

	for (int i = 2; i <= N; i++) {

		for (int j = 1; j < next; j++) {
			cout << "? A " << num1[j] << " A " << i << endl;
			Q--;
			cin >> p;
			if (p) {
				A[i] = j;
				break;
			}
		}
		if (!A[i]) {
			num1[next] = i;
			A[i] = next++;
		}
	}
	int next2 = 2;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < next2; j++) {
			cout << "? B " << num2[j] << " B " << i << endl;
			Q--;
			cin >> p;
			if (p) {
				B[i] = j;
				break;
			}
		}
		if (!B[i]) {
			num2[next2] = i;
			B[i] = next2++;
		}
	}

	for (int i = 1; i < next; i++) {
		for (int j = 1; j < next2; j++) {
			cout << "? A " << num1[i] << " B " << num2[j] << endl;
			Q--;
			cin >> p;
			if (p) {
				cout << "! 1" << endl;
				return 0;
			}
		}
	}
	cout << "! 0" << endl;
	return 0;
}