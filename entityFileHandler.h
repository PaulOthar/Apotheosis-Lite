#ifndef ENTITY_FILE_HANDLER
#define ENTITY_FILE_HANDLER

#include "entity.h"
#include "statsdata.h"
#include "combatdata.h"
#include "manadata.h"
#include <string.h>

#define ENTITY_FILE_HANDLER_USER_ENTITIES_PATH "data/entities/usercreated/"
#define ENTITY_FILE_HANDLER_ENTITY_FILE_FOLDER "entity"
#define ENTITY_FILE_HANDLER_STATSDATA_FILE_FOLDER "statsdata"
#define ENTITY_FILE_HANDLER_COMBATDATA_FILE_FOLDER "combatdata"
#define ENTITY_FILE_HANDLER_MANADATA_FILE_FOLDER "manadata"
#define ENTITY_FILE_HANDLER_ENABLEDMANADATA_FILE_FOLDER "enabledmanadata"

FILE* openEntityRelatedFile(char* folder,char* fileName){
    char pth[300];

    strcpy(pth,ENTITY_FILE_HANDLER_USER_ENTITIES_PATH);
    strcat(pth,folder);
    strcat(pth,"/");
    strcat(pth,fileName);
    strcat(pth,".txt");

    return fopen(pth,"r");
}

void readEntityRelatedFileIntegers(FILE* fptr,int holder[],int size){
    int i = 0;
    char content[150];
    for(i = 0;i<size && !feof(fptr);i++){
        fgets(content,150,fptr);
        holder[i] = atoi(content);
    }
}

void readStatsDataFile(char* name,Entity* e){
    FILE* fptr = openEntityRelatedFile(ENTITY_FILE_HANDLER_STATSDATA_FILE_FOLDER,name);

    if(fptr == NULL){
        return;
    }

    int integers[8];
    readEntityRelatedFileIntegers(fptr,integers,8);

    fclose(fptr);

    e->statsData = newStatsData();

    if(e->statsData == NULL){
        return;
    }

    int i = 0;
    for(i = 0;i<4;i++){
        e->statsData->level[i] = integers[i];
    }
    for(i = 4;i<8;i++){
        e->statsData->experience[i-4] = integers[i];
    }
}

void readCombatDataFile(char* name,Entity* e){
    FILE* fptr = openEntityRelatedFile(ENTITY_FILE_HANDLER_COMBATDATA_FILE_FOLDER,name);

    if(fptr == NULL){
        return;
    }

    int integers[4];
    readEntityRelatedFileIntegers(fptr,integers,4);

    fclose(fptr);

    e->combatData = newCombatData();

    if(e->combatData == NULL){
        return;
    }

    int i = 0;

    for(i = 0;i<4;i++){
        e->combatData->value[i] = integers[i];
    }
}   

void readManaDataFile(char* name,Entity* e){
    FILE* fptr = openEntityRelatedFile(ENTITY_FILE_HANDLER_MANADATA_FILE_FOLDER,name);

    if(fptr == NULL){
        return;
    }

    int integers[16];
    readEntityRelatedFileIntegers(fptr,integers,16);

    fclose(fptr);

    e->manaData = newManaData();

    if(e->manaData == NULL){
        return;
    }

    int i = 0;

    for(i = 0;i<8;i++){
        e->manaData->reserve[i] = integers[i];
    }
    for(i = 8;i<16;i++){
        e->manaData->limit[i-8] = integers[i];
    }
}

void readEnabledManaDataFile(char* name,Entity* e){
    if(e->manaData == NULL){
        return;
    }

    FILE* fptr = openEntityRelatedFile(ENTITY_FILE_HANDLER_ENABLEDMANADATA_FILE_FOLDER,name);

    if(fptr == NULL){
        return;
    }

    int integers[16];
    readEntityRelatedFileIntegers(fptr,integers,16);

    fclose(fptr);

    enableManaData(e->manaData);

    if(e->manaData->level == NULL || e->manaData->spent == NULL){
        return;
    }

    int i = 0;

    for(i = 0;i<8;i++){
        e->manaData->level[i] = integers[i];
    }
    for(i = 8;i<16;i++){
        e->manaData->spent[i-8] = integers[i];
    }
}

Entity* readEntityFile(char* name){
    Entity* output = newEntity();

    if(output == NULL){
        return NULL;
    }

    FILE* fptr = openEntityRelatedFile(ENTITY_FILE_HANDLER_ENTITY_FILE_FOLDER,name);

    if(fptr == NULL){
        freeEntity(output);
        return NULL;
    }

    int integers[4];
    readEntityRelatedFileIntegers(fptr,integers,4);

    fclose(fptr);

    int i = 0;
    for(i = 0;i<2;i++){
        output->hp[i] = integers[i];
    }
    for(i = 2;i<4;i++){
        output->mana[i-2] = integers[i];
    }
    
    readStatsDataFile(name,output);
    readCombatDataFile(name,output);
    readManaDataFile(name,output);
    readEnabledManaDataFile(name,output);

    return output;
}

#endif