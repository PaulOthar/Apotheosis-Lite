#ifndef MANA_DATA
#define MANA_DATA

#include <stdio.h>
#include <stdlib.h>

int MANA_DATA_VERBOSE = 0;

/*
Mana Data Dictates the general data of a item or creature mana reserve.

Some spent mana is required in order to level up.

Level up will have influence in the limit.

it is quite costly, so use carefully.
*/
typedef struct /*ManaData*/{
    int reserve[8];
    int limit[8];
    int *level;//NPCs cannot level up.
    int *spent;//Those who cant level up, must not gain exp
}ManaData;

ManaData* newManaData(){
    ManaData* output = (ManaData*)malloc(sizeof(ManaData));
    if(output != NULL){
        output->level = NULL;
        output->spent = NULL;
    }
    return output;
}

void assignManaData(ManaData* md){
    if(md != NULL){
        return;
    }
    md = (ManaData*)malloc(sizeof(ManaData));
    if(md != NULL){
        md->level = NULL;
        md->spent = NULL;
    }
}

void freeManaData(ManaData* md){
    if(md->level != NULL){
        free(md->level);
    }
    if(md->spent != NULL){
        free(md->spent);
    }
    free(md);
}

void initializeManaData(ManaData* md){
    int i = 0;
    for(i = 0;i<8;i++){
        md->reserve[i] = 0;
        md->limit[i] = 0;
    }
    if(md->level != NULL && md->spent != NULL){
        for(i = 0;i<8;i++){
            md->level[i] = 0;
            md->spent[i] = 0;
        }
    }
}

void enableManaData(ManaData* md){
    md->level = (int*)malloc(sizeof(int)*8);
    md->spent = (int*)malloc(sizeof(int)*8);
}

void spendManaData(ManaData* md,int index,int amount){
    md->reserve[index] -= amount;
    if(md->spent != NULL){
        md->spent[index] += amount;
    }
}

void printNameManaData(int index){
    switch(index){
        case 0:
            printf("Earth");
            break;
        case 1:
            printf("Air");
            break;
        case 2:
            printf("Cold");
            break;
        case 3:
            printf("Heat");
            break;
        case 4:
            printf("Life");
            break;
        case 5:
            printf("Death");
            break;
        case 6:
            printf("Light");
            break;
        case 7:
            printf("Dark");
            break;
    }
}

void printManaData(ManaData* md){
    int i = 0;
    if(md->level != NULL && md->spent != NULL){
        for(i = 0;i<8;i++){
            if(i>0){
                printf("\n");
            }
            printNameManaData(i);
            printf(":{%d}(%d/%d)<%d>",md->level[i],md->reserve[i],md->limit[i],md->reserve[i]);
        }
        return;
    }
    for(i = 0;i<8;i++){
        if(i>0){
            printf("\n");
        }
        printNameManaData(i);
        printf(":(%d/%d)",md->reserve[i],md->limit[i]);
    }
}

#endif