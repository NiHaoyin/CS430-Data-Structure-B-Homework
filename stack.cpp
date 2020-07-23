#include<iostream>
#include<iomanip>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
class stack
{
	private:
		struct node
		{
			int train;
			node *next;
		};
	node *top;
	public:
		stack()
		{
			top=NULL;
		}		
		bool empty();
		void push(int &x);
		int pop();
		int size();
		int topele();
 }; 
void stack::push(int &x)
{
	node* newtop=new node;
	newtop->train=x;
	newtop->next=top;
	top=newtop;
}
int stack::pop()
{
	node *tmp=top;
	int x=tmp->train;
	top=top->next;
	delete tmp;
	return x;
}
bool stack::empty()
{
	if (top!=NULL) return false;
    else return true;
}
int stack::size()
{
	int i=0;
	node * tmp=top;
	while (tmp != NULL)
	{
		i=i+1;
		tmp=tmp->next;
	}
	return i;
}
int stack::topele()
{
	return top->train;
}
int main()
{
	stack stack1;;
	int k,n,m,tmp,cur;//n是火车数量；m是容量 
	cin>>k;
	int array[k];
	for (int i=0;i<k;i++)
        {
        	array[i]=0;
		}
	for (int i=0;i<k;i++)
		{
		cin>>n;
		cin>>m;
        cur = 0;
        int x = 0;
        stack1.push(x);
        for (int i = 0; i < n; ++ i) 
			{
            scanf("%d", &tmp);
            if (tmp > cur) 
			{
                for (int j = cur+1 ; j <= tmp; j++)
                    stack1.push(j);
                cur = tmp;
            }
			else 
			{	
				if (stack1.topele() != tmp)
                {
				array[i]=1;
                break;
				}
            }
            stack1.pop();
            if(!stack1.empty())
        	{
            	if (stack1.size() > m) 
				{
                	array[i]=1;
                	break;
				}
			}
        	}
		while (!stack1.empty())
		{
			stack1.pop() ;	
		}	
    	} 
    for (int i=0;i<k;i++)
    {
    	if (array[i]==1) cout<<"No\n";
    	else cout<<"Yes\n";
	}
	return 0;
}
