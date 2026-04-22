#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	int arr[26]{};
	for (char i : a)	arr[i - 'a']++;
	for (char i : b)	arr[i - 'a']--;
	int s = 0;
	for (int i = 0; i < 26; i++)	s += abs(arr[i]);
	cout << s;
}