/************************************************************************
  > File Name: sharedPtr.cc
  > Author: tp
  > Mail: 
  > Created Time: Sun 13 May 2018 06:11:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//智能指针——引用计数版本
struct A{ 
	int age;
	string name;
	A(string na ="", int a = 0)
		:age(a), name( na)  { }
};
template<class T>
struct DelArr{ 
	void operator()(T* ptr){ 
		cout<<"delete[]"<<endl;
		delete[] ptr;
	}
};
template <class T, class Del= DelArr<T> >
class SharedPtr
{ 
public:
		SharedPtr( T* ptr)	
			:_ptr(ptr)
			 ,_pCount(new int(1) )	{ }

		T* operator->( )   {return _ptr;}
		T& operator*( )    {return *_ptr;}

		SharedPtr(const SharedPtr<T>& sp)  //加上const
			:_ptr(sp._ptr)
			 ,_pCount(sp._pCount)    { ++(*_pCount);}

		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
		{ 
			if(this != &sp)	{ 
				Release( );
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				++(*_pCount);
			}
			return *this;
		}
		void Release( )
		{ 
			if(--(*_pCount) == 0){ 
				if(_ptr){        //真正释放空间 
					cout<<"释放空间"<<endl;
					delete _pCount;
					//delete _ptr;
					Del _del;    //定义定置删除仿函数
					_del(_ptr);  //调用该仿函数 

					_ptr = NULL;
					_pCount = NULL;
				}
			}
		}
		~SharedPtr(){ 
			cout<<"析构调用"<<endl;
			Release( );
		}
protected:
		T* _ptr;
		int* _pCount;
};

int main( void)
{ 
	SharedPtr<A, DelArr<A> > sp(new A[2]);
	return 0;

} 
