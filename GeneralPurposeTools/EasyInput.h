#ifndef EasyInput
#define EasyInput
#include <stdio.h>

void nullify(char *StringAdress,int Size){
	int i = 0;
	for(i = 0;i<Size;i++){
		*(StringAdress+i) = '\0';
	}
}

void read(char *InputPointer,int MaximumSize){
	fgets(InputPointer, MaximumSize, stdin);
}

void readEnhanced(char *InputPointer,int MaximumSize){
	fgets(InputPointer, MaximumSize, stdin);
	int i = 0;
	for(i = 0;i<MaximumSize;i++){
		if(*(InputPointer+i) == '\n'){
			*(InputPointer+i) = '\0';
			break;
		}
	}
}

#endif