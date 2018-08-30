/*************************************************************************
  > File Name: main.cc
  > Author: tp
  > Mail: 
  > Created Time: Tue 15 May 2018 10:53:29 PM CST
 ************************************************************************/
#include "1.h"

void Test( ) 
{ 
	int a =1, b=2;
	Swap<int>(a, b);
	cout<<a<<" "<<b<<endl;
}
//class A
//{ 
//public:
//		A()
//		:a(){}
//		void show( )
//		{cout<<a<<endl;}
//protected:
//	T a;
//};
int main(void)
{ 
	Test( );
	return 0;
}
