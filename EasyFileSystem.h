#ifndef EASY_FILE_SYSTEM
#define EASY_FILE_SYSTEM

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "EasyText.h"

#define FILE_TEXT_EXTENTION ".txt"

EasyText* easyReadFile(char* path,int linesAmount,int lineSize){
    FILE* fptr = fopen(path,"r");
    
    if(fptr == NULL){
        return NULL;
    }

    EasyText* output = newEasyText(linesAmount,lineSize);

    if(output == NULL){
        close(fptr);
        return NULL;
    }

    int i = 0;
    for(i = 0;i<linesAmount && !feof(fptr);i++){
        fgets(output->text[i],lineSize,fptr);
    }

    close(fptr);

    return output;
}

void easyWriteFile(char* path,EasyText* et){
    FILE* fptr = fopen(path,"w");

    if(fptr == NULL){
        return;
    }

    char* bigText = toEasyBigText(et);

    fprintf(fptr,bigText);

    free(bigText);

    close(fptr);
}

void easierWriteFile(char* path,char* content){
    FILE* fptr = fopen(path,"w");

    if(fptr == NULL){
        return;
    }

    fprintf(fptr,content);

    close(fptr);
}

#endif