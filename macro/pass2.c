#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	FILE *inp, *argtab, *namtab, *atab2, *op2;
	char la[10], mne[10], opnd[10], mne1[10], opnd1[10], name[10], arg[10];
	inp = fopen("inp.txt", "r");
	argtab = fopen("argtab.txt", "r");
	namtab = fopen("namtab.txt", "r");
	atab2 = fopen("atab2.txt", "w+");
	op2 = fopen("op2.txt", "w");
	fscanf(inp, "%s %s %s", la, mne, opnd);
	while(strcmp(mne, "END") != 0){
		if(strcmp(mne, "MACRO")==0){
			fscanf(inp, "%s %s %s", la, mne, opnd);
			while(strcmp(mne, "MEND")==0)
				fscanf(inp, "%s %s %s", la, mne, opnd);

		}else{
			fscanf(namtab, "%s", name);
			if(strcmp(name, mne) != 0)
				fprintf(op2, "%s\t%s\t%s\n", la, mne, opnd);
			else{
				int len = strlen(opnd);
				for(int i=0; i<len; i++){
					if(opnd[i]!=',')
						fprintf(atab2, "%c", opnd[i]);
					else
						fprintf(atab2, "\n");
				}
				fseek(namtab, SEEK_SET, 0);
				fseek(atab2, SEEK_SET, 0);
				fscanf(argtab, "%s %s", mne1, opnd1);
				fprintf(op2, ".\t%s\t%s\n", mne1, opnd);
				fscanf(argtab, "%s %s", mne1, opnd1);
				while(strcmp(mne1, "MEND")!=0){
					if(opnd1[0] == '&'){
						fscanf(atab2, "%s", arg);
						fprintf(op2, "-\t%s\t%s\n", mne1, arg);
					}else
						fprintf(op2, "-\t%s\t%s\n", mne1, opnd1);
					fscanf(argtab, "%s %s", mne1, opnd1);
				}
			}
		}
	fscanf(inp, "%s %s %s", la, mne, opnd);
	}
	fclose(inp); fclose(argtab); fclose(namtab); fclose(atab2); fclose(op2);
	printf("Pass 2 completed");
	
}
