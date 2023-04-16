#ifndef EASY_CONSOLE_GRAPHICS
#define EASY_CONSOLE_GRAPHICS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TBLR_CODE_EMPTY 0b0000 //0
#define TBLR_CODE_RIGHT 0b0001 //1
#define TBLR_CODE_LEFT 0b0010 //2
#define TBLR_CODE_HORIZONTAL 0b0011 //3
#define TBLR_CODE_BOTTOM 0b0100 //4
#define TBLR_CODE_BOTTOM_RIGHT 0b0101 //5
#define TBLR_CODE_BOTTOM_LEFT 0b0110 //6
#define TBLR_CODE_BOTTOM_HORIZONTAL 0b0111 //7
#define TBLR_CODE_TOP 0b1000 //8
#define TBLR_CODE_TOP_RIGHT 0b1001 //9
#define TBLR_CODE_TOP_LEFT 0b1010 //10
#define TBLR_CODE_TOP_HORIZONTAL 0b1011 //11
#define TBLR_CODE_VERTICAL 0b1100 //12
#define TBLR_CODE_VERTICAL_RIGHT 0b1101 //13
#define TBLR_CODE_VERTICAL_LEFT 0b1110 //14
#define TBLR_CODE_CROSS 0b1111 //15

const int TBLR_CODE_FILTER_SIMPLE[] = {0,3,3,3,12,15,15,15,12,15,15,15,12,15,15,15};
const int TBLR_CODE_FILTER_COMPLEX1[] = {0,3,3,3,12,5,6,15,12,9,10,15,12,15,15,15};
const int TBLR_CODE_FILTER_COMPLEX2[] = {0,3,3,3,12,15,15,7,12,15,15,11,12,13,14,15};
const int TBLR_CODE_FILTER_COMPLETE[] = {0,3,3,3,12,5,6,7,12,9,10,11,12,13,14,15};

typedef struct /*EasyWall*/{
    int type;//[0:Simple][1:Complex1][2:Complex2][3:Complete]

    /*
    00 = Simple
    01 = Complex
    10 = Complexer
    11 = Complete
    */

    //Simple
    char *Horizontal;//Horizontal Line
	char *Vertical;//Vertical Line
    char *Cross;//Cross Symbol
    char *Empty;//Empty Symbol

    //Complex 1
	char *T_Left;//Top Left Corner
	char *T_Right;//Top Right Corner
	char *B_Left;//Bottom Left Corner
	char *B_Right;//Bottom Right Corner
	
    //Complex 2
	char *L_W;//Left Horizontal Line on a Vertical Line
	char *R_W;//Right Horizontal Line on a Vertical Line
	char *T_W;//Top Vertical Line on a Horizontal Line
	char *B_W;//Bottom Vertical Line on a Horizontal Line


}EasyWall;

EasyWall* newEasyWall(char* Horizontal,char* Vertical,char* Cross,char* Empty){
    EasyWall* output = (EasyWall*)malloc(sizeof(EasyWall));

    if(output != NULL){
        output->type = 0;

        output->Horizontal = (char*)malloc(sizeof(char)*strlen(Horizontal));
        strcpy(output->Horizontal,Horizontal);

        output->Vertical = (char*)malloc(sizeof(char)*strlen(Vertical));
        strcpy(output->Vertical,Vertical);

        output->Cross = (char*)malloc(sizeof(char)*strlen(Cross));
        strcpy(output->Cross,Cross);

        output->Empty = (char*)malloc(sizeof(char)*strlen(Empty));
        strcpy(output->Empty,Empty);

        output->T_Left = NULL;
	    output->T_Right = NULL;
	    output->B_Left = NULL;
	    output->B_Right = NULL;
	
	    output->L_W = NULL;
	    output->R_W = NULL;
	    output->T_W = NULL;
	    output->B_W = NULL;
    }

    return output;
}

void freeEasyWall(EasyWall* ew){
    if(ew->Horizontal != NULL){
        free(ew->Horizontal);
    }
    if(ew->Vertical != NULL){
        free(ew->Vertical);
    }
    if(ew->Cross != NULL){
        free(ew->Cross);
    }
    if(ew->Empty != NULL){
        free(ew->Empty);
    }
    
    if(ew->T_Left != NULL){
        free(ew->T_Left);
    }
    if(ew->T_Right != NULL){
        free(ew->T_Right);
    }
    if(ew->B_Left != NULL){
        free(ew->B_Left);
    }
    if(ew->B_Right != NULL){
        free(ew->B_Right);
    }

    if(ew->L_W != NULL){
        free(ew->L_W);
    }
    if(ew->R_W != NULL){
        free(ew->R_W);
    }
    if(ew->T_W != NULL){
        free(ew->T_W);
    }
    if(ew->B_W != NULL){
        free(ew->B_W);
    }

    free(ew);
}

