#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, s = 0;
	string arr[100]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < i; j++) {
			string a = "", b = "", c = "", d = "";
			for (int k = 0; k < min(arr[i].size(), arr[j].size()); k++) {
				a = arr[i][arr[i].size() - 1 - k] + a;
				b += arr[j][k];
				c = arr[j][arr[j].size() - 1 - k] + c;
				d += arr[i][k];
				if (a == b || c == d) {
					s++;
					break;
				}
			}
		}
	}
	cout << s;
}