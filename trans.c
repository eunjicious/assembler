#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}
	char *sr,*dest;
	char* str=args;
	sr=strtok(str,",");
	str=strtok(NULL,",");
	dest=str;
	printf("%s %s\n",sr,dest);
	if(sr[0]=='%'&&sr[1]=='e'){
		if(dest[0]=='%'&&dest[1]=='e')
			strcpy(mcode,"89");
		else if(dest[0]=='0'&&dest[1]=='x')
			strcpy(mcode,"a3");
	}
	else if(sr[0]=='('||sr[strlen(sr)-1]==')')
	{
		strcpy(mcode,"8b");
	}
	else if(sr[0]=='0'&&sr[1]=='x')
	{
		if(strcmp(dest,"%eax"))
		{
			strcpy(mcode,"a1");
		}
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
	return 1;	
}
