/*************************************************************************
  > File Name: Vector.h
  > Author: tp
  > Mail: 
  > Created Time: Sun 06 May 2018 11:15:04 AM CST
 ************************************************************************/
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

//类型萃取
struct __TrueType { bool Get(){ return true;} };
struct __FalseType { bool Get(){ return false;} };

template <class T>
struct TypeTraits 
{ 
	typedef __FalseType __IsPodType; //默认为false
};
template <>
struct TypeTraits <int>
{ 
	typedef __TrueType __IsPodType;
};
template <>
struct TypeTraits <char>
{ 
	typedef __TrueType __IsPodType;
};
template<typename T>
class Vector
{ 
	public:
		Vector()
			:_start(NULL) 
		{ 
			_finish = _endOfStorage = _start;
		}
		Vector( const Vector<T>& v);
		Vector<T>& operator=(Vector<T> tmp);
		T& operator[]( size_t pos);
		const T& operator[]( size_t pos) const;

		void PushBack(const T& x);
		void PopBack();
		void Expand(size_t n);
		void Insert(size_t pos, const T& x);
		void Erase( size_t pos);
		size_t Find(const T& x) const ; 
		bool Empty() const;
		size_t Size( ) const 
		{ 
			return _finish - _start;
		}
		size_t Capacity( ) const
		{ 
			return _endOfStorage - _start;
		}
		void Print() const;

		~Vector( )
		{ 
			delete[] _start;
			_start = _finish = _endOfStorage = NULL;
		}
	protected:
		T* _start;
		T* _finish;
		T* _endOfStorage;
};

//v2( v1)
template<class T>
Vector<T>::Vector(const Vector<T>& v) //拷贝构造 
	:_start( new T[ v.Capacity()])
{ 
	//BUG !!!
	//memcpy(_start, v._start, sizeof(T)* v.Size());
	
	if(TypeTraits<T>::__IsPodType().Get()) //内置类型
		memcpy(_start, v._start, sizeof(T)* v.Size());
	else
	{ 
		for(size_t i =0; i < v.Size(); ++i)
			_start[i] = v[i];
	}
	_finish = _start + v.Size();
	_endOfStorage = _start +v.Capacity();
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T> tmp) 
{ 
	swap(tmp._start, _start);
	_finish = tmp._finish;
	_endOfStorage = tmp._endOfStorage;
}
template<class T>
T& Vector<T>::operator[](size_t pos) 
{ 
	assert(pos < Size());

	return _start[pos];	
}

template<class T>
const T& Vector<T>::operator[](size_t pos) const
{ 
	assert(pos < Size());

	return _start[ pos];
}

template<class T>
void Vector<T>::PushBack(const T& x)
{ 
	Insert(Size(), x);
}
template<class T>
void Vector<T>::PopBack()
{ 
	Erase(Size()-1);
}
template<class T>
void Vector<T>::Expand(size_t n)
{ 
	size_t size = Size( );
	T* newstart = new T[n];
	if(_start)
	{ 
		//BUG !!!
		//存储数据是string发生浅拷贝问题
		//memcpy(newstart, _start, Size()*sizeof( T));
		if(TypeTraits<T>::__IsPodType().Get())
			memcpy(newstart, _start, Size()*sizeof( T));

		else{ //正确写法
			for(size_t i =0; i < size; ++i)
			{ 
				newstart[i] = _start[i];
			}
		}
		delete[] _start;
	}

	_start = newstart;
	_finish = _start + size;
	_endOfStorage = _start + n;
}
template<class T>
void Vector<T>::Insert(size_t pos, const T& x)
{ 
	assert(pos <= Size()); 

	if( _finish == _endOfStorage)
	{ 
		if(_finish == NULL)
			Expand( 3);
		else
			Expand( 2*Capacity());
	}
	T* end = _finish-1;
	while(end >= pos+_start)
	{ 
		*(end+1) = *end;
		--end;
	}
	_start[pos] = x;

	++_finish;
}
	template <class T>
void Vector<T>::Erase( size_t pos)
{ 
	assert( pos < Size( ));

	size_t begin  = pos;
	while( begin < Size()-1)
	{ 
		_start[begin] = _start[ begin+1];
		++begin;
	}
	--_finish;
}
template<class T>
size_t Vector<T>::Find(const T& x) const  
{ 
	for(size_t i =0; i< Size( ); ++i)
	{ 
		if( _start[ i] == x)
			return i; 
	}
	return 0;
}

template<class T>
void Vector<T>::Print( ) const
{ 
	for(size_t i = 0; i < Size(); ++i)
		cout<<_start[i]<<" ";		
	cout<<endl;
}

void Test()
{ 
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	cout<<"Size:"<<v.Size()<<" Capacity:"<<v.Capacity( )<<endl;
	v.Print();


	Vector<string> v1;
	v1.PushBack("hello");
	v1.PushBack("11111111111111111111111");
	v1.PushBack("gg=G");
	v1.PushBack("222222222222222");
	cout<<"Size:"<<v1.Size()<<" Capacity:"<<v1.Capacity( )<<endl;
	v1.Print();

	Vector<string> vv(v1);
	vv.Print();

	Vector<string> v2;
	v2 = v1;
	v2.Print( );
	cout<<v2.Find("gg=G")<<endl;
}

#endif  //__VECTOR_H__
