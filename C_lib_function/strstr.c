/*************************************************************************
  > File Name: strstr.c
  > Author: tp
  > Mail: 
  > Created Time: Thu 30 Aug 2018 01:50:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* Strstr(const char* str, const char* sub)
{ 
	if(str == NULL || sub == NULL)
		return NULL;

	char* pL = (char*)str; 
	char* pS = (char*)sub; 
	while(*pL != '\0'){ 
		char* subStart = pS;
		char* start = pL; 
		//注意：str=“abc”  sub=“abcde”这种情况
		while(*subStart == *start && *subStart && *start){ 
			++start; ++subStart;
		}
		if(*subStart== '\0')
			return pL; 
		++pL;
	}
	return NULL;
}
int main( )
{ 
	char buf[] = "change world";
	char sub[] = "ange";
	char sub1[] = "ane";
	char* ret = Strstr(buf, sub);     //ange world
	char* ret1 = Strstr(buf, sub1);   //NULL

	return 0;
}
