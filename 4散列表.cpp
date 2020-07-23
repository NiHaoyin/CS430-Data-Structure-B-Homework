#include<iostream>
using namespace std;
class HashTable
{
private:
	struct node
	{
		int data;
		int state;
		int finding;
		node()
		{
			state =0;
			finding=0;
		}
	};
	node* array;
	int size;
	int parameter;
	void module();
public:
	void setparameter();
	void insert(int x);
	void ouput();
};
void HashTable::module()
{
	for (int i=0;i<size;i++)
	{
		if (array[i].state == 0)
		{
			array[i].data=-1;
		}
	}
}
void HashTable::setparameter()
{
	int p, m, n;
	cin >> p >> m ;
	parameter = p;
	size = m;
	array = new node[size];
}
void HashTable::insert(int x)
{
	int initPos, pos, i=1,find;
	pos = x % parameter;
	find=0;
	while (i)
	{
		if (array[pos].state != 1)
		{
			array[pos].data = x;
			array[pos].state = 1;
			array[pos].finding=find+1;
			i = 0;
			return;
		}
		if (pos == size - 1)	
		{
			pos=0;
		}
		else	pos = pos + 1;
		find++;
	}
}
void HashTable::ouput()
{
	for (int i=0;i<size;i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	module();
	for (int i=0;i<size;i++)
	{
		cout<<array[i].data<<" ";
	}
	cout<<endl;
	for (int i=0;i<size;i++)
	{
		cout<<array[i].finding<<" ";
	}
}
int main()
{
	HashTable table;
	table.setparameter();
	int n,x;
	cin >>n;
	int find [n];
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		table.insert(x);
	}
	table.ouput();
	cout<<endl;
	return 0;
}
