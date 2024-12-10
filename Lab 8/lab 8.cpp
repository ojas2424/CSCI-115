#include <iostream>

using namespace std;

class Node {
public:
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	};
	int data;
	Node* left;
	Node* right;
};

class BstModule {
public:
	Node* root;
	BstModule() {
		root = NULL;
	}

	~BstModule() {
	}
	Node* makeEmpty(Node* t) {
		if (t == NULL)
			return NULL;
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;
	}

	Node* getRoot() { return this->root; };

	void postOrder(Node* treeNode) {
		if (treeNode == NULL)
			return;
		postOrder(treeNode->left);
		postOrder(treeNode->right);
		cout << treeNode->data << " ";
	}

	void printTree() {
		postOrder(root);
		cout << "exiting print tree " << endl;
	};

	Node* insert(int nodeData, Node* root)
	{
		if (root == NULL) {
			root = new Node(nodeData);
		}
		else if (nodeData < root->data)
			root->left = insert(nodeData, root->left);
		else if (nodeData > root->data)
			root->right = insert(nodeData, root->right);

		return root;
	}

	void InsertNode(int x) {
		root = insert(x, root);
	}

	bool isNodePresent(int data, Node* root) {
		if (root == NULL)
			return false;

		else if (data < root->data)
			return isNodePresent(data, root->left);
		else if (data > root->data)
			return isNodePresent(data, root->right);
		else
			return true;
	}

	bool FindNode(int data) {
		return isNodePresent(data, root);
	}


	int Largest(Node* root) {
		if (root == NULL)
			return -1;
		else if (root->right == NULL) {
			cout << "get left data as right null " << root->data << endl;
			return root->data;
		}
		else {
			cout << "get right data  " << root->right->data << endl;
			return Largest(root->right);
		}
	}

	int getMaxvalFromBST() {
		cout << "inside getMaxvalFromBST" << endl;
		return Largest(root);
	}
};

int main() {
	BstModule BStree;

	BStree.InsertNode(6);
	BStree.InsertNode(21);
	BStree.InsertNode(4);
	BStree.InsertNode(15);
	BStree.InsertNode(203);
	BStree.InsertNode(17);
	BStree.printTree();
	cout << endl;

	BStree.InsertNode(19);

	BStree.printTree();
	int largest = BStree.getMaxvalFromBST();
	cout << "Largest key " << largest << endl;

	cout << "Is node having data equals to 203 present in BSt:  " << (BStree.FindNode(203) == 1 ? "true" : "false") << endl;


}