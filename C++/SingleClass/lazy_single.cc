
#include <iostream>
#include <stdio.h>
using namespace std;

//1. 懒汉模式  (基础版本，  线程不安全)
class SingleClass
{ 
public:
	static SingleClass* GetInstance(){ 
		if( _pInstance == NULL){ 
			_pInstance = new SingleClass();
		}
		return _pInstance;
	}
private:
	SingleClass() { };
	SingleClass(const SingleClass& ); //防拷贝
	SingleClass& operator=(const SingleClass& ); //防copy assignment

	static SingleClass* _pInstance;
};

SingleClass* SingleClass::_pInstance = NULL; //将成员_pInstance初始化为null 


void test1( ){ 
	cout<<"run test1 ...\n";
	SingleClass* p = SingleClass::GetInstance( );
	SingleClass* p1 = SingleClass::GetInstance( );
	SingleClass* p2 = SingleClass::GetInstance( );

	cout<<(p == p1 && p1== p2)<<endl;
}

//1.1  懒汉线程安全版（加锁保证线程安全） 
//class SingleClass1
//{ 
//public:
//	static SingleClass1* GetInstance(){ 
//		//再次判断是否为空！ 解决接连到来的线程阻塞到锁上影响效率 
//		if(_pInstance == NULL){  		
//			mutex.lock( ); //加锁
//			if( _pInstance == NULL){ 
//				_pInstance = new SingleClass();
//			}
//			mutex.unlock( ); //解锁
//			return _pInstance;
//		}
//	}
//private:
//	SingleClass1() { };
//	SingleClass1(const SingleClass1& ); //防拷贝
//	SingleClass1& operator=(const SingleClass1& ); //防copy assignment
//
//	static SingleClass1* _pInstance;
//};
//
//SingleClass1* SingleClass1::_pInstance = NULL; //将成员_pInstance初始化为null 



//1.2 懒汉-静态局部对象版( C++11后保证线程安全)
class SingleClass2
{ 
public:
	static SingleClass2& GetInstance(){ 
		//c++11之后保证静态局部变量初始化过程线程安全问题
		static SingleClass2 instance;
		return instance;
	}
private:
	SingleClass2() { };
	SingleClass2(const SingleClass2& ); //防拷贝
	SingleClass2& operator=(const SingleClass2& ); //防copy assignment
};


void test2( ){ 
	SingleClass2& obj1 = SingleClass2::GetInstance( ); 
	SingleClass2& obj2 = SingleClass2::GetInstance( ); 
	SingleClass2& obj3 = SingleClass2::GetInstance( ); 

	printf( "%p\n", &obj1);
	printf( "%p\n", &obj2);
	printf( "%p\n", &obj3);
}
int main( )
{ 
//	test1( );
	test2( );
	return 0;
}
