/* Function: 改版二分查找
 * 
 * 一个数组中元素是由有序数组经过旋转得来，试查找一个指定元素
 * 要求达到lgN的时间复杂度
 * */
#include <iostream>
#include <vector>
using namespace std;

int FindMinIndex(const vector<int>& v)
{ 
	int l  =0, r = v.size( )-1;
	int mid = l;
	while(v[l] >= v[r]){ 
		if(r- l == 1) 
			return r;

		mid = l + (r-l>>1);
		//0 1 1 1 1  =>  1 0 1 1 1 和 1 1 1 0 1的情况
		if(v[l] == v[r] && v[l] == v[mid]){ 
			int minIndex = l;
			for( int i=l+1; i <= r; ++i ){ 
				if(v[i] < v[minIndex])
					minIndex = i;
			}
			return minIndex;
		}
		if(v[l] <= v[mid]){ 
			l = mid;
		}else if(v[r] >= v[mid]) 
			r = mid;
	}
	return mid;
}

int BinaryFind( const vector<int>& v, 
				int l, int r, int target)
{ 
	while(l <= r){ 
		int mid= l + ( r-l>>1);
		if(v[mid] < target){ 
			l = mid+1;
		}else if( v[mid] > target){ 
			r = mid -1;
		}else
			return mid;
	}
	return -1;
} 
int Find( const vector<int>& v, int target){ 
	int ret =0, len = v.size( );
	int del = FindMinIndex(v);

	if((ret = BinaryFind(v, 0, del-1, target))  == -1){ 
		ret = BinaryFind(v, del, len-1, target);
	}
	return ret;
}
int main( )
{ 
	vector<int> v{ 4,5,0,1,1,2,3}	;	
	cout<<Find(v, 2)<<endl;

	vector<int> v1{ 1,0,1,1,1};	
	cout<<Find(v1, 0)<<endl;

	vector<int> v2{0};	
	cout<<Find(v2, 0)<<endl;

	vector<int> v3{ 4,5,0,1,1,2,3}	;	
	cout<<Find(v3, 9)<<endl;
	return 0;
}
