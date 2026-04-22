#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string a) {
	vector<string> res;
	string temp = "";
	for (char now : a) {
		if (now == ' ') {
			if (temp != "") {
				res.push_back(temp);
				temp = "";
			}
			continue;
		}
		temp += now;
	}
	res.push_back(temp);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	getline(cin, a);
	vector<string> arr = split(a);
	int s = 0;
	for (string i : arr) {
		if (i == "[")	continue;
		if (i == "]")	s += 8;
		else if (i[0] - '0' < 10)	s += 8;
		else	s += i.size() + 12;
	}
	cout << s;
}