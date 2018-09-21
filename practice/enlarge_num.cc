/* Function: 放大数字
 * 功能：实现一个数字放大的函数，放大的样式类似于用
 *    *   ***
 *    *     *
 *    *   ***
 *    *   *
 *    *   ***
 * 来表示数字12 
 * */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<vector<vector<char> > > num_arr{ 
	{  //1
		{'*', '*', '*'},
		{' ', '*', ' '},
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', ' ', '*'}, //4
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'},
	},
	{  //2
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
		{'*', ' ', '*'}, //4
		{'*', ' ', ' '},
		{'*', ' ', ' '},
		{' ', ' ', '*'},
		{'*', ' ', '*'},
		{'*', ' ', '*'},
	},
	{ //3
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{'*', '*', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'}, //4
		{'*', '*', '*'},
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'},
	},
	{//4 
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{'*', ' ', ' '},
		{' ', ' ', '*'},
		{' ', ' ', '*'}, //4
		{' ', ' ', '*'},
		{'*', ' ', '*'},
		{' ', ' ', '*'},
		{'*', ' ', '*'},
		{' ', ' ', '*'},
	},
	{//5 
		{'*', '*', '*'},
		{' ', '*', ' '},
		{'*', '*', '*'},
		{'*', '*', '*'},
		{' ', ' ', '*'}, //4
		{'*', '*', '*'},
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
		{'*', '*', '*'},
	},
};
void GetNum(vector<int>& num, int n){
	stack<int> s;
	while( n> 0){ 
		s.push(n%10);
		n /= 10;
	}
	while( !s.empty( )){ 
		num.push_back(s.top());
		s.pop( );
	}
}
void PrintNum(const vector<int>& v){ 
	for( int i=0; i< 5; ++i){ 
		for(int j =0; j <v.size(); ++j ){ 
			for(int k =0; k < 3; ++k) 
				cout<<num_arr[i][v[j]][k];
			cout<<" ";
		}
		cout<<endl;
	}
}
int main( )
{ 
	int n;
	while( cin>>n){ 
		vector<int> num;
		GetNum(num, n);

		PrintNum(num);
	}
	return 0;
}
