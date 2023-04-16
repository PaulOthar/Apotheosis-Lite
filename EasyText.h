#ifndef EASY_TEXT
#define EASY_TEXT

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct /*EasyText*/{
    char** text;
    int linesAmount;
    int lineSize;
}EasyText;

EasyText* newEasyText(int linesAmount,int lineSize){
    EasyText* output = (EasyText*)malloc(sizeof(EasyText));

    if(output != NULL){
        output->linesAmount = linesAmount;
        output->lineSize = lineSize;

        output->text = (char**)malloc(sizeof(char*)*linesAmount);
        if(output->text != NULL){
            int i = 0;
            for(i = 0;i<linesAmount;i++){
                output->text[i] = (char*)malloc(sizeof(char)*lineSize);
            }
        }
    }

    return output;
}

void freeEasyText(EasyText* et){
    if(et->text != NULL){
        int i = 0;
        for(i = 0;i<et->linesAmount;i++){
            if(et->text[i] != NULL){
                free(et->text[i]);
            }
        }
        free(et->text);
    }
    free(et);
}

void printEasyText(EasyText* et){
    if(et->text != NULL){
        int i = 0;
        for(i = 0;i<et->linesAmount;i++){
            if(et->text[i] != NULL){
                printf("%s",et->text[i]);
            }
        }
        free(et->text);
    }
}

char* toEasyBigText(EasyText* et){
    char* output = (char*)malloc(sizeof(char)*et->linesAmount*et->lineSize);

    int i = 0;
    for(i = 0;i<et->linesAmount;i++){
        if(i == 0){
            strcpy(output,et->text[i]);
        }
        else{
            strcat(output,et->text[i]);
        }
    }

    return output;
}

#endif