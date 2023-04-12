#include <stdio.h>
#include "manadata.h"

int main(int argc,char** argv){
    MANA_DATA_VERBOSE = 1;

    ManaData* md = newManaData();

    if(md == NULL){
        return 0;
    }

    enableManaData(md);
    initializeManaData(md);
    printManaData(md);
    freeManaData(md);
    return 0;
}