#include <stdio.h>
#include "statsdata.h"

int main(int argc,char** argv){
    StatsData* sd = newStatsData();
    if(sd == NULL){
        return 0;
    }
    initializeStatsData(sd);
    sd->level[0] = 10;
    sd->level[2] = 5;
    printStatsData(sd);
    freeStatsData(sd);
    return 0;
}