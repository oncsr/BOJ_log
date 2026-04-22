#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string a;
	cin >> N >> a;
	for (int i = 0; i < a.size(); i++) {
		string t1 = a.substr(0, i + 1);
		string t2 = a.substr(a.size() - (i + 1), i + 1);
		int diff = 0;
		for (int j = 0; j < i + 1; j++) {
			if (t1[j] != t2[j])	diff++;
		}
		if (diff == 1) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}