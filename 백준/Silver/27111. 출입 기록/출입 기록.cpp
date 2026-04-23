#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, c = 0, a, b;
	int s[200001]{}, e[200001]{};
	for (cin >> n; n--;) {
		cin >> a >> b;
		if (b) {
			if (s[a])	c++;
			else	s[a]++;
		}
		else {
			if (s[a])	s[a]--;
			else	c++;
		}
	}
	for (int i = 1; i <= 200000; i++)
		if (s[i])	c++;
	cout << c;
}