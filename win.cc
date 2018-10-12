/* 途家：拿小石子比赛
 * 
 * 一堆石子n个，A、B两人轮流拿，A先拿 B后拿；每人至多拿k个
 * 至少拿一个；A、B同样聪明，最后拿到石子的获得胜利
 * 输入n，k  问：判断谁获得胜利
 *
 * test: 
 * 4
 * 3 2
 * 4 2
 * 7 3
 * 8 3
 *
 * output:
 * B
 * A
 * A
 * B
 *
 * */
#include <iostream>
#include <vector>
using namespace std;

void Win(int n, int k) 
{ 
	vector<bool> isWin(n+1, true); //true表示先取的一方胜利
	for(int i=k; i<= n; ++i){ 
		int j =1;
		for(; j<=k; ++j){ 
			if(!isWin[i-j]) break;
		}
		if(j > k)
			isWin[i] = false;
		//cout<<" :"<<isWin[i]<<endl;
	}
	if(isWin[n-1] == true) cout<<"A"<<endl;
	else cout<<"B"<<endl;
}
int main( )
{ 
	int t,n,k;
	while( cin>>t){ 
		for(int i=0; i<t; ++i){ 
			cin>>n>>k;  Win(n, k);
		}
	}
	return 0;
}
