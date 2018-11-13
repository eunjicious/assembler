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

	
	return 1;	
}
