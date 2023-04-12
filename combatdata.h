#ifndef COMBAT_DATA
#define COMBAT_DATA

#include <stdio.h>
#include <stdlib.h>

/*
Combat Data is composed by 4 Values:
Attack(ATK)
Defense(DEF)
Arcane(ARC)
Resistance(RES)

ATK (Physical Damage)
DEF (Physical Damage Reduction)
ARC (Magical Damage)
RES (Magical Damage Reduction)
*/

typedef struct /*CombatData*/{
    int value[4];
}CombatData;

CombatData* newCombatData(){
    CombatData* output = (CombatData*)malloc(sizeof(CombatData));
    return output;
}

void freeCombatData(CombatData* cd){
    free(cd);
}

void initializeCombatData(CombatData* cd){
    int i = 0;
    for(i = 0;i<4;i++){
        cd->value[i] = 0;
    }
}

void printCombatData(CombatData* cd){
    printf("ATK:%d\nDEF:%d\nARC:%d\nRES:%d",
    cd->value[0],
    cd->value[1],
    cd->value[2],
    cd->value[3]
    );
}

#endif