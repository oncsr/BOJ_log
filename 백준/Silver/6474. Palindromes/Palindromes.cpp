#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	map<char, char> M;
	string t = "AHIMOTUVWXY18";
	for (char i : t)	M[i] = i;
	M['E'] = '3', M['3'] = 'E';
	M['J'] = 'L', M['L'] = 'J';
	M['S'] = '2', M['2'] = 'S';
	M['Z'] = '5', M['5'] = 'Z';
	while (cin >> a) {
		int s = 0, e = a.size() - 1;
		bool is_mirror = true, is_palindrome = true;
		while (s <= e) {
			char left = a[s], right = a[e];
			if (left != right)	is_palindrome = false;
			if (!M[left] || (M[left] != right))	is_mirror = false;
			s++, e--;
		}
		cout << a << " -- ";
		if (is_mirror) {
			if (is_palindrome)
				cout << "is a mirrored palindrome.\n";
			else
				cout << "is a mirrored string.\n";
		}
		else {
			if (is_palindrome)
				cout << "is a palindrome.\n";
			else
				cout << "is not a palindrome.\n";
		}
		cout << '\n';
	}
}