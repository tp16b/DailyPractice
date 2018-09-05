#pragma once

/* 简单模拟 vector 容器
*/

#include <iostream>
using namespace std;

#include <cstring>

//暂时忽略配置器
template <class T /*, class Alloc=alloc*/>
class Vector
{ 
public:
	Vector( ) :_start(NULL),_finish( NULL),_end_of_storage(NULL) { }
	Vector(size_t num, const T& x);

	Vector(const Vector<T>& v );
	Vector& operator=(const Vector<T>& v );
	T& operator[](size_t pos){
		if( pos < Size())
			return _start[pos];
	}

	//增
	void PushBack(const T& x){ 
		Insert(Size( ), x);
	} 
	void Insert(size_t pos, const T& x);   //返回值原为iterator
	void Insert(size_t pos, size_t num, const T& x);
	//删
	void Erase(size_t pos);
	void Erase(size_t pos, size_t num);

	size_t Find() const;
	bool Empty( ) const{ 
		if(_start == _finish)
			return false;
		return true;
	}
	void Reserve(size_t n){ 
		if(n > Capacity( )){ 
			size_t size = Size( );
			T* new_start = new T[n];		
			Uninit_Copy(_start, _finish, new_start);
		}
	} 
	void Resize(size_t n, const T& x=T())
	{
		if( n > Size()){ 
			if((Size()<<1) > n ) 
				n = Size()<<1;

			Insert(Size()-1, n-Size(), x);
		} 
		_finish = _start+n;  //改变Size()
	} 
	size_t Size( ) const     {return _finish- _start;}
	size_t Capacity( ) const {return _end_of_storage -_start;}

	//copy 、fill
	T* Uninit_Copy(const T* start, const T* finish, T* new_start) const;	
	T* Uninit_Fill_N(T* start, size_t n, const T& x);	

	void Release( ){ 
		delete[] _start; 
		_start=_finish =_end_of_storage = NULL;
	}
	~Vector(){
		cout<<"~Vector( )\n";
		Release( );
	}

	void Print( ) const{ 
		if( _start != NULL){ 
			for( int i=0;i < Size( ); ++i)  
				cout<<_start[i]<<" ";
		}
		cout<<endl;
	}
protected:
	T* _start;
	T* _finish;
	T* _end_of_storage;
};

template<class T>
T* Vector<T>::Uninit_Copy(const T* start, 
		const T* finish, T* new_start) const
{ 
	size_t size = finish - start;
	memcpy(new_start, start, sizeof(T)*size);	
	return new_start + size;
}

template<class T>
T* Vector<T>::Uninit_Fill_N(T* start, size_t n, const T& x) 	
{ 
	//返回填充后的finish
	if(start != NULL){ 
		for( int i=0; i< n; ++i)  
			start[i] = x;
	}
	return start+ n;
}

template <class T /*, class Alloc=alloc*/>
Vector<T>::Vector(const Vector<T>& v ) 
	:_start( NULL),_finish( NULL),_end_of_storage( NULL)
{ 
	if(v.Size( ) > 0){ 
		_start = new T[v.Capacity()];
		Uninit_Copy(v._start, v._finish, _start); //v._start  能访问？

		_finish = _start+ v.Size( );
		_end_of_storage = _start+ v.Capacity( );
	}	
}

template <class T /*, class Alloc=alloc*/>
Vector<T>& Vector<T>::operator=(const Vector<T>& v ) 
{ 
	swap(_start, v._start);		
	swap(_finish, v._finish);		
	swap(_end_of_storage, v._end_of_storage);		
	return *this;
}

template <class T /*, class Alloc=alloc*/>
void Vector<T>::Insert(size_t pos, const T& x) 
{ 
	if(pos > Size())    
		throw out_of_range( "invalid position!");

	//扩容
	if(_finish == _end_of_storage){ 
		if(_start == NULL){ 
			_start = new T[1];
			_start[pos] = x;

			_finish = _start+1;
			_end_of_storage= _start+ 1; 
		}else{ 
			size_t size = Size( );
			T* tmp = new T[size*2];			
			T* new_finish = Uninit_Copy(_start, _start+pos, tmp);
			new_finish = Uninit_Fill_N(tmp+pos, 1, x);
			new_finish = Uninit_Copy(_start+pos, _finish, new_finish);

			Release( );
			_start = tmp;
			_finish = new_finish; 
			_end_of_storage= _start + size*2;
		}
	}else{ 
		//普通插入
		int end = Size()-1;
		while(end >= (int)pos ){
			_start[end+1] = _start[ end];
			--end;
		} 
		_start[pos] = x;
		++_finish;
	}	
}

template <class T /*, class Alloc=alloc*/>
void Vector<T>::Insert(size_t pos, size_t num, const T& x) 
{ 
	size_t size = Size( );
	if(pos > size) throw out_of_range( "Invalid Enter");

	if(size+num >= Capacity()){//扩容 

		if( _start == NULL){ 

			_start = new T[num];
			_finish = _end_of_storage = Uninit_Fill_N(_start, num, x);
		}else{ 
			size_t new_size = Capacity()<<1;
			while(size+num > new_size ) 
				new_size <<= 1;
			T* tmp = new T[new_size];

			T* new_finish = Uninit_Copy(_start, _start+pos, tmp);
			new_finish = Uninit_Fill_N(new_finish, num, x);
			new_finish = Uninit_Copy(_start+pos, _finish, new_finish);

			Release();
			_start = tmp;
			_finish = new_finish; 
			_end_of_storage = _start + new_size; 
		}
	}else{//普通情况 
		int end = size-1;
		while(end >= (int)pos){
			_start[end+num] = _start[end];
			--end;
		} 
		Uninit_Fill_N(_start+pos, num, x);	

		_finish = _finish+ num;
	}
} 
template<class T>
void Vector<T>::Erase(size_t pos) 
{ 
	if( pos >= Size( ))  
		throw out_of_range("Invalid entering");

	for( int i=pos+1; i < Size( ); ++i){ 
		_start[i-1] = _start[i];
	}

	--_finish;
}











