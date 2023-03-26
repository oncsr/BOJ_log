#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	int arr[26]{};
	for (int i = 0; i < a.size(); i++) {
		char now = a[i];
		arr[now - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << arr[i] << ' ';
}