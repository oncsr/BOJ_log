#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzz";
	string A[20];
	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> A[i];
		string a = "";
		for (int j = 0; j < C; j++) {
			if (A[i][j] == '#') {
				if (a.size() > 1 && a < ans) ans = a;
				a = "";
			}
			else a += A[i][j];
		}
		if (a.size() > 1 && a < ans) ans = a;
	}
	
	for (int j = 0; j < C; j++) {
		string a = "";
		for (int i = 0; i < R; i++) {
			if (A[i][j] == '#') {
				if (a.size() > 1 && a < ans) ans = a;
				a = "";
			}
			else a += A[i][j];
		}
		if (a.size() > 1 && a < ans) ans = a;
	}
	cout << ans;

}