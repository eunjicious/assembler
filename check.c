#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char *sr;
	char* dest;
	char* str=args;	
	sr=strtok(str,",");
	str=strtok(NULL,",");
	dest=strtok(str,",");

	if(!strcmp(op,"movl"))
		return 0;
	if(strstr(dest,"$"))
		return 0;
	if(strstr(sr,"(")||strstr(sr,"0x"))
		if(strstr(dest,"(")||strstr(dest,"0x"))
			return 0;
	
	return 1;
}
