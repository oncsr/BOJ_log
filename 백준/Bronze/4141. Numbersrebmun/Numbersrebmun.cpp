#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[26]{};
	for (int i = 0; i < 26; i++) {
		if(i < 18)	arr[i] = i / 3 + 2;
		else {
			if (i == 18)	arr[i] = i / 3 + 1;
			else if (i == 21)	arr[i] = i / 3 + 1;
			else if (i > 23)	arr[i] = i / 3 + 1;
			else	arr[i] = i / 3 + 2;
		}
	}
	int N;
	for (cin >> N; N--;) {
		string a;
		cin >> a;
		int s = 0, e = a.size() - 1, f = 1;
		
		while (s <= e) {
			char aa = a[s] >= 97 ? a[s] - 'a' : a[s] - 'A';
			char bb = a[e] >= 97 ? a[e] - 'a' : a[e] - 'A';
			if (arr[aa] != arr[bb]) {
				f = 0;
				cout << "NO\n";
				break;
			}
			s++, e--;
		}
		if (f)	cout << "YES\n";
	}
}