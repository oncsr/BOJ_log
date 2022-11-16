#include <iostream>
#include <vector>
using namespace std;

int visit[13]{};
int N;
int arr[13]{};

void R(int n, vector<int> ans) {
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			if (ans.empty() || ans.back() < arr[i]) {
				visit[i]++;
				ans.push_back(arr[i]);
				if (n < 6)	R(n + 1, ans);
				else {
					for (int i : ans)	cout << i << ' ';
					cout << '\n';
				}
				visit[i]--;
				ans.pop_back();
			}
		}
	}
}

int main() {
	cin >> N;
	while (N) {
		vector<int> a;
		for (int i = 0; i < N; i++)	cin >> arr[i];
		R(1, a);
		cout << '\n';
		cin >> N;
	}
}