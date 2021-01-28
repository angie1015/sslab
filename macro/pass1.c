#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	FILE *inp, *argtab, *namtab;
	char la[10], mne[10], opnd[10];
	inp = fopen("inp.txt", "r");
	argtab = fopen("argtab.txt", "w");
	namtab = fopen("namtab.txt", "w");
	fscanf(inp, "%s %s %s", la, mne, opnd);
	while(strcmp(mne, "MEND")!=0){
		if(strcmp(mne, "MACRO")==0){
			fprintf(namtab, "%s\n", la);
			fprintf(argtab, "%s\t%s\n", la, opnd);
		}else
			fprintf(argtab, "%s\t%s\n", mne, opnd);
		fscanf(inp, "%s %s %s", la, mne, opnd);
	}
	fprintf(argtab, "%s", mne);
	fclose(inp); fclose(argtab); fclose(namtab);
	printf("Pass 1 is completed");
}
