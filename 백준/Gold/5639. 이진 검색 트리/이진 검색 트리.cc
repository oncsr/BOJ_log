#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

bool isLeft(Node* v) {
	if (v->left != NULL)
		return true;
	else
		return false;
}

bool isRight(Node* v) {
	if (v->right != NULL)
		return true;
	else
		return false;
}

void insert(Node* v, int x) {
	if (x < v->data) {
		if (isLeft(v))
			insert(v->left, x);
		else {
			Node* temp = (Node*)malloc(sizeof(*temp));
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			v->left = temp;
		}
	}
	else {
		if (isRight(v))
			insert(v->right, x);
		else {
			Node* temp = (Node*)malloc(sizeof(*temp));
			temp->data = x;
			temp->left = NULL;
			temp->right = NULL;
			v->right = temp;
		}
	}
}

void postorder(Node* v) {
	if (isLeft(v))
		postorder(v->left);
	if (isRight(v))
		postorder(v->right);
	cout << v->data << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	if (cin.eof() != 1) {
		Node* root = (Node*)malloc(sizeof(root));
		root->data = n;
		root->left = NULL;
		root->right = NULL;
		cin >> n;
		while (cin.eof() != 1) {
			insert(root, n);
			cin >> n;
		}
		postorder(root);
	}
}