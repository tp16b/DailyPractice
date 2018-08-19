/*************************************************************************
  > File Name: QuickSort.cc
  > Author: tp
  > Mail: 
  > Created Time: Tue 22 May 2018 12:45:13 PM CST
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;
#define N 7

int PartionSort( int* number, int left, int right)
{ 
	assert( number && left <= right);

	int begin = left;
	int end = right;
	int key = number[left];
	while(begin < end)
	{ 
		while(begin < end && number[end] >= key)
			--end;
		while(begin < end && number[begin] <= key)
			++begin;
		swap(number[begin], number[end]);
	}
	swap(number[begin], number[left]);

	return begin;
}
int PartionSort1( int* number, int left, int right)
{ 
	assert(number && left <= right);
	int begin = left;
	int end = right;
	int key = number[left];
	while(begin < end)
	{ 
		while(begin < end && number[end] >= key)
			--end;
		number[begin] = number[end];
		while( begin < end && number[begin] <= key)
			++begin;
		number[end] = number[begin];
	}
	number[begin] = key;
	return begin;
}
void QuickSort(int* number, int left, int right)
{ 
	if(left >= right)
		return;

	//int div = PartionSort(number, left, right);	
	int div = PartionSort1(number, left, right);	
	QuickSort(number, left, div-1);
	QuickSort(number, div+1, right);
}
int main()
{ 
	//int arr[N] = {5,2,9,5,1,11,5};
	int arr[N] = {9,8,7,5,4,3,5};
	QuickSort(arr, 0, N-1);
	for( int i=0; i< N; ++i)
		cout<<arr[ i]<<" ";
	cout<<endl;
	return 0;
}
