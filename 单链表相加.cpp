#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
	int coef;
	int exp;
	struct Node* next;
}; 
typedef struct Node* Pnode;

Pnode createnode(int size)
{
	int coef;
	int exp;
	Pnode head, tail, p;
    p = (Pnode)malloc(sizeof(Node));
    head = (Pnode)malloc(sizeof(Node));
    head->coef=NULL;
    head->exp=NULL;
    head->next=p;
    for (int i=0;i<=size-1;i++)
    {
    	scanf("%d", &coef);
    	scanf("%d", &exp);
    	p->coef=coef;
    	p->exp=exp;
    	tail = (Pnode)malloc(sizeof(Node));
    	tail->next = NULL;
		p->next = tail;
		p = tail;
	}
    return head;	
}

Pnode addNode(Pnode pa, Pnode pb) 
{	
	Pnode p, q, pc,delp;
	p = pa->next;
	pc = pa;
	q = pb->next;
	while (p->next != NULL )//&& q->next != NULL 
	{
		if (p->exp==q->exp)
		{
			int x=p->coef+q->coef;
			if (x == 0) 
		    {   
			pc->next = p->next;
			p = p->next;
			q = q->next;
			}
			else 
			{
			p->coef = x;
			p = p->next;
			pc = pc->next;
			q = q->next;
			}
		}
		
		if (p->exp<q->exp)
		{
			Pnode x;
			x = (Pnode)malloc(sizeof(Node));
			x->coef = q->coef;
			x->exp = q->exp;
			pc->next = x;
			x->next = p;
			q = q->next;
			p = pc->next;
		}
        if (p->exp>q->exp) 
		{   
			p = p->next;
			pc = pc->next;
		}
	}
	if (q) //q
	{  
	pc->next = q;
	}
	p=pa->next;
	return pa;
}


int main()
{
	int size1,size2,j=1;
	Pnode pa, pb, x;
	scanf("%d", &size1);
	scanf("%d", &size2);
	pa=createnode(size1);
    pb=createnode(size2);
    pa=addNode(pa,pb);
    x = pa->next;
    
	while (x->next != NULL) 
	{
	j++;
	x = x->next;
	}
	
	if (pa->next->next == NULL)
	{
		cout<<0<<" "<<0;
	}
	for (int i = 0; i <j-1; i++) 
	{
	    //if(pa->next->next !=NULL)	
		//{
		cout<<pa->next->coef;
		printf(" ");
		cout<<pa->next->exp;
		printf(" ");
		pa = pa->next;
		//}
		
	}
	return 0;
}
