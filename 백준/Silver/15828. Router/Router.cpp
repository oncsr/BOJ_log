#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, a = 0;
	queue<int> Q;
	for (cin >> N >> a; a != -1;) {
		if (a && Q.size() < N)	Q.push(a);
		else if (a == 0 && !Q.empty())	Q.pop();
		cin >> a;
	}
	if (Q.empty())	cout << "empty";
	else	for (; !Q.empty(); Q.pop())	cout << Q.front() << ' ';
}