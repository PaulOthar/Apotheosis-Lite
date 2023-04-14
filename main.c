#include <stdio.h>
#include "entity.h"

int main(int argc,char** argv){
    Entity* e = newEntity();

    if(e == NULL){
        return 0;
    }
    enableEntity(e,1,0,2);
    initializeEntity(e);
    printEntity(e);
    freeEntity(e);
    return 0;
}