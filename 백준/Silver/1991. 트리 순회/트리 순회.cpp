#include <iostream>
using namespace std;
#define left first
#define right second

pair<char, char> Tree[27];
int N;

void preorder(char node) {
	if (node == '.')	return;
	cout << node;
	int temp = node - 'A';
	preorder(Tree[temp].left);
	preorder(Tree[temp].right);
}

void inorder(char node) {
	if (node == '.')	return;
	int temp = node - 'A';
	inorder(Tree[temp].left);
	cout << node;
	inorder(Tree[temp].right);
}

void postorder(char node) {
	if (node == '.')	return;
	int temp = node - 'A';
	postorder(Tree[temp].left);
	postorder(Tree[temp].right);
	cout << node;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		int x = a - 'A';
		Tree[x] = { b,c };
	}

	preorder('A');
	cout << '\n';

	inorder('A');
	cout << '\n';

	postorder('A');
	cout << '\n';

}