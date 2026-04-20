#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	int cnt = 0;
	while (n) {
		string a = to_string(n);
		bool f = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '1') {
				a.erase(a.begin() + i);
				if (!a.empty())	n = stoi(a);
				else	n = 0;
				f = 1;
				break;
			}
		}
		if (!f)	n--;
		cnt++;
	}
	cout << cnt;

}