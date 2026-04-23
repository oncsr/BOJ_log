#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
	return a < b;
}

/*
* 2022.11.13
* [used algorithm]
* =>
* [point]
* =>
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<string, string> M;
	int N;
	cin >> N;
	string a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a.size() <= 3) {
			M[a] = a;
		}
		else {
			string temp = a;
			sort(a.begin() + 1, a.end() - 1);
			M[a] = temp;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a.size() <= 3)	cout << M[a] << ' ';
		else {
			sort(a.begin() + 1, a.end() - 1);
			cout << M[a] << ' ';
		}
	}
}