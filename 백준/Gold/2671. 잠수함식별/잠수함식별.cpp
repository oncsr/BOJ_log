#include <iostream>
#include <regex>
using namespace std;

int main() {
	regex r("((100+1+)|(01))+");
	string s;
	cin >> s;
	cout << (regex_match(s, r) ? "SUBMARINE" : "NOISE");
}