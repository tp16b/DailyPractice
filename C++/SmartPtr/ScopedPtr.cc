/*************************************************************************
  > File Name: ScopedPtr.cc
  > Author: tp
  > Mail: 
  > Created Time: Sun 13 May 2018 06:02:24 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

struct A{ 
	int age;
	string name;
	A(string na, int a = 0)	:age(a), name( na) { }
};
template <class T>
class ScopedPtr
{ 
public:
		ScopedPtr(T* ptr)	
			:_ptr(ptr) 
		{ 
			ptr = NULL;
		}

		T& operator*()  {return *_ptr;}
		T* operator->()	{return _ptr;}

		~ScopedPtr( )	{delete _ptr; }
private:
		ScopedPtr(ScopedPtr<T>& a);  //防拷贝 
		ScopedPtr<T>& operator=( ScopedPtr<T>& a);
		T* _ptr;
				
};

int main( void)
{	
	ScopedPtr<int> sp1(new int(20));
	cout<<++(*sp1)<<endl;	

	ScopedPtr<A> sp2(new A("napom"));
	cout<<sp2->name<<endl;

	ScopedPtr<int> sp3(sp1);		
//	cout<<*sp1;  //导致ap1无家可归,赋值运算同理
	return 0;
}
