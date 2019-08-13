# include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *right;
	struct TreeNode *left;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
	vector<int> res;
	if(!root) return res;
	TreeNode *cur, *pre;
	cur = root;

	while(cur)
	{
		if(cur -> left == NULL)
		{
			res.push_back(cur -> val);
			cur = cur -> right;
		}

		else if(cur -> left != NULL)
		{
			pre = cur -> left;
			while(pre -> right && pre -> right != cur) pre = pre -> right;
			if(pre -> right == NULL)
			{
				pre -> right = cur;
				cur = cur -> left;
			}
			else if(pre -> right != NULL)
			{
				pre -> right = NULL;
				res.push_back(cur -> val);
				cur = cur -> right;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> res;
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	node1 -> left = node2;
	node2 -> left = node3;
	node3 -> right = node4;
	inorderTraversal(node1);
	res = inorderTraversal(node1);
	vector<int>::iterator it;
	for(it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	delete node1; delete node2;
	delete node3; delete node4;
	return 0;
}

// 3 4 2 1