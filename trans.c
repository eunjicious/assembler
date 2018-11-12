#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	char* sr;
	char* dest;
	char* str=args;
	sr=strtok(str,",");
	str=strtok(NULL,",");
	dest=strtok(str,",");
	if(sr[0]=='%'){
		if(dest[0]=='%'){
			strcpy(mcode,"89");
		}
		else if(dest[0]=='0')
		{
			strcpy(mcode,"a3");
		}
	}
	else if(sr[0]=='('){
		strcpy(mcode,"8b");
	}
	else if(sr[strlen(sr)-1]==')'){
		strcpy(mcode,"8b");
	}
	else if(sr[0]=='0'){
		if(strstr(dest,"%e"))
			strcpy(mcode,"a1");
	}
	else if(sr[0]=='$'){
		if(strcmp(dest,"%eax"))
			strcpy(mcode,"b8");
		else if(strcmp(dest,"%ecx"))
			strcpy(mcode,"b9");
		else if(strcmp(dest,"%edx"))
			strcpy(mcode,"ba");
		else if(strcmp(dest,"%ebx"))
			strcpy(mcode,"bb");	
		else if(strcmp(dest,"%esp"))
			strcpy(mcode,"bc");
		else if(strcmp(dest,"%ebp"))
			strcpy(mcode,"bd");
		else if(strcmp(dest,"%esl"))
			strcpy(mcode,"be");
		else if(strcmp(dest,"%edl"))
			strcpy(mcode,"bf");
	}
	else
		return 0;

	
	return 1;	
}
