#include<iostream>
#include<string.h>

using namespace std;

class String
{
	public:
		String(const char* str = " ")
			:_str(new char[strlen(str) + 5])
		{
			strcpy(_str +4, str);
			_str = _str+4;
			GetRefCount() = 1;
		}
		//s2(s1)
		String(const String& s)
			:_str(s._str)
		{
			++GetRefCount();
		}
		//s3(s1)
		String& operator=(const String& s)
		{
			if(_str != s._str)
			{
				this->Release();   //s2对象引用计数可能只有1
				_str = s._str;
				++GetRefCount();
				return *this;
			}
		}
		char& operator[](size_t pos)
		{
			if(pos < strlen(_str))
			{
				//if(GetRefCount() > 1)  //该空间的对象数不止一个才拷贝
					CopyOnWrite();
				return _str[pos];
			}
		}
		const char operator[](size_t pos) const
		{
			if(pos < strlen(_str))
				return _str[pos];
		}
		void CopyOnWrite()
		{
			char* newStr = new char[strlen(_str)+5];
			strcpy(newStr, _str);
			//--GetRefCount();
			Release();
			_str = newStr;
			GetRefCount() = 1;
			
		}
		int& GetRefCount()
		{
			return *((int*)(_str-4));
		}
		void Release()
		{
			if(--GetRefCount() == 0)
			{
				delete[] (_str-4);
			}
		}
		const char* c_str()
		{
			return _str;
		}
		~String()
		{
			Release();
		}
	private:
		char* _str;
};
int main(void)
{
	String s1("change world");
	String s2(s1);
	cout<<"s2: "<<s2.GetRefCount()<<s2.c_str()<<endl;
	String s3("hello world");
	s3 = s1;
	cout<<"s3: "<<s3.GetRefCount()<<s3.c_str()<<endl;

	s3[0] = 'W';
 	cout<<s3[0]<<endl;
	return 0;
}
