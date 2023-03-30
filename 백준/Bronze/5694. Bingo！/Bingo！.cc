#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, B;
	for (cin >> N >> B; N != 0 && B != 0; cin >> N >> B) {
		int arr[91]{};
		for (int i = 0; i < B; i++)	cin >> arr[i];
		int chk[91]{};
		for (int i = 0; i < B; i++)
			for (int j = i + 1; j < B; j++)
				chk[abs(arr[i] - arr[j])]++;
		bool find = true;
		for (int i = 1; i <= N; i++) {
			if (!chk[i]) {
				cout << "N\n";
				find = false;
				break;
			}
		}
		if (find)	cout << "Y\n";
	}
}