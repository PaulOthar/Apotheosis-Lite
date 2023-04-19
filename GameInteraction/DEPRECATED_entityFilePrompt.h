#ifndef ENTITY_FILE_PROMPT
#define ENTITY_FILE_PROMPT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "..\GameLogic\entity.h"
#include "..\GeneralPurposeTools\EasyInput.h"

#define ENTITY_FILE_PROMPT_ENTITY_FOLDER "data/entities/usercreated/entity/"
#define ENTITY_FILE_PROMPT_STATSDATA_FOLDER "data/entities/usercreated/statsdata/"
#define ENTITY_FILE_PROMPT_COMBATDATA_FOLDER "data/entities/usercreated/combatdata/"
#define ENTITY_FILE_PROMPT_MANADATA_FOLDER "data/entities/usercreated/manadata/"
#define ENTITY_FILE_PROMPT_ENABLEDMANADA_FOLDER "data/entities/usercreated/enabledmanadata/"

#define ENTITY_FILE_PROMPT_MAX_LINE_SIZE 150

#define ENTITY_FILE_PROMPT_YES_OPTION "y"
#define ENTITY_FILE_PROMPT_NO_OPTION "anything"

#define ENTITY_FILE_PROMPT_PROMTP "%s\n"
#define ENTITY_FILE_PROMPT_QUESTION "%s [%s : Yes][%s : No]\n"

#define ENTITY_FILE_PROMPT_NAME "Insert a name for the Entity:"
#define ENTITY_FILE_PROMPT_STATS "Enable Stats Data for the Entity?"
#define ENTITY_FILE_PROMPT_COMBAT "Enable Combat Data for the Entity?"
#define ENTITY_FILE_PROMPT_MANA1 "Enable Mana Data for the Entity?"
#define ENTITY_FILE_PROMPT_MANA2 "Enable Expanded Mana Data for the Entity?"

void saveEntityPrompt(Entity* e,char* name){
    char filename[ENTITY_FILE_PROMPT_MAX_LINE_SIZE];
    strcpy(filename,name);
    int i = 0;
    for(i = 0;i<ENTITY_FILE_PROMPT_MAX_LINE_SIZE;i++){
        if(filename[i] == '\n'){
            filename[i] = '\0';
        }
    }
    strcat(filename,".txt");

    char path[ENTITY_FILE_PROMPT_MAX_LINE_SIZE];
    strcpy(path,ENTITY_FILE_PROMPT_ENTITY_FOLDER);
    strcat(path,filename);

    FILE* fptr = fopen(path,"w");
    if(fptr == NULL){
        printf(path);
        return;
    }

    fprintf(fptr,"%d\n%d\n%d\n%d",e->hp[0],e->hp[1],e->mana[0],e->mana[1]);

    fclose(fptr);

    if(e->statsData != NULL){
        strcpy(path,ENTITY_FILE_PROMPT_STATSDATA_FOLDER);
        strcat(path,filename);

        fptr = fopen(path,"w");
        if(fptr == NULL){
        printf(path);
        return;
        }
        fprintf(fptr,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",
        e->statsData->level[0],e->statsData->level[1],e->statsData->level[2],e->statsData->level[3],
        e->statsData->experience[0],e->statsData->experience[1],e->statsData->experience[2],e->statsData->experience[3]
        );
        fclose(fptr);
    }

    if(e->combatData != NULL){
        strcpy(path,ENTITY_FILE_PROMPT_COMBATDATA_FOLDER);
        strcat(path,filename);

        fptr = fopen(path,"w");
        if(fptr == NULL){
        printf(path);
        return;
        }
        fprintf(fptr,"%d\n%d\n%d\n%d",
        e->combatData->value[0],e->combatData->value[1],e->combatData->value[2],e->combatData->value[3]
        );
        fclose(fptr);
    }

    if(e->manaData != NULL){
        strcpy(path,ENTITY_FILE_PROMPT_MANADATA_FOLDER);
        strcat(path,filename);

        fptr = fopen(path,"w");
        if(fptr == NULL){
        printf(path);
        return;
        }
        fprintf(fptr,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",
        e->manaData->reserve[0],e->manaData->reserve[1],e->manaData->reserve[2],e->manaData->reserve[3],
        e->manaData->reserve[4],e->manaData->reserve[5],e->manaData->reserve[6],e->manaData->reserve[7],
        e->manaData->limit[0],e->manaData->limit[1],e->manaData->limit[2],e->manaData->limit[3],
        e->manaData->limit[4],e->manaData->limit[5],e->manaData->limit[6],e->manaData->limit[7]
        );
        fclose(fptr);

        if(e->manaData->level != NULL && e->manaData->spent != NULL){
            strcpy(path,ENTITY_FILE_PROMPT_ENABLEDMANADA_FOLDER);
            strcat(path,filename);

            fptr = fopen(path,"w");
            if(fptr == NULL){
            printf(path);
            return;
            }
            fprintf(fptr,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",
            e->manaData->level[0],e->manaData->level[1],e->manaData->level[2],e->manaData->level[3],
            e->manaData->level[4],e->manaData->level[5],e->manaData->level[6],e->manaData->level[7],
            e->manaData->spent[0],e->manaData->spent[1],e->manaData->spent[2],e->manaData->spent[3],
            e->manaData->spent[4],e->manaData->spent[5],e->manaData->spent[6],e->manaData->spent[7]
            );
            fclose(fptr);
        }
    }
}

