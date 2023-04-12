#ifndef STATS_DATA
#define STATS_DATA

#include <stdio.h>
#include <stdlib.h>

/*
StatsData is the Holder of Data Related to Stats:

Strength(Str)
Dexterity(Dex)
Arcanism(Arc)
Resistance(Res)

Stats are used in tests, made by the main character, or NPCs.
They are also used to calculate the CombatData:

Str+Dex = ATK (Physical Damage)
Str+Res = DEF (Physical Damage Reduction)
Arc+Dex = ARC (Magical Damage)
Arc+Res = RES (Magical Damage Reduction)

Aside from CombatData, Stats are also used in other general entity data:

Str -> Carry Weight
Dex -> Speed
Arc -> Mana
Res -> HP

Dex+Res = Stamina

Stats are Leveled by Spending mana and Experience,
The experience must be equal or above the 2xlevel, in order to level up.

Experience is earned by suceeding in tests, and by undefined methods.
*/

typedef struct /*StatsData*/{
    int level[4];
    int experience[4];
}StatsData;

StatsData* newStatsData(){
    StatsData* output = (StatsData*)malloc(sizeof(StatsData));
    return output;
}

void freeStatsData(StatsData* sd){
    free(sd);
}

void initializeStatsData(StatsData* sd){
    int i = 0;
    for(i = 0;i<4;i++){
        sd->level[i] = 0;
        sd->experience[i] = 0;
    }
}

int requiredExpStatsData(int level,int experience){
    return 2*level;
}

void printStatsData(StatsData* sd){
    printf("Strength:%d (%d/%d)\nDexterity:%d (%d/%d)\nArcanism:%d (%d/%d)\nResistance:%d (%d/%d)",
    sd->level[0],sd->experience[0],requiredExpStatsData(sd->level[0],sd->experience[0]),
    sd->level[1],sd->experience[1],requiredExpStatsData(sd->level[1],sd->experience[1]),
    sd->level[2],sd->experience[2],requiredExpStatsData(sd->level[2],sd->experience[2]),
    sd->level[3],sd->experience[3],requiredExpStatsData(sd->level[3],sd->experience[3])
    );
}

#endif