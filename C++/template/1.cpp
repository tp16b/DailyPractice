/*************************************************************************
  > File Name: 1.cc
  > Author: tp
  > Mail: 
  > Created Time: Sun 13 May 2018 09:56:15 AM CST
 ************************************************************************/

#include "1.h"

//template<class T>
//void A<T>::show( )
//{ 
//	cout<<a<<endl;
//}
//template <class> A<int> a;

template<class T>
void Swap(T& a, T& b) 
{ 
	T tmp = a;
	a = b;
	b = tmp;
}
template void Swap<int>(int& a, int& b);//显示实例化 


