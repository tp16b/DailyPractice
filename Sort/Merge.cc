
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right)
{ 
	int begin1 = left, end1= mid;
	int begin2 = mid+1, end2 = right;
	vector<int> tmp;
	//合并
	while(begin1 <= end1 && begin2 <= end2 )
	{ 
		if( arr[begin1] < arr[begin2])
			tmp.push_back( arr[begin1++]);
		else
			tmp.push_back( arr[begin2++]);
	}
	while(begin1 <= end1 )
			tmp.push_back( arr[begin1++]);
	while(begin2 <= end2 )
			tmp.push_back( arr[begin2++]);
	//拷回
	for( int i=0; i< tmp.size( ); ++i)
	{ 
		arr[ i+left] = tmp[ i];
	}
}
void MergeSort(vector<int>& arr, int left, int right)
{ 
	if(left >= right) return;

	int mid = left + (right -left >>1);
	MergeSort(arr, left, mid);
	MergeSort(arr, mid+1, right);
	Merge(arr, left, mid, right);
}
void MergeSort(vector<int>& array)
{ 
	int len = array.size( ); 
	if(len <= 1 )  return ;
	MergeSort(array, 0, len -1);
}
int main( ) 
{ 
	vector<int> a;
	a.push_back(3);
	a.push_back(40);
	a.push_back(1);
	a.push_back(4);
	a.push_back(1);
	a.push_back(2);
	MergeSort(a);
	for(int i =0;i < a.size( ); ++i)
	{ 
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
