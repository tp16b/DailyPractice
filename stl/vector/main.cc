/*************************************************************************
  > File Name: main.cc
  > Author: tp
  > Mail: 
  > Created Time: Sun 02 Sep 2018 03:12:46 PM CST
 ************************************************************************/
#include "Vector.h"


void test1( )
{ 
	Vector<int> v;
	v.Insert(0, 1);
	v.Insert(0, 2);
	v.Insert(0, 3);
	v.Insert(0, 4);
	v.Insert(0, 5);
	v.Print( );
	cout<<"size: "<<v.Size( )<<endl;
	cout<<"capacity: "<<v.Capacity( )<<endl;
}
void test2( )
{ 
	Vector<int> v;
	v.Insert(0, 1);
	v.Insert(0, 2);
	v.Insert(0, 3);
	v.Insert(0, 4);
	v.Insert(1, 5);
	v.Insert(5, 99);
	v.Print( );
	cout<<"size: "<<v.Size( )<<endl;
	cout<<"capacity: "<<v.Capacity( )<<endl;
	
	Vector<int> v2(v);
	v2.Print( );
	cout<<"size: "<<v2.Size( )<<endl;
	cout<<"capacity: "<<v2.Capacity( )<<endl;
}
void test3( )
{ 
	Vector<int> v;

}
int main( )
{ 
	test1( );
	test2( );
	return 0;
}
