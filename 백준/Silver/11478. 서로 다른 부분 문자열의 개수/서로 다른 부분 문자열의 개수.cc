#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	set<string> S;
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		string temp = "";
		for (int j = i; j < a.size(); j++) {
			temp += a[j];
			S.insert(temp);
		}
	}
	cout << S.size();
}