
#include <iostream>
using namespace std;

//1. 饥汉版本单例类
/*特点：一开始就创建单例对象并且初始化
 *		不用考虑多线程下的线程安全问题
 *
 *缺陷：参见effictive c++ 条款47
 *		存在跨编译单元的初始化顺序问题，
 *		对该顺序,编译器是无法保证的
 */
class SingleClass
{ 
public:
	static SingleClass* GetInstance(){ 
		return &_instance;
	}
private:
	SingleClass()	{cout<<"SingleClass( )\n"; } 

	SingleClass(const SingleClass& ); //防拷贝
	SingleClass& operator=(const SingleClass& ); //防copy assignment

	static SingleClass _instance;
};

SingleClass SingleClass::_instance; //在程序入口之前进行单例对象初始化

void test1( )
{ 
	cout<<"run test1...\n";
	SingleClass* p1 = SingleClass::GetInstance( );
	SingleClass* p2 = SingleClass::GetInstance( );
	SingleClass* p3 = SingleClass::GetInstance( );

	printf( "%p\n", p1);
	printf( "%p\n", p2);
	printf( "%p\n", p3);
}


//1.2  饥汉单例模式（boost实现版, 
/*	解决不同编译单元初始化顺序问题）
*/
class SingleClass2
{ 
public:
	static SingleClass2& GetInstance( ){ 
		return *_pInstance;
	} 
private:
	SingleClass2( )    {cout<<"SingleClass2( )\n";}  
	// 辅助代理类, 由它进行实际创建
	struct ObjectCreator{ 
		ObjectCreator(){ 
			SingleClass2::_pInstance = new SingleClass2; 
		} 
		~ObjectCreator( ){ 
			delete SingleClass2::_pInstance;	
			SingleClass2::_pInstance = nullptr;
		}
	};
private:
	static SingleClass2* _pInstance;
	static ObjectCreator _object_creator;
} ;

/*定义一个ObjectCreator对象, 触发单例对象创建*/
SingleClass2* SingleClass2::_pInstance = NULL;
SingleClass2::ObjectCreator SingleClass2::_object_creator; 


void test2( )
{ 
	cout<<"run test2 ...\n"	;
	SingleClass2& obj1 = SingleClass2::GetInstance( );
	SingleClass2& obj2 = SingleClass2::GetInstance( );
	SingleClass2& obj3 = SingleClass2::GetInstance( );


	printf( "%p\n", &obj1 );
	printf( "%p\n",&obj2 );
	printf( "%p\n",&obj3 );
}

int main( )
{ 
//	test1( );
	test2( );
	
	return 0;
}
