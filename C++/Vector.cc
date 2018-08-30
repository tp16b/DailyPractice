#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
typedef int DataType;
class Vector
{
private:
		DataType* _start;
		DataType* _finish;
		DataType* _endStorage;
public:
		Vector()
			:_start(NULL)
			 ,_finish(NULL)
			 ,_endStorage(NULL)
	{}
		Vector(const Vector& v)
		{
			if(v.Size() > 0)
			{
				_start = new DataType[v.Size()];
				memcpy(_start, v._start, sizeof(DataType)*v.Size());

				_finish = _start + v.Size();
				_endStorage = _start + v.Size();
			}
			else
				_start = _finish = _endStorage = NULL;
		}
		//v1 = v2
		Vector& operator=( Vector v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endStorage, v._endStorage);

			return *this;
		}
		void Expand(size_t n);
		void PushBack(DataType x);
		void PopBack();
		void Insert(size_t pos, DataType x);
		void Erase(size_t pos);
		void Reverse(size_t n);
		size_t Find(DataType x) const;
		void Print() const;
		~Vector()
		{
			delete[] _start;
			_start = _finish = _endStorage = NULL;
		}
		size_t Size() const
		{
			return _finish - _start;
		}
		size_t Capacity() const
		{
			return _endStorage - _start;
		}
};
void Vector::Expand(size_t n)	
{
	size_t size = Size();
	DataType* tmp = new DataType[n];
	if(_start)
	{
		memcpy(tmp, _start, sizeof(DataType)*Size());
		delete[] _start;
	}

	_start = tmp;
	_finish = tmp + size;
	_endStorage = tmp + n;
}
void Vector::PushBack(DataType x)
{
	Insert(Size(), x);
}
void Vector::PopBack()
{
	Erase(Size()-1);
}		
void Vector::Insert(size_t pos, DataType x) 
{
	assert(pos <= Size());

	if(_finish == _endStorage)
	{
		if(Capacity() == 0)
			Expand(4);
		else
			Expand(Capacity() *2);
	}
	int end = Size() -1;
	//pos 到end位置值往后移
	while(end >= (int)pos)
	{
		_start[end +1] = _start[end];
		--end;
	}
	_start[pos] = x;
	++_finish;
}
void Vector::Erase(size_t pos) 
{
	assert(pos < Size());
	int cur = pos;
	while(cur < Size()-1)
	{
		_start[cur] = _start[cur+1];
		++cur;
	}
	--_finish;
}

void Vector::Reverse(size_t n) 
{
	assert( n >=0);

	DataType* begin = _start;
	DataType* end = _start+n-1;
	while(begin < end)
	{ 
		swap(*begin, *end);
		++begin; --end;
	}
}
size_t Vector::Find(DataType x) const 
{
	for(int i = 0; i < Size(); ++i)
	{
		if(_start[i] == x)
			return i;
	}
	return 0;
}

void Vector::Print() const 
{
	for(int i =0; i< Size(); ++i)
		cout<<_start[i]<<" ";
	cout<<endl;
}
int main(void)
{
	Vector v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PopBack();
	//	cout<<v.Find(4)<<endl;
	v.Print();
	cout<<v.Capacity();
	cout<<v.Size()<<endl;
	Vector v1(v);
	v1.Print();

	Vector v2;
	v2 = v1;
	v2.Print();
	v2.Reverse(5);
	v2.Print( );
	return 0;
}
