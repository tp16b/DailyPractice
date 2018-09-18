#pragma once

#include "common.h"
/*移动语义实现
 *
 * 解决问题：深拷贝等传值过程中,调用拷贝构造生成临时对象方式赋值的效率问题
 *
 * 原理：移动语义+右值引用 方式进行实现资源的转移
 * move() : 强制将一个左值move为右值, move要作用与声明周期即将到期的对象
 * */
void test6( )
{ 
	string s1("change ");
	string s2("world");
	string&& s3 = s1+s2;
	cout<<s3<<endl;

	string&& s4 = move(s1);  //典型的错误用法，move应作用于即将失效的变量
	s4[0] = 'A';
//	s1[0] = 'B';
	cout<<"s4: "<<s4<<endl;
	cout<<"s1: "<<s1<<endl;
}

