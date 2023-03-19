#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;

	int arr[26]{};
	for (char i : s)	arr[i - 'a']++;
	for (int i = 0; i < 26; i++)	cout << arr[i] << ' ';
}