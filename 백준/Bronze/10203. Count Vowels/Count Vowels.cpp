#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	for (cin >> n; n--;) {
		string a;
		cin >> a;
		int s = 0;
		for (char i : a)
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
				s++;
		cout << "The number of vowels in " << a << " is " << s << ".\n";
	}
}