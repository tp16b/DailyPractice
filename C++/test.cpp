#include<iostream>
#include<stdio.h>
using namespace std;

//class A
//{
//	public:
//		virtual void f1()
//		{
//			cout<<"A::f1()"<<endl;
//		}
//		virtual void f2()
//		{
//			cout<<"A::f2()"<<endl;
//		}
//	protected:
//		int _a;
//
//};
//class B:public A
//{
//	public:
//		virtual void f1()
//		{
//			cout<<"B::f1()"<<endl;
//		}
//		virtual void f3()
//		{
//			cout<<"B::f3()"<<endl;
//		}
//	private:
//		int _b;
//};
//
//typedef void (*FUN)();
//void PrintTable(int** pTable)
//{
//	if(pTable == NULL)
//		return ;
//	printf("Table:%p\n", pTable);
//	for(int i = 0; pTable[i] != 0; ++i)
//	{
//		printf("vf[%d]: %p->", i, pTable[i]);
//		FUN f = (FUN)pTable[i];
//		f();
//	}
//}

//实现一个不能被继承的类
class AA
{	
	public:
		static AA* GetAAObject()
		{
			return new AA;
		}
	private: AA()
		{}
		int _a;			
};
class A
{
	public:
		static A GetAObject()
		{
			return A();
		}
	private:
		A() {}
		int _a;
};
class BB : public AA
{
	public:

	private:
		int _b;
};
int main(void)
{
	//	A a;
	//	PrintTable((int**)(*((int**)&a)));
	//B b;	
	//PrintTable((int**)(*((int**)&b)));  //int** 旨在利用当前环境指针大小来进行强转，
	AA* p = AA::GetAAObject();
//	BB b;
	
	A a = A::GetAObject(); 
	return 0;
}
