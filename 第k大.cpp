#include<iostream>
using namespace std;
int divide(int a[], int low, int high)
{
	int k;
	k = a[low];
	while (low != high)
	{
		while (a[high] >= k && low<high)
		{
			high = high - 1;
		}
		if (low < high)
		{
			a[low] = a[high];
			low++;
		}
		while (a[low] <= k && low<high)
		{
			low = low + 1;
		}
		if (low < high)
		{
			a[high] = a[low];
			high--;
		}
	}
	a[low] = k;
	return low;
}
void quicksort(int array[], int low, int high)
{
	int mid;
	if (low >= high) return;
	mid = divide(array, low, high);
	quicksort(array, mid + 1, high);
	quicksort(array,low,mid-1) ;
}

int main()
{
	int size, k,number;
	cin >> size >> k;
	int a [size];
	for (int i = 0; i < size; i++)
	{
		cin >> number;
		a[i] = number;
	}
	quicksort(a, 0, size - 1);
	cout<<a[size-k];
	return 0;
}

