#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define yes true
#define no false

int main() {
	int N;
	cin >> N;
	vector<vector<string> > Cow(N);
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			string a;
			cin >> a;
			Cow[i].push_back(a);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			set<string> onA;
			for (string A : Cow[i]) {
				onA.insert(A);
			}
			set<string> onB;
			for (string B : Cow[j]) {
				if (onA.count(B))	onA.erase(B);
				else	onB.insert(B);
			}

			for (int k = 0; k < N; k++) {
				if (k == i || k == j)	continue;
				int aa = 0, bb = 0;
				for (string C : Cow[k]) {
					if (onA.count(C))	aa++;
					if (onB.count(C))	bb++;
				}
				if (aa && bb) {
					cout << "no";
					return 0;
				}
			}
		}
	}
	cout << "yes";
}