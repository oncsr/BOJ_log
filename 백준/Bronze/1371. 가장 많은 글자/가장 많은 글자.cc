#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int arr[26]{}, mx = 0;
	while (getline(cin, a)) {
		for (auto& i : a) {
			if (i == ' ')	continue;
			arr[i - 'a']++;
			mx = max(arr[i - 'a'], mx);
		}
	}
	for (int i = 0; i < 26; i++)
		if (arr[i] == mx)	cout << (char)(i + 'a');
}