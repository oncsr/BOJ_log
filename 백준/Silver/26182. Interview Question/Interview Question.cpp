#include <iostream>
#include <vector>
using namespace std;

string toString(int a) {
	string ans = "";
	int g = 10;
	while (a > 0) {
		int temp = a % g / (g / 10);
		a -= temp * (g / 10);
		char tmp = temp + '0';
		ans = tmp + ans;
		g *= 10;
	}
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int c, d, a, Fizz[100001]{}, Buzz[100001]{};
	int fizz = 0, buzz = 0, ans1 = 0, ans2 = 0;
	cin >> c >> d;
	for (int i = c; i <= d; i++) {
		string a;
		cin >> a;
		if (toString(i) == a)	continue;
		else {
			if (a == "Fizz") {
				if (!fizz)	fizz = i;
				else	ans1 = i - fizz;
				fizz = i;
			}
			else if (a == "Buzz") {
				if (!buzz)	buzz = i;
				else	ans2 = i - buzz;
				buzz = i;
			}
			else {
				if (!fizz)	fizz = i;
				else	ans1 = i - fizz;
				fizz = i;
				if (!buzz)	buzz = i;
				else	ans2 = i - buzz;
				buzz = i;
			}
		}
	}
	if (!ans1) {
		if (!fizz)	cout << d + 1 << ' ';
		else	cout << fizz << ' ';
	}
	else	cout << ans1 << ' ';
	if (!ans2) {
		if (!buzz)	cout << d + 1;
		else	cout << buzz;
	}
	else	cout << ans2;
}