/*************************************************************************
  > File Name: memove.c
  > Author: tp
  > Mail: 
  > Created Time: Wed 29 Aug 2018 03:14:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void* Memove(void* dst, const void* src, size_t n )
{ 
	if(dst == NULL || src == NULL)
		return NULL;
	if(n == 0) return dst;

	//不考虑n值过大的问题，由用户自行负责
	char* pdst = (char*)dst;
	char* psrc= (char*)src;
	if(pdst <= psrc){ 
		for( int i =0; i< n; ++i){ 
			*pdst++ = *psrc++;
		}
	}else{ 
		pdst += n-1; 
		psrc += n-1; 
		for(int i =0; i< n; ++i){ 
			*pdst-- = *psrc--;
		}
		++pdst;
	}
	return (void*)pdst;
}

int main( )
{ 
	char buf[13] = "abcd1234";
	printf( "before: %s ", buf);
	char* ret = (char*)Memove((void*)(buf+4), (void*)buf, sizeof(buf)-1);
	printf( "after: %s\n", ret);
	return 0;
}
