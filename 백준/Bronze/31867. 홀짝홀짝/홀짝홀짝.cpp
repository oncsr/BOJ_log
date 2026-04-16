#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
    
	string n, s;
	cin >> n >> s;
	int odd = 0, even = 0;
	for (char i : s)	odd += (i % 2), even += ((i - 1) % 2);
	cout << (odd == even ? -1 : (odd > even ? 1 : 0));
}