#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 简化区间  例：1 2 3 4 6    => 1-4 6
void Empty(queue<int>& q){ 
	queue<int> e;
	swap(q, e);
}
int main( )
{ 
	int n;
	queue<int> q;
	while(cin>>n){ 
		vector<int> v(n, 0)	;
		Empty(q);
		for( int i=0;i < n; ++i) 
			cin>>v[i];

		int lastFlag = 0;
		for(int i=0; i < n; ++i){ 
			if(q.empty() || q.back()+1 == v[i]){ 
				if(i == n -1) lastFlag = 1;

				q.push(v[i]);
			} 
			if(q.size( ) >= 4){ 
				if(lastFlag) cout<<q.front( )<<"-"<<q.back( );
				else cout<<q.front( )<<"-"<<q.back( )<<" ";
				Empty(q);
			}else if(q.back()+1 != v[i+1]){ 
				while(1 < q.size()){ 
					cout<<q.front()<<" ";
					q.pop( );
				}
				if(lastFlag)
					cout<<q.front();
				else
					cout<<q.front()<<" ";
			}
		}
	} 
	return 0;
} 
