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
	
	v.Insert(0, 1);
	v.Insert(0, 2);
	v.Insert(0, 3);

	v.Erase(0);
	v.Erase(0);
	v.Erase(0);

	cout<<v.Empty( )<<endl;
}

void test4( )
{ 
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	
	v.Insert(1, 3, 99);
	cout<<v.Size( )<<" :"<<v.Capacity( )<<endl;
	v.Print( );
}
#include <vector>

int main( )
{ 
//	test1( );
//	test2( );
//	test3( );
	
	test4( );
	return 0;
}
