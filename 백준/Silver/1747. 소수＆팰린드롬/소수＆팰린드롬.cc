#include <iostream>
#include <string>
using namespace std;
using ll = long long;

bool pal(int a) {
	string s = to_string(a);
	int st = 0, ed = s.size() - 1;
	while (st <= ed)
		if (s[st++] != s[ed--])	return false;
	return true;
}

int main() {
	int e[1000001] = { 0,1, }, n, f = 0;
	cin >> n;
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * 2; j <= 1000000; j += i)
				e[j]++;
	
	for (int i = n; i <= 1000000; i++) {
		if (!e[i] && pal(i)) {
			cout << i;
			f++;
			break;
		}
	}
	if (!f)	cout << 1003001;
}