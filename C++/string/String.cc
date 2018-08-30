#include<iostream>
#include<string.h>
using namespace std;
//深拷贝
//
class String
{

	friend ostream& operator<<(ostream& out, const String& s);
	public:
	String(const char* str)
	{
		_size = _capacity = strlen(str);
		_str = new char[_capacity+1];
		strcpy(_str, str);
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	String(const String& s)//拷贝构造现代写法
		:_str(NULL)
		 ,_size(0)
		 ,_capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);//
	}
	String& operator=(const String& s)
	{
		if(&s != this)
		{
			String tmp(s._str);
			this->Swap( tmp);
		}
		return *this;
	}
	char& operator[](size_t pos)//写,作左值
	{
		return _str[pos];
	}
	const char& operator[](size_t pos)  const//读 const 防止对象被修改
	{
		return _str[pos];
	}
	const char* c_str()
	{
		return _str;
	}
	void Expand(size_t n);
	void PushBack(char ch);
	void PushBack(const char* str);
	void Pop();
	void Insert(size_t pos, char ch); 
	void Insert( size_t pos, const char* str);
	void Erase(size_t pos, size_t n = 1);
	void Replace(char ch1, char ch2);
	void Replace(const char* sub1, const char* sub2);

	size_t Find(char ch) const;//后面加上const防止对象数据成员被修改
	size_t Find(const char* str) const; // ? 

	bool operator==(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator>(const String& s);
	bool operator>=(const String& s);
	String operator+(char ch);
	String operator+(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);

	~String()
	{
		delete[] _str;
		_size = _capacity =0;
		_str = NULL;
	}

	private:
	//	char buff[16];
	char* _str;
	size_t _size;
	size_t _capacity;
};

ostream& operator<<(ostream& out, const String& s)
{
	out<<s._str<<" "<<s._size<<" "<<s._capacity<<endl;
	return out;
}
void String::Expand(size_t n)
{
	char* newStr = new char[n+1];
	strcpy(newStr, _str);
	delete[] _str;
	_str = newStr;

	_capacity = n;
}
void String::PushBack(char ch)
{
	//	if(_size >= _capacity)
	//		Expand(2*_capacity);
	//	_str[_size++] = ch;
	//	_str[_size] = '\0';
	Insert(_size, ch);
}
void String::PushBack(const char* str)
{
	//size_t len = strlen(str);
	//if(_size + len > _capacity)
	//{
	//	Expand(_size + len);
	//}
	//strcpy(_str + _size, str);
	//_str[_size+len] = '\0';

	//_size+= len;
	Insert(_size, str);
}
bool String::operator==(const String& s)
{
	return strcmp(_str, s._str) == 0? 1:0;
}
bool String::operator<(const String& s) 
{
	return strcmp(_str, s._str)< 0? 1:0;
}
bool String::operator<=(const String& s) 
{
	return *this < s && *this == s;
}
bool String::operator>(const String& s) 
{
	return !(*this <= s);
}
bool String::operator>=(const String& s) 
{
	return !(*this < s);
}

String String::operator+(char ch)//返回一个原字符串加上一个字符的字符串
{
	String tmp(*this);
	tmp.PushBack(ch);
	return tmp;
}
String String::operator+(const char* str)
{
	String tmp(*this);
	tmp.PushBack(str);
	return tmp;
}
String& String::operator+=(char ch)
{
	this->PushBack(ch);
	return *this;
}
String& String::operator+=(const char* str)
{
	this->PushBack(str);
	return *this;
}
void String::Pop() 
{
	Erase(_size-1, 1);
}
void String::Insert(size_t pos, char ch) 
{
	if(pos > _size)
		return;
	if(_size >= _capacity)
		Expand(2*_capacity);

	for(int i = _size; i>= (int)pos; --i)
	{
		_str[i+1] = _str[i];
	}
	_str[pos] = ch;
	++_size;
}
void String::Insert(size_t pos,  const char* str) 
{
	if(pos > _size)
		return ;
	int len = strlen(str);
	if(_size + len > _capacity)
	{
		Expand(_size + len);	
	}
	//往后挪动	
	for(int i = _size; i>= (int)pos; --i)
	{
		_str[i+len] = _str[i];
	}
	//插入
	for(size_t i = 0; str[i] != '\0'; ++i)
	{
		_str[pos+i] = str[i];
	}
	_size+= len;
}
void String::Erase(size_t pos, size_t n) 
{
	if(pos > _size || n <=0) 
		return ;

	if(pos + n > _size)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		for(int i= pos+ n; i<= _size; ++i)
		{
			_str[i -n] = _str[i];
		}
		_size-= n;
	}
}
size_t String::Find(char ch) const 
{
	for(int i =0; _str[i] != '\0'; ++i)
	{
		if(_str[i] == ch)
			return i;
	}
	return -1;
}
size_t String::Find(const char* str) const // ? 
{
	if(str == NULL) return -1;

	const char* sub = str;	
	int  cur = 0;
	while(_str[cur] != '\0')
	{
		if(_str[cur] == *sub)
		{
			int i =1;
			for(; sub[i] != '\0'; ++i)
			{
				if(_str[cur+i] != sub[i])
					break;
			}
			if(sub[i] == '\0')
				return cur;
		}
		++cur;
	}
	return -1;
}


//void Replace(char ch1, char ch2) 
//void Replace(const char* sub1, const char* sub2) 


int main(void)
{
	//	String s1("change world");
	//	cout<<s1<<endl;
	//	//	s1.PushBack('!');
	//	//	cout<<s1<<endl;
	//	//	s1+= "right now!";
	//	//	cout<<s1<<endl;
	//
	//	String s2 = ("change myself");
	//	cout<<s2<<endl;
	//	cout<<"s1>=s2:"<<(s1 >= s2)<<endl;

	//	String s1("change world");
	//	cout<<s1<<endl;
	//    s1.Insert(0, 'x');
	//	cout<<s1<<endl;
	//	s1.Insert(0,"love");
	//String s1("change world");
	//s1.Erase(7, 3);
	//cout<<s1<<endl;

	String s1("abcdabce");	
	cout<<s1.Find("abce")<<endl;  // ? 
//	s1.Insert(3, "love");
//	cout<<s1<<endl;

//	String s1("change world");
	//s1[0] = 'x';
//	cout<<s1[0]<<endl;
	return 0;
}
