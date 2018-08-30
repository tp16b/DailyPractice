/*************************************************************************
  > File Name: AutoPtr.cc
  > Author: tp
  > Mail: 
  > Created Time: Sun 13 May 2018 05:08:41 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct A
{ 
	int age;
	string name;
	A(string na, int a = 0)
		:age(a), name(na) { }
};

template <class T>
class AutoPtr
{ 
public:
	AutoPtr(T* ptr)	:_ptr(ptr) { }

	T& operator*()   {return *_ptr;}
	T* operator->()	 {return _ptr;}

	//防止多次析构，ap2直接夺取管理权，ap1置空
	//ap2( ap1)
	AutoPtr(AutoPtr<T>& a) :_ptr(a._ptr)  {a._ptr = NULL;}

	//ap2 = ap1
	AutoPtr<T>& operator=(AutoPtr<T>& a)
	{ 
		if(this != &a){ 
			delete _ptr;
			_ptr = a._ptr;
			a._ptr = NULL;
		} 
		return *this;
	}

	~AutoPtr()	{ delete _ptr;}
protected:
	T* _ptr;
};
int main( void)
{	
	AutoPtr<int> ap1(new int(20));
	cout<<++(*ap1)<<endl;	

	AutoPtr<A> ap2(new A("napom"));
	cout<<ap2->name<<endl;

	AutoPtr<int> ap3(ap1);		
	cout<<*ap1;  //导致ap1无家可归,赋值运算时同理
	return 0;
}
