#include <cstddef>
#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<stdlib.h>
#include<queue> 
using namespace std;
class tree
{
private:
	struct Node
	{
		Node *left, *right;
		int data;
		Node( ): left(NULL),right(NULL){}
		Node(int x,Node *L=NULL, Node *R=NULL):data(x),left(L),right(R){}
	};
	Node *root;
	int Nodenumber;
	public:
	int levelOrderJudge();
	void createTree();
};

void tree::createTree()
{
	int nodenumber,lson,rson;
	cin>>nodenumber;
	int leftsonarray[nodenumber],rightsonarray[nodenumber];
	for (int i=0;i<nodenumber;i++)
	{
		cin>>lson>>rson;
		leftsonarray[i]=lson;
		rightsonarray[i]=rson;
	}
	queue<Node*>que;
	Node *tmp;
	int x;
	root=new Node(nodenumber);
	que.push(root);
	int i=nodenumber-1;
	while (!que.empty())
	{
		tmp=que.front();
		que.pop();
		lson=leftsonarray[i];
		rson=rightsonarray[i];
		if (lson!=0) que.push(tmp->left=new Node(lson));
		if (rson!=0) que.push(tmp->right=new Node(rson));
		i=i-1;
	}
} 
int tree::levelOrderJudge()
{
	queue<Node*>que;
	Node*tmp;
	que.push(root);
	while(tmp=que.front())//����Ԫ�ز�ΪNULL����ýڵ���ڣ���չ����ڵ�Ķ��ӽڵ㣬��ΪNULL��˵���������Ľڵ�Ϊ�սڵ��ˣ���ô�ͱ�������������Ԫ��
    {
        que.push(tmp->left);
        que.push(tmp->right);
        que.pop();
    }
    while(!que.empty())
    {
        if(que.front()) return 0;
        que.pop();
 
    }
    return 1;

}
int main()
{
	tree T;
	T.createTree();
	if (T.levelOrderJudge())
	cout<<"Y";
	else 
	cout<<"N";
	return 0;
}
 
