#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	cout << "int a;\n";
	string a = "int ";
	string b = "ptr";
	string c = " = &";
	for (int i = 1; i <= N; i++) {
		cout << a;
		for (int j = 0; j < i; j++)cout << '*';
		cout << b;
		if (i != 1)cout << i;
		cout << c;
		if (i == 1)cout << 'a';
		else {
			cout << b;
			if (i - 1 != 1)cout << i - 1;
		}
		cout << ";\n";
	}
}