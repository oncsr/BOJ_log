#include <iostream>
using namespace std;

int main() {
	int n, tn = 0, ts = 0, now = 0, s = 0;
	string a;
	cin >> n >> a;
	char temp = '0';
	for (char i : a) {
		if (temp == '0') {
			temp = i;
			now++;
			continue;
		}
		if (i == temp)	now++;
		else {
			if (i == 'N') {
				ts = now;
			}
			else {
				tn = now;
			}
			now = 1;
			s = max(s, min(ts, tn) * 2);
		}
		temp = i;
	}
	if (temp == 'N')	tn = now;
	else	ts = now;
	s = max(s, min(ts, tn) * 2);
	cout << s;
}