#include<iostream>
#include<string.h>
using namespace std;

//String类的浅拷贝
class String
{
	public:
		String(const char* str = "")
			:_str(new char[strlen(str)+ 1])
			,_pCount(new int(1))
			{
				strcpy(_str, str);
			}
		//s2(s1)
		String(const String& s)
			:_str(s._str)
			 ,_pCount(s._pCount)
		{
			++(*_pCount);	
 		}
		//s3 = s1
		String& operator=(const String& s)
		{
			if(_str != s._str)
			{
				this->Release();
				_str = s._str;
				_pCount = s._pCount;
				++(*_pCount);
			}
		}
		char& operator[](size_t pos)
		{
			if(pos < strlen(_str))
			{
				//if(*_pCount > 1)
					CopyOnWrite();
				return _str[pos];
			}
		}
		const char operator[](size_t pos) const //防止该函数修改对象的属性
		{
			if(pos < strlen(_str))
			{
				return _str[pos];
			}
		}
		//需要修改对象的属性时，需要为对象新开辟一块空间
		//否则会影响其他对象的属性 
		void CopyOnWrite() //写时拷贝
		{
			char* newStr = new char[strlen(_str)+1];
			strcpy(newStr, _str);
			Release();  //先拷贝
			_str = newStr;
			_pCount = new int(1); 
			
		}
		void Release()
		{
			//cout<<"引用计数："<<*_pCount<<endl;
			if(--(*_pCount) == 0)
			{
				delete[] _str;
				delete _pCount;
			}
		}
		const char* c_str() const
		{
			return _str;
		}
		void Show()
		{
			cout<<" "<<*_pCount<<endl;
		}
		~String()
		{
			Release();	
		}
	private:
		char* _str;
		int* _pCount;
};



int main(void)
{
	String s1("change world");
//	for(int i = 1; i<10; ++i)
//	{
//		String s(s1);
//		cout<<s.c_str()<<endl;
//	}

	String s2(s1);
//	cout<<"s2:"<<s2.c_str()<<endl;
	String s3 = s1;
	s3[0] = 'W';       //写会调用拷贝构造	
	cout<<s3[0]<<endl;  //读都会调用拷贝构造
	cout<<"s2:"<<s2.c_str()<<endl;
	cout<<"s3:"<<s3.c_str()<<endl;

	return 0;
}
