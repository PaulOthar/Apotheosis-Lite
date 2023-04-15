#include <stdio.h>

#include "consolehandler.h"
#include "consoleEntityHandler.h"

int main(int argc,char** argv){
    consoleEntityHandlerPrompt();
    /*
    switch(handleArgs(argc,argv)){
        case -1:break;
        case 0:printf("Options:\n1 - Read Entity\n2 - Create Entity");break;
        case 1:break;
        default:printf("Invalid Option");break;
    }
    */
    return 0;
}