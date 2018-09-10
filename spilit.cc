//#include "common.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*Func: 字符串分割,提取参数放入vector或数组
 *
 * Why? oj题 输入输出有时真的难受，出题方不
 *		肯好好给出测试用例，强行在中间添加特
 *		殊字符来区分！
 *
 *		如这样给出一串要存入vector或数组的值：
 *			1,2,3,4,5 
 *		有木有特别烦？
 *		*/
//template <class T = string>
void Spilit(vector<string>& v, string& str, char delim)
{ 
	size_t pos = 0;
	while((pos=str.find(delim)) != string::npos){ 
		string tmp(str.begin(), str.begin()+pos);
		v.push_back(tmp);
		str.erase(str.begin(), str.begin()+pos+1);
	}
	v.push_back(str);
}

void Spilit(vector<int>& v, string& str, char delim)
{ 
	size_t pos = 0;
	while((pos=str.find(delim)) != string::npos){ 
		string tmp(str.begin(), str.begin()+pos);
		int x = atoi(tmp.c_str( ));
		v.push_back(x);
		str.erase(str.begin(), str.begin()+pos+1);
	}
	v.push_back(atoi( str.c_str()));
}

int main( )
{ 
	vector<string> v1;
	vector<string> v2;
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	Spilit(v1, str1, ','); 
	Spilit(v2, str2, ','); 
	
	cout<<v1[0]<<endl<<v1[1]<<endl;
	return 0;
}

