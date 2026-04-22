#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b, c = "";
	deque<char> B, C;
	cin >> a >> b;
	for (char i : b)	B.push_back(i);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < 60)	continue;
		C.push_back(a[i]);
		if (C.size() < B.size())	continue;
		if (C.size() > B.size())	C.pop_front();
		if (C == B) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}