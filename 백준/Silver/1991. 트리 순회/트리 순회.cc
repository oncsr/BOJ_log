#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, char> > V(27);

void preorder(char i) {
	cout << i;
	if (V[i-64].first != '.')
		preorder(V[i-64].first);
	if (V[i-64].second != '.')
		preorder(V[i-64].second);
}

void inorder(char i) {
	if (V[i - 64].first != '.')
		inorder(V[i - 64].first);
	cout << i;
	if (V[i - 64].second != '.')
		inorder(V[i - 64].second);
}

void postorder(char i) {
	if (V[i - 64].first != '.')
		postorder(V[i - 64].first);
	if (V[i - 64].second != '.')
		postorder(V[i - 64].second);
	cout << i;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		V[a - 64] = { b,c };
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}