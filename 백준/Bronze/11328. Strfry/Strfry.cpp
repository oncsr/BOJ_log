#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		string a, b;
		cin >> a >> b;
		int arr[26]{}, find = 1;
		for (char i : a)	arr[i - 'a']++;
		for (char i : b)	arr[i - 'a']--;
		for (int i = 0; i < 26; i++) {
			if (arr[i]) {
				cout << "Impossible\n";
				find = 0;
				break;
			}
		}
		if (find)	cout << "Possible\n";
	}
}