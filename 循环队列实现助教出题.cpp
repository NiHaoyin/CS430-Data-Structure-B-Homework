#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node (int x,node *n=NULL)
	{
		data=x;
		next=n;
	}
};
int main()
{
	int n,m,k,x;//n¸öÖú½Ì£¬mÂÖ£¬10^k´Î£¬xºÅ
	node *head,*p,*q;
	cin>>n;
	cin>>m;
	cin>>k;
	cin>>x;
    head=p=new node(0);
	for (int i=1;i<n;i++)
	{
		q=new node(i);
		p->next=q;
		p=p->next; 	
	} 
	p->next=head;
	for (int i=0;i<=x;i++)
	{
		p=p->next;
	}
	int a;
	a=int(pow(10,k))%n;
	//cout<<a<<"\n";
	for (int i=0;i<a;++i)
	{
		for(int j = 0; j < m; ++j) 
			p=p->next;
	}
	cout<<p->data;
	return 0;
}

