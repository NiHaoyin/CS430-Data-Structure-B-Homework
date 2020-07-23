#include<iostream>
using namespace std;
#include <string>
class PriorityQueue
{
private:
	int* array;
	int currentSize;
	int maxSize;
	void doublespace();

public:
	PriorityQueue(int capacity = 100000)
	{
		array = new int[capacity];
		maxSize = capacity;
		currentSize = 0;
		array[0]=-1000;
	}
	void insert(int& x);
	int find(int x);
	void decrease(int i, int v);
	void output()
	{
		for (int i=0;i<=currentSize;i++)
		{
			cout<<array[i]<<" ";	
		}	
	} 
};
void PriorityQueue::insert(int& x)
{
	// if (currentSize == maxSize - 1) doublespace();
	int hole = ++currentSize;
	while (hole > 1 && x < array[hole / 2])
	{
		array[hole] = array[hole / 2];
		hole = hole / 2;
	}
	array[hole] = x;
}
int PriorityQueue::find(int x)
{
	int number = 1 ;
	int min;
	for (int i = 1; i <= currentSize; i++)
	{
		if (array[i] > x)  
			{
				min = array[i];
				number = i;
				break;
			}
	}
	for (int i = 1; i <= currentSize; i++)
	{
		if ((array[i] > x) && (array[i] < min))
		{
			min=array[i];
			number = i;
		}
	}
	return number;
}
void PriorityQueue::decrease(int i, int v)
{
	array[i] = array[i] - v;
	int hole = i;
	int tmp;
	while (array[hole] < array[hole/2])
	{
		tmp = array[hole/2];
		array[hole/2] = array[hole];
		array[hole] = tmp;
		hole = hole/2;
	}
}
int main()
{
	PriorityQueue q;
	int N,number,node,j;
	string word;
	cin >> N;
	int *find = new int[N];
	j=0;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		cin >> number;
		if (word == "insert")
			q.insert(number);
		else if (word == "find")
			{
				find[j]=q.find(number);
				j=j+1;
			}
		else if (word == "decrease")
		{
			cin >> node;
			q.decrease(number,node);
		}
	
	}
//	q.output() ;
	for (int i=0;i<j;i++)
	{
		cout<<find[i]<<endl;
	}
	return 0;
}

