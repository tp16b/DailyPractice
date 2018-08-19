/*************************************************************************
  > File Name: HeapSort.cc
  > Author: tp
  > Mail: 
  > Created Time: Mon 21 May 2018 09:37:46 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define N 8

void AdjustDown( int* number, int range, int parent)
{ 
	int child = (parent<<1)+1; 
	while(child < range)
	{
		if(number[ child] < number[ child+1] && child+1< range)
			++child;
		if(number[child] > number[parent])
			swap(number[child], number[parent]);
		
		parent = child;
		child = (parent<<1)+1;
	}
}
void HeapSort(int* number, int size)
{ 
	int i = (size-2)>>1;	
	for(; i>=0; --i)
	{ 
		AdjustDown(number, size, i);
	}

	int end = size -1;
	while(end > 0)
	{ 
		swap(number[0], number[ end]);
		AdjustDown(number, end, 0);
		--end;
	}
}
int main()
{ 
	int number[N] = {4, 9,1,5,2,0,23,4};
	HeapSort(number, N);
	for(int i=0; i<N; ++i)
	{ 
		cout<<number[i]<<" ";
	}
	cout<<endl;
	return 0;
}
