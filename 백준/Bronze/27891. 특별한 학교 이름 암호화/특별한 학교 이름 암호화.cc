#include <iostream>
using namespace std;

int main() {
	string a = "northlondo";
	string b = "branksomeh";
	string c = "koreainter";
	string d = "stjohnsbur";
	string e;
	cin >> e;
	for (int i = 0; i < 26; i++) {
		if (e == a) {
			cout << "NLCS";
			return 0;
		}
		if (e == b) {
			cout << "BHA";
			return 0;
		}
		if (e == c) {
			cout << "KIS";
			return 0;
		}
		if (e == d) {
			cout << "SJA";
			return 0;
		}
		for (int j = 0; j < 10; j++) {
			e[j]++;
			if (e[j] > 122)	e[j] = 97;
		}
	}
}