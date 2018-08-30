#include<stdio.h>

typedef void (*FUN)();

typedef struct A
{
	FUN _f;
	int _a;
}A;
typedef struct B
{
	A a;
	int _b;
}B;

void _fA()
{
	printf("_fA()\n");
} 
void _fB()
{
	printf("_fB()\n");
}

int main()
{
	A a;
	B b;
	//实现继承
	a._f = _fA;
	b.a._f = _fB;
	a._f();
	b.a._f();
	
	//实现多态
	A* p = &a;
	p->_f();
	p = (A*)&b;	
	p->_f();
	return 0;
}
