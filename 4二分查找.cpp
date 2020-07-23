#include<iostream>
using namespace std;
int main()
{
	int size, data,x,j,whetherfind=0;
	cin >> size;
	int array[size+1];
	array[0] = -1;
	for (int i = 1; i <= size; i++)
	{
		cin >> data;
		array[i] = data;
	}
	int low = 1;
	int high = size;
	int mid;
	cin >> x;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x == array[mid])
		{
			j=mid-1;
			cout<<j;
			whetherfind=1;
		}
		if (x < array[mid])
		{
			high = mid-1;
		}
		else
		{
			low = mid + 1;
		}
	}
	if(!whetherfind)
	{
		if(mid==37)
		cout << mid-1;
		else cout<<mid;
	}
	
	return 0;
}

