#include <cstddef>
#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

class tree
{
private:
	struct Node
	{
		Node* firstson, * firstsib;
		int data;
		int number;
		Node() : firstson(NULL), firstsib(NULL) {}
		Node(int x, Node* Son = NULL, Node* Sib = NULL,int y=-1) :data(x), firstson(Son), firstsib(Sib),number(y) {}
	};
	Node* root;
	void postOrder(Node* t);
	int Nodenumber;
public:
	void preOrder();
	void postOrder();
	void levelOrder();
	void createTree();
};

void tree::postOrder(Node* t)
{
	if (t == NULL) return;
	postOrder(t->firstson);
	cout << t->data << " ";
	postOrder(t->firstsib);
}
void tree::postOrder()
{
	postOrder(root);
}

void tree::createTree()
{
	queue<Node*>sonque,sibque;
	Node* tmp;
	int nodenumber, fson, fsib, Nodedata,p;
	cin >> nodenumber;
	Nodenumber=nodenumber;
	int* sonarray = new int[nodenumber+1];
	int *sibarray = new int[nodenumber+1];
	int *dataarray=new int [nodenumber+1];
	sonarray[0]=-1;
	sibarray[0]=-1;
	dataarray[0]=-1;
	for(int i=1;i<=nodenumber;i++)
	{
		cin>>fson;
		cin>>fsib;
		cin>>Nodedata; 
		sonarray[i]=fson;
		sibarray[i]=fsib;
		dataarray[i]=Nodedata;
	} 
	int i=1;
	while(i <= nodenumber)
	{
		bool Whetherroot = false;
		int j = 1;
		while(j <= nodenumber)
		{
			if (sonarray[j]!=i)
			{
				j++;
			}
			else break;
		}
		int k=1;
		while(k<=nodenumber)
		{
			if (sibarray[k]!=i)
			{
				k++;
			}
			else break;
		}
		if((k == nodenumber+1)  &&  (j == nodenumber+1)) Whetherroot=true;
		if(Whetherroot) break;
		i=i+1;
	}
	p=i;
	root = new Node(dataarray[p]);
	root->number=p;
	root->firstson=new Node();
	sibque.push(root->firstson);
	for (int b = 1; b < Nodenumber ; b++)
	{
		if (!sibque.empty())
			{
				tmp = sibque.front();
				sibque.pop();
			}
		else if (sibque.empty() &&! sonque.empty())
			{
				tmp = sonque.front();
				sonque.pop();
			}
		p=tmp->number;
		fson=sonarray[p];fsib=sibarray[p];Nodedata=dataarray[p];
		if (fson != 0) 
		{
			sonque.push(tmp->firstson = new Node());
			tmp->firstson->number=fson;
		}
		if (fsib != 0) 
		{
			sibque.push(tmp->firstsib = new Node());
			tmp->firstsib->number=fsib;
		}
		tmp->data = Nodedata;
	}
}
void tree::levelOrder()
{
	queue<Node*>sonque, sibque;
	Node* tmp;
	sibque.push(root);
	for (int i = 0; i < Nodenumber; i++)
	{
		if (!sibque.empty())
			{
				tmp = sibque.front();
				sibque.pop();
			}
		else if (sibque.empty() && !sonque.empty())
			{
				tmp = sonque.front();
				sonque.pop();
			}
		cout << tmp->data<< " ";
		if (tmp->firstsib != NULL) 
		{
			sibque.push(tmp->firstsib);
		}
		if (tmp->firstson != NULL) 
		{
			sonque.push(tmp->firstson);
		}
	}
}
void tree::preOrder()
{
	stack<Node*> s;
	Node *current;
	s.push(root);
	while(!s.empty())
	{
		current=s.top();
		s.pop();
		cout<<current->data<<" ";
		if (current->firstsib != NULL) s.push(current->firstsib);
		if (current->firstson != NULL) s.push(current->firstson);
	}
}

int main()
{
	tree T;
	T.createTree();
	T.preOrder();
	cout<<"\n";
	T.postOrder();
	cout<<"\n";
	T.levelOrder();
	return 0;
}

