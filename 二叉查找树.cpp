#include <iostream>
using namespace std;
class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
		Node(int& x, Node* lf = NULL, Node* rt = NULL)
		{
			data = x;
			left = lf;
			right = rt;
		}
	};
	Node* root;
	void insert(int& x, Node*& t);
	int find(int& x, Node* t);
public:
	BinaryTree()
	{
		root = NULL;
	};
	int find(int& x);
	void insert(int& x);
};

int BinaryTree::find(int& x,Node *t)
{
	if (t != NULL)
	{
		if ((t->left != NULL && t->left->data == x) ||(t->right != NULL && t->right->data == x))
		return t->data;
	}
	if (x < t->data)
	{
		return find(x, t->left);
	}
	else return find(x, t->right);
}
int BinaryTree:: find(int &x)
{
	return find(x,root);
}
void BinaryTree::insert(int& x,Node *&t)
{
	if (t == NULL)
		t = new Node(x, NULL, NULL);
	else if (x < t->data)
		insert(x, t->left);
	else if (x > t->data)
		insert(x, t->right); 
	
}
void BinaryTree::insert(int &x)
{
	insert(x,root);
}
int main()
{
	BinaryTree Tree;
	int N,x;
	cin>>N;
	int key[N];
	
	for (int i=0;i<N;i++)
	{
		cin>>key[i];
		Tree.insert(key[i]);
	}
	cout<<"-1"<<endl;
	//cin>>x;
	//cout<<Tree.find(x);
	for (int i=1;i<N;i++)
	{
		cout<<Tree.find(key [i])<<endl;
	}
	return 0;
} 
