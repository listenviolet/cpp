# include <bits/stdc++.h>
using namespace std;

enum RBTColor{RED, BLACK};

struct RBTNode
{
	int val;
	RBTColor color;

	RBTNode *left;
	RBTNode *right;
	RBTNode *parent;

	// RBTNode(int v, RBTColor c): val(v), color(c), left(RBTree -> nil), right(RBTree -> nil), parent(RBTree -> nil) {}
	RBTNode(int v, RBTColor c): val(v), color(c), left(NULL), right(NULL), parent(NULL) {}

};

class RBTree
{
private:
	RBTNode *root;
	// RBTNode *nil;
public:
	RBTree(){};
	~RBTree(){};

	void setRoot(RBTNode *node)
	{
		this -> root = node;
	}

	RBTNode* getRoot()
	{
		return this -> root;
	}

// private:
	void leftRotate(RBTNode *&root, RBTNode *x);
	void rightRotate(RBTNode *&root, RBTNode *y);
	void RBTInsert(RBTNode *&root, RBTNode *z);
	void RBTInsertFixup(RBTNode *&root, RBTNode *z);
	// void display(RBTNode *root);

};

void display(RBTNode *root)
{
	cout << root -> val << " ";
	if(root -> left != NULL ) display(root -> left);
	if(root -> right != NULL) display(root -> right);
}

void RBTree::RBTInsert(RBTNode *&root, RBTNode *z)
{
	RBTNode *y = nullptr;
	RBTNode *x = root;
	while(x != NULL)
	{
		y = x;
		if(z -> val < x -> val)
		{
			x = x -> left;
		}
		else x = x -> right;
	}

	z -> parent = y;
	if(z -> parent == NULL) root = z;
	else if(z -> val < y -> val) y -> left = z;
	else y -> right = z;

	z -> color = RED;

	cout << "After insert before fix up:" << endl;
	display(root);
	cout << endl;
	RBTree::RBTInsertFixup(root, z);
}

void RBTree::RBTInsertFixup(RBTNode *&root, RBTNode *z)
{
	RBTNode *y = nullptr;
	while(z -> parent -> color == RED)
	{
		if(z -> parent == z -> parent -> parent -> left)
		{
			y = z -> parent -> parent -> right;

			if(y -> color == RED)
			{
				z -> parent -> color = BLACK;
				y -> color = BLACK;
				z -> parent -> parent -> color = RED;
				z = z -> parent -> parent;
				cout << "case 1:" << endl;
				display(root);
				cout << endl;
				continue;
			}

			if(z == z -> parent -> right)
			{
				z = z -> parent;
				RBTree::leftRotate(root, z);
				cout << "case 2:" << endl;
				display(root);
				cout << endl;
			}

			z -> parent -> color = BLACK;
			z -> parent -> parent -> color = RED;
			rightRotate(root, z -> parent -> parent);
			cout << "case 3:" << endl;
			display(root);
			cout << endl;

		}

	}

	root -> color = BLACK;
}

void RBTree::leftRotate(RBTNode *&root, RBTNode *x)
{
	RBTNode *y = nullptr;
	y = x -> right;
	x -> right = y -> left;
	if(y -> left != NULL) y -> left -> parent = x;

	y -> parent = x -> parent;
	if(x -> parent == NULL)
	{
		root = y;
	}

	else if(x -> parent -> left == x)
	{
		x -> parent -> left = y;
	}
	else x-> parent -> right = y;

	y -> left = x;
	x -> parent = y;
}

void RBTree::rightRotate(RBTNode *&root, RBTNode *y)
{
	RBTNode *x = nullptr;
	x = y -> left;
	y -> left = x -> right;

	if(x -> right != NULL) 
	{
		x -> right -> parent = y;
	}

	x -> parent = y -> parent;
	if(y -> parent == NULL) 
	{
		root = x;
	}
	else if(y -> parent -> left == y)
	{
		y -> parent -> left = x;
	}
	else
	{
		y -> parent -> right = x;
	}

	x -> right = y;
	y -> parent = x;
}


int main()
{

	RBTNode *node1 = new RBTNode(1, BLACK);
	RBTNode *node2 = new RBTNode(2, RED);
	RBTNode *node4 = new RBTNode(4, RED);
	RBTNode *node5 = new RBTNode(5, RED);
	RBTNode *node7 = new RBTNode(7, BLACK);
	RBTNode *node8 = new RBTNode(8, RED);

	RBTNode *node11 = new RBTNode(11, BLACK);
	RBTNode *node14 = new RBTNode(14, BLACK);
	RBTNode *node15 = new RBTNode(15, RED);

	node2 -> left = node1;
	node1 -> parent = node2;

	node2 -> right = node7;
	node7 -> parent = node2;

	node7 -> left = node5;
	node5 -> parent = node7;

	node7 -> right = node8;
	node8 -> parent = node7;

	// node5 -> left = node4;
	// node4 -> parent = node5;

	node11 -> left = node2;
	node2 -> parent = node11;

	node11 -> right = node14;
	node14 -> parent = node11;

	node14 -> right = node15;
	node15 -> parent = node14;

	RBTree *T = new RBTree();
	T -> setRoot(node11);
	RBTNode *root = T -> getRoot();

	cout << "Before insert node4:" << endl;
	display(T -> getRoot());
	cout << endl;

	cout << "After insert node4:" << endl;
	T -> RBTInsert(root, node4);
	T -> setRoot(root);
	display(T -> getRoot());


	// cout << "Before left rotate: " << endl;
	// // cout << "root = " << T -> getRoot() -> val << endl;

	// RBTNode *root = T -> getRoot();
	// T -> display(root);	
	// cout << endl;

	// cout << "After left rotate: " << endl;
	// T -> leftRotate(root, node2);
	// //cout << "root = " << T -> getRoot() -> val << endl;
	// T -> setRoot(root);
	// T -> display(T -> getRoot());
	// cout << endl;

	// cout << "After right rotate: " << endl;
	// T -> rightRotate(root, node11);
	// //cout << "root = " << T -> getRoot() -> val << endl;
	// T -> setRoot(root);
	// T -> display(T -> getRoot());
	// cout << endl;


	delete node1;
	delete node2;
	delete node4;
	delete node5;
	delete node7;
	delete node8;
	delete node11;
	delete node14;
	delete node15;
	
	delete T;
	
	return 0;
}