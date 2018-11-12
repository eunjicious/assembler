#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char* sr_check;
	char* dest_check;
	char* str_check=args;	
	sr_check=strtok(str_check,",");
	str_check=strtok(NULL,",");
	dest_check=strtok(str_check,",");

	if(!strcmp(op,"movl"))
		return 0;
	if(dest_check[0]=='$')
		return 0;
	if(sr_check[0]=='('||sr_check[0]=='0')
		if(dest_check[0]=='('||dest_check[0]=='0')
			return 0;
	
	return 1;
}
