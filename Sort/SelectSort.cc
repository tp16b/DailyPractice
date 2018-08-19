/*************************************************************************
  > File Name: SelectSort.cc
  > Author: tp
  > Mail: 
  > Created Time: Tue 05 Jun 2018 11:44:09 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
void Print(const vector<int>& arr)
{ 
	vector<int>::const_iterator it = arr.begin( );
	while( it != arr.end( ))
	{ 
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}
void SelectSort(vector<int>& arr )
{ 
	int len = arr.size( );
	if( len <= 1) return;
	int left =0, right = len-1;
	int min = 0, max = 0;
	while( left < right)
	{ 
		min = left; 
		max = left;
		for( int i =left; i<= right; ++i)
		{ 
			if(arr[ i] > arr[max])
				max = i;
			if( arr[ i] < arr[ min])
				min = i;
		}
		swap(arr[min], arr[left]); 
		if( left == max)
			max = min;
		swap( arr[ max], arr[right]);
		++left;
		--right;
		Print( arr);
	}
}

int main( )
{ 
	vector<int> arr;
	arr.push_back( 1);
	arr.push_back( 10);
	arr.push_back( 30);
	arr.push_back( 5);
	arr.push_back( 110);
	arr.push_back( 5);
	arr.push_back( 2);
	Print( arr);
	SelectSort(arr );
	Print( arr);
	return 0;
}
