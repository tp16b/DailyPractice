#include "common.h"
#include "mobile_semantic.h"
//(****) lambda 表达式 一种匿名的函数, 追踪返回值类型定义返
//回值。虽然危险，但是爱问
//函数式编程 有些公司禁止使用->导致代码可读性，可维护性很差
//
//语法：[捕获列表]->return_type{ statement}
void test4( ){	
	//返回值明确，size_t可以删除
	auto sum = [](size_t x, size_t y)->size_t{ return x+y;}; 
	cout<<sum(10, 20)<<endl;

	int a=3,b=4;
	//	auto mul= [a, b]{return a*b; }; //以值传递方式，传入a，b
	//	cout<<mul()<<endl; //12   <=>
	auto mul1= [=]{  return a*b;}; //以值传递方式，传入a，b
	cout<<mul1()<<endl; //12

	a=3; b=4;
	auto change = [&a, b]{++a; /*--b;  报错，b只能读*/};
	change( );     
	cout<<a<<endl; //4
}

/*lambda表达式应用场景:  
 *
 * 比如打印一些内容状态，或者进行一些内部操作，这些功能不能与其他的代码共享，
 * 却要在一个函数中多次重用，比如：代码中可能要经常打印vector中内容，但该部
 * 分功能其他函数又不需要，就可使用lambda来封装内部函数
 *
 * 没有引入lamb函数前，上面功能只有封装函数来实现，考虑到函数作用域和效率
 * 通常又会在函数前加上static和inline等关键字，否则就有建立额外函数栈帧
 * 的开销。
 * 引入lamb函数，其捕捉列表可以让我们不必关心函数参数的个数和传递方式；同
 * 时，一旦调用lamb的主函数结束，lamb函数也就结束了，代码实现更加简洁明了
 * */
void test4_1( )
{ 
	vector<int> v{1, 2, 3, 4 } ;
	auto Print = [](vector<int>& v)
			{ 
				for( auto& e:v) 
					cout<<e<<" ";
			};
	//利用 lamb 函数打印 vector 中内容
	Print( v) ;
	cout<<endl;
	//给 vector 中每个成员 *2
	for( auto& e : v) 
		e *= 2;
	//检测是否打印成功
	Print( v);
}

/*继承构造函数& 委派构造
 * */
//1. 继承构造：
class A{ 
public:
	A(int a, int b = 0) :_x(a),_y(b) { }
	A(int a, int b, int c) :_x(a),_y( b) { }
protected:
	int _x;
	int _y;
};
class B :public A{ 
public:
	using A::A;

	void show( ){ 
		cout<<"_x="<<A::_x<<" _y="<<A::_y<<" "<<_b<<endl;
	}
	int _b{1};
};
void test5( )
{ 
	B b(99);
	b.show( ); //99 0 1
}
int main( )
{ 
	//test2( );
	//test3( );
//	test4( );
	//test4_1( );
	//test5( );
	test6( );
	return 0;
}
//struct Pos{ 
//	int x;
//	int y;
//	Pos(int a, int b): x(a),y( b) { }
//};
//void test1( )
//{ 
//	pair<int, bool> pr{10, false};
//	auto a = Pos(1,2) ;
//	auto b = pr;
//	auto c= 10.10;
//	cout<<typeid(a).name( )<<endl;
//	cout<<typeid(b).name( )<<endl;
//	cout<<typeid(c).name( )<<endl;
//}
//
//int* func(int x) 
//{ 
//	return new int[10];
//}
//void test2( )
//{ 
//	decltype(func(99)) e;
//	cout<<typeid(e).name()<<endl;
//}
//
//
//
//void test3( )
//{ 
//	vector<int> v{ 1,2,4,5,6,6,11};
//	for( auto& e : v)
//		cout<<e<<" ";
//	cout<<endl;
////	for(int e: v)
////		cout<<e<<" ";
//	map<string , int> mp{ {"sort", 1},{ "insert", 2}};
//	for( auto& e: mp)
//		cout<<e.first<<" ";
//}
