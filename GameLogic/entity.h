#ifndef ENTITY
#define ENTITY

#define STATS_DATA_SIZE 4
#define COMBAT_DATA_SIZE 4
#define ELEMENTAL_DATA_SIZE 8

#include <stdlib.h>

typedef struct /*Entity*/{
    int hp[2];
    int mana[2];

    char* name;

    int* statsLevel;
    int* statsExperience;

    int* combatValues;

    int* elementalReserve;
    int* elementalLimit;
    int* elementalLevel;
    int* elementalSpent;
}Entity;

Entity* newEntity(){
    Entity* output = (Entity*)malloc(sizeof(Entity));

    if(output != NULL){
        output->hp[0] = 0;
        output->hp[1] = 0;
        output->mana[0] = 0;
        output->mana[1] = 0;

        output->name = NULL;

        output->statsLevel = NULL;
        output->statsExperience = NULL;

        output->combatValues = NULL;

        output->elementalReserve = NULL;
        output->elementalLimit = NULL;
        output->elementalLevel = NULL;
        output->elementalSpent = NULL;
    }

    return output;
}

void freeEntity(Entity* e){
    if(e == NULL){
        return;
    }

    if(e->name != NULL){
        free(e->name);
    }

    if(e->statsLevel != NULL){
        free(e->statsLevel);
    }
    if(e->statsExperience != NULL){
        free(e->statsExperience);
    }

    if(e->combatValues != NULL){
        free(e->combatValues);
    }

    if(e->elementalReserve != NULL){
        free(e->elementalReserve);
    }
    if(e->elementalLimit != NULL){
        free(e->elementalLimit);
    }
    if(e->elementalLevel != NULL){
        free(e->elementalLevel);
    }
    if(e->elementalSpent != NULL){
        free(e->elementalSpent);
    }

    free(e);
}

int* newInitializedFeaturePointer(int size){
    /*
    For those whom may concern:
    I KNOW I COULD HAVE USED CALLOC, BUT I DONT LIKE IT NOR WANT TO USE IT >:C
    */
    int* output = (int*)malloc(sizeof(int)*size);

    if(output != NULL){
        int i = 0;
        for(i = 0;i<size;i++){
            output[i] = 0;
        }
    }

    return output;
}

void enableEntityFeature(Entity* e,int featureIndex){
    switch(featureIndex){
        case 0:
            if(e->statsLevel == NULL){
                e->statsLevel = newInitializedFeaturePointer(STATS_DATA_SIZE);
            }
            break;
        case 1:
            if(e->statsExperience == NULL){
                e->statsExperience = newInitializedFeaturePointer(STATS_DATA_SIZE);
            }
            break;
        case 2:
            if(e->combatValues == NULL){
                e->combatValues = newInitializedFeaturePointer(COMBAT_DATA_SIZE);
            }
            break;
        case 3:
            if(e->elementalReserve == NULL){
                e->elementalReserve = newInitializedFeaturePointer(ELEMENTAL_DATA_SIZE);
            }
            break;
        case 4:
            if(e->elementalLimit == NULL){
                e->elementalLimit = newInitializedFeaturePointer(ELEMENTAL_DATA_SIZE);
            }
            break;
        case 5:
            if(e->elementalLevel == NULL){
                e->elementalLevel = newInitializedFeaturePointer(ELEMENTAL_DATA_SIZE);
            }
            break;
        case 6:
            if(e->elementalSpent == NULL){
                e->elementalSpent = newInitializedFeaturePointer(ELEMENTAL_DATA_SIZE);
            }
            break;
    }
}



#endif