#ifndef EASY_FILE_SYSTEM
#define EASY_FILE_SYSTEM

#include "EasyText.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FILE_TEXT_EXTENTION ".txt"

EasyText* easyReadFile(char* path,int linesAmount,int lineSize){
    FILE* fptr = fopen(path,"r");
    
    if(fptr == NULL){
        return NULL;
    }

    EasyText* output = newEasyText(linesAmount,lineSize);

    if(output == NULL){
        fclose(fptr);
        return NULL;
    }

    int i = 0;
    for(i = 0;i<linesAmount && !feof(fptr);i++){
        fgets(output->text[i],lineSize,fptr);
    }

    fclose(fptr);

    return output;
}

void easyClearFile(char* path){
    FILE* fptr = fopen(path,"w");

    if(fptr == NULL){
        return;
    }
    
    fprintf(fptr,"");

    fclose(fptr);
}

void easyWriteInFile(char* path,EasyText* et){
    FILE* fptr = fopen(path,"w");

    if(fptr == NULL){
        return;
    }

    fprintf(fptr,"");

    int i = 0;
    for(i = 0;i<et->linesAmount;i++){
        fputs(et->text[i],fptr);
    }

    fclose(fptr);
}

void easierWriteOverFile(char* path,char* content){
    FILE* fptr = fopen(path,"w");

    if(fptr == NULL){
        return;
    }

    fprintf(fptr,content);

    fclose(fptr);
}

#endif