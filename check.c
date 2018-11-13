#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char sr_ch[128];
	char dest_ch[128];
	int i;
	int j;
	for(i=0;i<strlen(args);i++)
	{
		if(args[i]==','){
			i++;
			break;
		}
		sr_ch[i]=args[i];
	}
	for(j=i;j<strlen(args);j++)
		dest_ch[j-i]=args[j];
	if(dest_ch[0]=='$')
		return 0;
	if(sr_ch[0]=='('||sr_ch[0]=='0'||sr_ch[0]=='-')
		if(dest_ch[0]=='('||dest_ch[0]=='0')
			return 0;

	return 1;
}
