#ifndef ENTITY
#define ENTITY

#include <stdio.h>
#include <stdlib.h>

#include "statsdata.h"
#include "combatdata.h"
#include "manadata.h"

typedef struct /*Entity*/{
    int hp[2];//Reserve/Limit
    int mana[2];//Reserve/Limit

    char* name;

    StatsData* statsData;
    CombatData* combatData;
    ManaData* manaData;
}Entity;

Entity* newEntity(){
    Entity* output = (Entity*)malloc(sizeof(Entity));

    if(output != NULL){
        output->name = NULL;
        output->statsData = NULL;
        output->combatData = NULL;
        output->manaData = NULL;
    }

    return output;
}

void freeEntity(Entity* e){
    if(e->name != NULL){
        free(e->name);
    }
    if(e->statsData != NULL){
        free(e->statsData);
    }
    if(e->combatData != NULL){
        free(e->combatData);
    }
    if(e->manaData != NULL){
        free(e->manaData);
    }
    free(e);
}

void initializeEntity(Entity* e){
    e->hp[0] = 0;
    e->hp[1] = 0;
    e->mana[0] = 0;
    e->mana[1] = 0;

    if(e->statsData != NULL){
        initializeStatsData(e->statsData);
    }
    if(e->combatData != NULL){
        initializeCombatData(e->combatData);
    }
    if(e->manaData != NULL){
        initializeManaData(e->manaData);
    }
}

void enableEntity(Entity* e,int statsdata,int combatdata,int manadata){
    if(statsdata > 0 && e->statsData == NULL){
        e->statsData = newStatsData();
    }
    if(combatdata > 0 && e->combatData == NULL){
        e->combatData = newCombatData();
    }
    if(manadata > 0){
        if(e->manaData == NULL){
            e->manaData = newManaData();
        }
        if(manadata > 1 && e->manaData != NULL){
            enableManaData(e->manaData);
        }
    }
}

void printEntity(Entity* e){
    if(e->name != NULL){
        printf("%s\n",e->name);
    }
    printf("HP:(%d/%d)\nMana:(%d/%d)",
    e->hp[0],e->hp[1],
    e->mana[0],e->mana[1]
    );
    if(e->statsData != NULL){
        printf("\n--<Stats Data>--\n");
        printStatsData(e->statsData);
    }
    if(e->combatData != NULL){
        printf("\n--<Combat Data>--\n");
        printCombatData(e->combatData);
    }
    if(e->manaData != NULL){
        printf("\n--<Elemental Mana Data>--\n");
        printManaData(e->manaData);
    }
}

#endif