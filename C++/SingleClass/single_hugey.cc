
#include <iostream>
using namespace std;

//1. 饥汉版本单例类
/*特点：一开始就单例对象创建并且初始化
 *		不用考虑多线程下的线程安全问题
 *
 *缺陷：参见effictive c++ 条款47
 *		存在跨编译单元的初始化顺序问题，
 *		该顺序编译器是无法保证的
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

SingleClass SingleClass::_instance; //在程序入口之前就完成单例对象的初始化


//1.2  饥汉单例（boost实现版, 
/*	解决不同编译单元初始化顺序问题）
*/
class Singleton
{ 
public:
	static Singleton* GetInstance( ) 
	{ 
		static Singleton instance;
		return &instance;
	} 
protected:
	// 辅助代理类
	struct Object_Creator
	{ 
		Object_Creator( ) 
		{ 
			Singleton::GetInstance( ) ;
		} 
	} ;
	static Object_Creator _object_creator;

	Singleton( )  { } 
	~Singleton( )  { } 
} ;

Singleton::Object_Creator Singleton::_object_creator; 


void test1( )
{ 
	cout<<"run main ...\n";
	SingleClass* p1 = SingleClass::GetInstance( );
	SingleClass* p2 = SingleClass::GetInstance( );
	SingleClass* p3 = SingleClass::GetInstance( );

	printf( "%p\n", p1);
	printf( "%p\n", p2);
	printf( "%p\n", p3);
}
void test2( )
{ 

}
int main( )
{ 
//	test1( );
	test2( );
	return 0;
}
