#include "myas.h"

int main(int argc, char* argv[])
{
	char ifname[20];
	char ofname[20];
	char op[4];
	char args[256]; 
	char* mcode;  

	if(argc < 3){
		printf("Usage: myas input_file output_file\n");
		return 0;
	}

	strcpy(ifname, argv[1]);
	strcpy(ofname, argv[2]);

	FILE *ifp = fopen(ifname, "r");
	FILE *ofp = fopen(ofname, "w");

	mcode = (char*) malloc (sizeof(char)*20);

	while (!feof(ifp)){
		fscanf(ifp, "%s %s\n", op, args);

		// translate assembly into machine-code 
		if(!instr_trans(op, args, mcode)){
			printf("Error: %s %s cannot be translated\n", op, args);
			continue;
		}
		fprintf(ofp, "%s\n", mcode);
	}

	free(mcode);
	fclose(ifp);
	fclose(ofp);

	return 1;
}
