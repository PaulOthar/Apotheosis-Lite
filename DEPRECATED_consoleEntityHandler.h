#ifndef CONSOLE_ENTITY_HANDLER
#define CONSOLE_ENTITY_HANDLER

#include <stdio.h>
#include <string.h>

#include "EasyInput.h"
#include "entity.h"

#include "entityFileHandler.h"

#define CONSOLE_ENTITY_HANDLER_MENUPROMPT "What you wish to do?\n%s - Ends the Entity Manipulation\n%s - Prints the current Entity\n%s - Allocate a new Entity (Freeing the previous whitheout saving)\n%s - Loads an existing Entity (Freeing the previous whitheout saving)\n%s - Saves the current Entity"

#define CONSOLE_ENTITY_HANDLER_PRINT_NULL "Null Entity :("

#define CONSOLE_ENTITY_HANDLER_QUIT "quit"
#define CONSOLE_ENTITY_HANDLER_PRINT "print"
#define CONSOLE_ENTITY_HANDLER_NEW "new"
#define CONSOLE_ENTITY_HANDLER_LOAD "load"
#define CONSOLE_ENTITY_HANDLER_SAVE "save"

void consoleEntityHandlerInsertName(char*name,char*input,int size){
    printf("\nInsert the Name of the Entity:\n>");
    readEnhanced(input,size);
    strcpy(name,input);
}

void consoleEntityHandlerPrint(Entity* entity){
    if(entity != NULL){
        printEntity(entity);
    }
    else{
        printf(CONSOLE_ENTITY_HANDLER_PRINT_NULL);
    }
}

void consoleEntityHandlerPrompt(){
    Entity* entity = NULL;
    char name[200];

    int inputsize = 200;
    char input[200];

    int skip = 0;

    nullify(input,inputsize);
    
    while(strcmp(input,CONSOLE_ENTITY_HANDLER_QUIT) != 0){
        printf(CONSOLE_ENTITY_HANDLER_MENUPROMPT,CONSOLE_ENTITY_HANDLER_QUIT,CONSOLE_ENTITY_HANDLER_PRINT,CONSOLE_ENTITY_HANDLER_NEW,CONSOLE_ENTITY_HANDLER_LOAD,CONSOLE_ENTITY_HANDLER_SAVE);
        
        printf("\n\n>");
        readEnhanced(input,inputsize);
        printf("\n\n");

        if(strcmp(input,CONSOLE_ENTITY_HANDLER_PRINT) == 0){
            consoleEntityHandlerPrint(entity);
            printf("\n\n");
        }
        else if(strcmp(input,CONSOLE_ENTITY_HANDLER_NEW) == 0){
            if(entity != NULL){
                freeEntity(entity);
            }
            consoleEntityHandlerInsertName(name,input,inputsize);
            entity = newEntity();
            printf("New Entity Created :)\n\n");
        }
        else if(strcmp(input,CONSOLE_ENTITY_HANDLER_LOAD) == 0){
            if(entity != NULL){
                freeEntity(entity);
            }
            consoleEntityHandlerInsertName(name,input,inputsize);
            entity = readEntityFile(name);
            if(entity != NULL){
                printf("\nEntity Loaded :)\n\n");
            }
            else{
                printf("\nCould not read Entity :(\n\n");
            }
        }
        else if(strcmp(input,CONSOLE_ENTITY_HANDLER_SAVE) == 0){
            printf("\n\n");
        }
    }

    if(entity != NULL){
        freeEntity(entity);
    }
}

#endif