void enableEasyWallComplex1(EasyWall* ew,char* T_Left,char* T_Right,char* B_Left,char* B_Right){
    if(ew->type == 1 || ew->type == 3){//1 or 3
        return;
    }
    ew->type += 1;

    ew->T_Left = (char*)malloc(sizeof(char)*strlen(T_Left));
    strcpy(ew->T_Left,T_Left);

    ew->T_Right = (char*)malloc(sizeof(char)*strlen(T_Right));
    strcpy(ew->T_Right,T_Right);

    ew->B_Left = (char*)malloc(sizeof(char)*strlen(B_Left));
    strcpy(ew->B_Left,B_Left);

    ew->B_Right = (char*)malloc(sizeof(char)*strlen(B_Right));
    strcpy(ew->B_Right,B_Right);
}

void enableEasyWallComplex2(EasyWall* ew,char* L_W,char* R_W,char* T_W,char* B_W){
    if(ew->type == 2 || ew->type == 3){//2 or 3
        printf("Quitted");
        return;
    }
    ew->type += 2;

    ew->L_W = (char*)malloc(sizeof(char)*strlen(L_W));
    strcpy(ew->L_W,L_W);

    ew->R_W = (char*)malloc(sizeof(char)*strlen(R_W));
    strcpy(ew->R_W,R_W);

    ew->T_W = (char*)malloc(sizeof(char)*strlen(T_W));
    strcpy(ew->T_W,T_W);

    ew->B_W = (char*)malloc(sizeof(char)*strlen(B_W));
    strcpy(ew->B_W,B_W);
}

char* fetchByTBLRCode(int code,EasyWall* ew){
    switch(code){
        case 0:return ew->Empty;
        case 1:return ew->Horizontal;
        case 2:return ew->Horizontal;
        case 3:return ew->Horizontal;
        case 4:return ew->Vertical;
        case 5:return ew->B_Right;
        case 6:return ew->B_Left;
        case 7:return ew->B_W;
        case 8:return ew->Vertical;
        case 9:return ew->T_Right;
        case 10:return ew->T_Left;
        case 11:return ew->T_W;
        case 12:return ew->Vertical;
        case 13:return ew->R_W;
        case 14:return ew->L_W;
        case 15:return ew->Cross;
    }
}

char* filterByTBLRCode(int code,EasyWall* ew){
    switch(ew->type){
        case 0:return fetchByTBLRCode(TBLR_CODE_FILTER_SIMPLE[code],ew);
        case 1:return fetchByTBLRCode(TBLR_CODE_FILTER_COMPLEX1[code],ew);
        case 2:return fetchByTBLRCode(TBLR_CODE_FILTER_COMPLEX2[code],ew);
        case 3:return fetchByTBLRCode(TBLR_CODE_FILTER_COMPLETE[code],ew);
    }
}

void printEasyWall(EasyWall* ew){
    char* toPrintFormat = "%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s\n%s%s%s%s%s";

    /*
    [05],[03],[07],[03],[06],
    [12],[00],[12],[00],[12],
    [13],[03],[15],[03],[14],
    [12],[00],[12],[00],[12],
    [09],[03],[11],[03],[10]
    */

    printf(toPrintFormat,
    filterByTBLRCode(5,ew),filterByTBLRCode(3,ew),filterByTBLRCode(7,ew),filterByTBLRCode(3,ew),filterByTBLRCode(6,ew),
    filterByTBLRCode(12,ew),filterByTBLRCode(0,ew),filterByTBLRCode(12,ew),filterByTBLRCode(0,ew),filterByTBLRCode(12,ew),
    filterByTBLRCode(13,ew),filterByTBLRCode(3,ew),filterByTBLRCode(15,ew),filterByTBLRCode(3,ew),filterByTBLRCode(14,ew),
    filterByTBLRCode(12,ew),filterByTBLRCode(0,ew),filterByTBLRCode(12,ew),filterByTBLRCode(0,ew),filterByTBLRCode(12,ew),
    filterByTBLRCode(9,ew),filterByTBLRCode(3,ew),filterByTBLRCode(11,ew),filterByTBLRCode(3,ew),filterByTBLRCode(10,ew)
    );
}

#endif