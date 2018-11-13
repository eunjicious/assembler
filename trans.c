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
		if(dest[2]=='a'&&dest[3]=='x')
		{
			strcpy(mcode,"a1");
		}
	}
	else if(sr[0]=='$'){
		if(dest[2]=='a'&&dest[3]=='x')
			strcpy(mcode,"b8");
		else if(dest[2]=='c'&&dest[3]=='x')
			strcpy(mcode,"b9");
		else if(dest[2]=='d'&&dest[3]=='x')
			strcpy(mcode,"ba");
		else if(dest[2]=='b'&&dest[3]=='x')
			strcpy(mcode,"bb");
		else if(dest[2]=='s'&&dest[3]=='p')
			strcpy(mcode,"bc");
		else if(dest[2]=='b'&&dest[3]=='p')
			strcpy(mcode,"bd");
		else if(dest[2]=='s'&&dest[3]=='i')
			strcpy(mcode,"be");	
		else if(dest[2]=='d'&&dest[3]=='i')
			strcpy(mcode,"bf");
	}
	else strcpy(mcode,"error");
	return 1;	
}
