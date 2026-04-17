#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string A;
	int B, C;
	cin >> A >> B;
	C = B;
	vector<int> ord(A.size());
	iota(ord.begin(), ord.end(), 0);
	do {
		if (A[ord[0]] == '0')	continue;
		string t = "";
		for (int i = 0; i < A.size(); i++)	t += A[ord[i]];
		int temp = stoi(t);
		if (temp <= B) {
			if (C == B)	C = temp;
			else	C = max(C, temp);
		}
	} while (next_permutation(ord.begin(), ord.end()));
	cout << (C == B ? -1 : C);

}