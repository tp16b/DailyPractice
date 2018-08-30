/*************************************************************************
  > File Name: strstr.c
  > Author: tp
  > Mail: 
  > Created Time: Thu 30 Aug 2018 01:50:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int Strcmp(const char* dst, const char* src)
{ 
	if(dst == NULL || src== NULL){ 
		perror( "invalid input");
		return 0;	
	}
	//转为unsigned char*类型。当有符号dst-src时，对于扩展字符
	//如 1- 129 结果为128而不是负数，如此答案不是我们想要的
	while(!(ret=*(unsigned char*)dst - *(unsigned char*)src)){ 
		if(dst == '\0') break;

		++dst; ++src;
	}
	return ret;
}
int main( )
{ 
	int ret;
	char buf[] = "change world";
	const char* src1= "change world";
	const char* src2= "change world!";
	const char* src3= "change"; 
	ret =Strcmp(buf, src1);  //0
	ret =Strcmp(buf, src2);  //-1 
	ret =Strcmp(buf, src3);  //1
	return 0;
}
