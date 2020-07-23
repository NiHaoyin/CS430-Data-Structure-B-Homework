#include<iostream>
#include<iomanip>
using namespace std;
class Node   //节点类
{
public:
	int value;
	Node *next;
	Node(int value, Node *next=NULL) :value(value), next(next){};  //构造函数
};
class List  //链表类  
{
private:
	Node *head;
public:
	List()     //构造函数  
	{
		head = new Node(0, NULL);  //头节点  
	}
	~List();   //析构函数
	void print();
	void add(int value);
	void merge(List list);
};
void List::add(int value)   //添加元素，升序  
{
	if (head->next == NULL)   //如果表中无元素  
	{
		head->next = new Node(value, NULL);
		return;
	}
	Node *p = head;
	while (p->next && p->next->value<value)
		p = p->next;
	if (p->next == NULL)  //如果到达表的末尾  
	{
		p->next = new Node(value);
		p->next->next = NULL;
	}
	else
	{
		Node *node = new Node(value);
		node->next = p->next;
		p->next = node;
	}
}
void List::merge(List list)   //合并链表，思路：把list中的节点用类似于直接插入的方法进行插入
{
	Node*p = head;
	Node*q = list.head->next;
	for (; q; q = q->next)
	{
		while (p->next && p->next->value < q->value)   //为q所指向节点的插入，寻找合适的位置
			p = p->next;
		if (p->next == NULL)   //到末尾
		{
			p->next = new Node(q->value);
			p->next->next = NULL;   //这一句可以不加
			continue;
		}
		if (q->value == p->next->value)   //重复元素不添加
		{
			continue;
		}
		Node *node = new Node(q->value);
		node->next = p->next;
		p->next = node;
	}
}
void List::print()
{
	for (Node* p = head->next; p; p = p->next)
		cout <<p->value<<" ";
	cout << endl;
}
List::~List()
{
	Node *q, *p = head;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
}
int main()
{
	// 两个升序链表合并，并要求去掉重复元素  
	List list1;
	int m,n;
	
	scanf("%d",&m);
    scanf("%d",&n); 
    
    for (int i=1;i<=m;i++)
    {
    	int value;
		scanf("%d",&value);
		list1.add(value);
	}
	
	//打印表一list1.print();     
	List list2;
	
	for (int i=1;i<=n;i++)
    {
    	int value;
		scanf("%d",&value);
		list2.add(value);
	}
	list1.merge(list2);
	
	list1.print();
	system("pause");
	return 0;
}


