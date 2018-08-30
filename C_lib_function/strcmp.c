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
	//转为unsigned char*类型。有符号dst-src. 
	//如 1- 129 结果为128不是负数，答案错误
	while(!(ret=*(unsigned char*)dst - *(unsigned char*)src)){ 
		if(dst == '\0') break;

		++dst; ++src;
	}
	return ret;
}
int main( )
{ 
	char buf[] = "change world";
	char a = 1;
	char b = 129;
	printf( "a-b= %d\n", a-b);
	return 0;
}
