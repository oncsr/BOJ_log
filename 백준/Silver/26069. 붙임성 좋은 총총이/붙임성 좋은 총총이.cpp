#include <iostream>
#include <map>
using namespace std;
int main() {
	map<string, bool> M;
	string a, b;
	int N, s = 1;
	for (cin >> N; N--;) {
		cin >> a >> b;
		if (!M[a] && !M[b]) {
			if (a == "ChongChong") {
				s++;
				M[b] = 1;
				M[a] = 1;
			}
			if (b == "ChongChong") {
				s++;
				M[a] = 1;
				M[b] = 1;
			}
		}
		else if (M[a] && M[b])	continue;
		else {
			M[a] = 1;
			M[b] = 1;
			s++;
		}
	}
	cout << s;
}