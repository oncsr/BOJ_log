#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int toint(string c) {
	int s = 0, g = 1;
	for (int j = c.size() - 1; j >= 0; j--) {
		s += (c[j] - '0') * g;
		g *= 10;
	}
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string sen;
	getline(cin, sen);
	vector<int> arr;
	string temp = "";
	for (char i : sen) {
		if (i == ' ') {
			arr.push_back(toint(temp));
			temp = "";
			continue;
		}
		temp += i;
	}
	arr.push_back(toint(temp));
	sort(arr.begin(), arr.end());
	int c;
	cin >> c;
	vector<pair<int, int>> V;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] + arr[j] == c) {
				V.push_back({ arr[i], arr[j] });
			}
		}
	}
	V.erase(unique(V.begin(), V.end()), V.end());
	for (pair<int, int> i : V)	cout << i.first << ' ' << i.second << '\n';
	cout << V.size();
}