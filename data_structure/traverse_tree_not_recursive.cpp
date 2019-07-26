# include <bits/stdc++.h>
using namespace std;

const int STACK_SIZE = 50;

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *createBinaryTree()
{
	TreeNode *root;
	int val;
	cin >> val;

	if(val == 0) root = NULL;
	else 
	{
		root = new TreeNode(val);
		root -> val = val;
		root -> left = createBinaryTree();
		root -> right = createBinaryTree();
	}
	return root;
}

typedef struct StackTree
{
	int top; // index of top element
	TreeNode *arr[STACK_SIZE];
}StackTree;

void InitStack(StackTree * S)
{
	S -> top = 0;
}

void Push(StackTree *S, TreeNode *node)
{
	int top_new = S -> top;
	if(node -> val == 0) return;
	else
	{
		S -> arr[top_new++] = node;
		S -> top++;
	}
}

int Pop(StackTree *S)
{
	if(S -> top == 0)
	{
		return 0;
	}
	else
	{
		--(S -> top);
		return 1;
	}
}

TreeNode *GetTop(StackTree *S)
{
	int top = S -> top;
	TreeNode *p;
	p = S -> arr[top];
	return p;
}

int isEmpty(StackTree *S)
{
	return (S -> top == 0 ? 1 : 0);
}

void preOrderNotRecursive(TreeNode *p)
{
	if(p)
	{
		StackTree stree;
		InitStack(&stree);
		TreeNode *root = p;
		while(root != NULL || !isEmpty(&stree))
		{
			while(root != NULL)
			{
				cout << root -> val << " ";
				Push(&stree, root);
				root = root -> left;
			}

			if(!isEmpty(&stree))
			{
				root = GetTop(&stree);
				Pop(&stree);
				root = root -> right;
			}
		}
	}
}

int main()
{
	cout << "input the int value, 0 as null." << endl;
	TreeNode *root = createBinaryTree();
	preOrderNotRecursive(root);
	return 0;
}