void createEntityPrompt(){
    char name[ENTITY_FILE_PROMPT_MAX_LINE_SIZE];

    printf(ENTITY_FILE_PROMPT_PROMTP,ENTITY_FILE_PROMPT_NAME);
    read(name,ENTITY_FILE_PROMPT_MAX_LINE_SIZE);
    printf("\n\n");

    char holder[ENTITY_FILE_PROMPT_MAX_LINE_SIZE];

    Entity* e = newEntity();

    if(e == NULL){
        return;
    }

    int options[] = {0,0,0};

    printf(ENTITY_FILE_PROMPT_QUESTION,ENTITY_FILE_PROMPT_STATS,ENTITY_FILE_PROMPT_YES_OPTION,ENTITY_FILE_PROMPT_NO_OPTION);
    read(holder,ENTITY_FILE_PROMPT_MAX_LINE_SIZE);
    printf("\n\n");

    if(strcmp(holder,ENTITY_FILE_PROMPT_YES_OPTION) >= 0){
        options[0] = 1;
    }

    printf(ENTITY_FILE_PROMPT_QUESTION,ENTITY_FILE_PROMPT_COMBAT,ENTITY_FILE_PROMPT_YES_OPTION,ENTITY_FILE_PROMPT_NO_OPTION);
    read(holder,ENTITY_FILE_PROMPT_MAX_LINE_SIZE);
    printf("\n\n");

    if(strcmp(holder,ENTITY_FILE_PROMPT_YES_OPTION) >= 0){
        options[1] = 1;
    }

    printf(ENTITY_FILE_PROMPT_QUESTION,ENTITY_FILE_PROMPT_MANA1,ENTITY_FILE_PROMPT_YES_OPTION,ENTITY_FILE_PROMPT_NO_OPTION);
    read(holder,ENTITY_FILE_PROMPT_MAX_LINE_SIZE);
    printf("\n\n");

    if(strcmp(holder,ENTITY_FILE_PROMPT_YES_OPTION) >= 0){
        options[2] = 1;

        printf(ENTITY_FILE_PROMPT_QUESTION,ENTITY_FILE_PROMPT_MANA2,ENTITY_FILE_PROMPT_YES_OPTION,ENTITY_FILE_PROMPT_NO_OPTION);
        read(holder,ENTITY_FILE_PROMPT_MAX_LINE_SIZE);
        printf("\n\n");

        if(strcmp(holder,ENTITY_FILE_PROMPT_YES_OPTION) >= 0){
            options[2] = 2;
        }
    }

    enableEntity(e,options[0],options[1],options[2]);

    initializeEntity(e);

    e->hp[0] = 1;
    e->hp[1] = 1;
    e->mana[0] = 0;
    e->mana[1] = 100;

    saveEntityPrompt(e,name);

    freeEntity(e);
}

#endif