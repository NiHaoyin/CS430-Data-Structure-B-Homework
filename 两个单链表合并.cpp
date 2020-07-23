#include<iostream>
#include<iomanip>
using namespace std;
class Node   //�ڵ���
{
public:
	int value;
	Node *next;
	Node(int value, Node *next=NULL) :value(value), next(next){};  //���캯��
};
class List  //������  
{
private:
	Node *head;
public:
	List()     //���캯��  
	{
		head = new Node(0, NULL);  //ͷ�ڵ�  
	}
	~List();   //��������
	void print();
	void add(int value);
	void merge(List list);
};
void List::add(int value)   //���Ԫ�أ�����  
{
	if (head->next == NULL)   //���������Ԫ��  
	{
		head->next = new Node(value, NULL);
		return;
	}
	Node *p = head;
	while (p->next && p->next->value<value)
		p = p->next;
	if (p->next == NULL)  //���������ĩβ  
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
void List::merge(List list)   //�ϲ�����˼·����list�еĽڵ���������ֱ�Ӳ���ķ������в���
{
	Node*p = head;
	Node*q = list.head->next;
	for (; q; q = q->next)
	{
		while (p->next && p->next->value < q->value)   //Ϊq��ָ��ڵ�Ĳ��룬Ѱ�Һ��ʵ�λ��
			p = p->next;
		if (p->next == NULL)   //��ĩβ
		{
			p->next = new Node(q->value);
			p->next->next = NULL;   //��һ����Բ���
			continue;
		}
		if (q->value == p->next->value)   //�ظ�Ԫ�ز����
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
	// ������������ϲ�����Ҫ��ȥ���ظ�Ԫ��  
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
	
	//��ӡ��һlist1.print();     
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


