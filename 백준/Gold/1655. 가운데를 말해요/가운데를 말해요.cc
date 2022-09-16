#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<> > Q1;	// 오름차순
	priority_queue<int> Q2;								// 내림차순
	int N;
	cin >> N;
	int mid;
	while (N--) {
		int a;
		cin >> a;
		if (Q2.empty())
			Q2.push(a);
		else {
			if (a > Q2.top()) {
				if (Q2.size() == Q1.size()) {
					if (a > Q1.top()) {
						int g = Q1.top();
						Q2.push(g);
						Q1.pop();
						Q1.push(a);
					}
					else
						Q2.push(a);
				}
				else
					Q1.push(a);
			}
			else {
				if (Q2.size() == Q1.size())
					Q2.push(a);
				else {
					int g = Q2.top();
					Q2.pop();
					Q1.push(g);
					Q2.push(a);
				}
			}
		}
		cout << Q2.top() << '\n';
	}
}