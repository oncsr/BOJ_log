#include <iostream>
#include <map>
#include <stack>
using namespace std;

/*
 < 2022.03.20 >
 [used algorithm]
 > string
 [point]

*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b;
	cin >> a >> b;

	string ans = "";
	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
		if (ans.size() < b.size())	continue;
		string now = ans.substr(ans.size() - b.size(), b.size());
		if (now == b) {
			int g = b.size();
			while (g--)	ans.pop_back();
		}
	}
	cout << (ans == "" ? "FRULA" : ans);


}