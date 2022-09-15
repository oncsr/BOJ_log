#include <iostream>
#include <string>
using namespace std;

int main() {
	string c;
	int result = 0;
	for (int i = 0; i < 8; i++) {
		cin >> c;
		for (int j = i%2; j < 8; j += 2)
			if (c[j] == 'F')
				result++;
	}
	cout << result << '\n';
}