#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1000001];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	stack<int> S;
	vector<int> ans;
	ans.push_back(-1);
	S.push(arr[n]);
	for (n--; n > 0;n--) {
		if (arr[n] >= S.top()) {
			while (!S.empty() && arr[n] >= S.top())
				S.pop();
			if (S.empty())
				ans.push_back(-1);
			else
				ans.push_back(S.top());
		}
		else
			ans.push_back(S.top());
		S.push(arr[n]);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	cout << '\n';
}