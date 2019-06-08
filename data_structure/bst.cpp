#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *BSTSearch(TreeNode *root, int key)
{
	if(root == NULL) return NULL;
	if(root -> val == key) return root;
	if(root -> val > key) return BSTSearch(root -> left, key);
	if(root -> val < key) return BSTSearch(root -> right, key);
}

void CreateBST(TreeNode *&root, vector<int> pre)
{
	root = NULL;
	for(int i = 0; i < pre.size(); ++i)
	{
		BSTInsert(root, pre[i]);
	}
}

bool BSTInsert(TreeNode *&root, int key)
{
	if(root == NULL) 
	{
		TreeNode *root = new TreeNode(key);
		return true;
	}

	if(key == root -> val)
	{
		return false;
	}  

	if(key > root -> val)
	{
		return BSTInsert(root -> right, key);
	}

	if(key < root -> val)
	{
		return BSTInsert(root -> left, key);
	}
}

int main()
{

}