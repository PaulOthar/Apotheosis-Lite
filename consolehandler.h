#ifndef CONSOLE_HANDLER
#define CONSOLE_HANDLER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define CONSOLE_HELP_FOLDER = "/help"
#define CONSOLE_HELP_FILE_SUFIX = ".txt"

#define CONSOLE_HELP_1 "-h"
#define CONSOLE_HELP_2 "-help"

int handleArgs(int argc,char *argv[]);

int noArgument();

int unknownArgument(char* arg);

int run();

int printHelp();

int printVersion();

int printManual(char* arg);

#define CONSOLE_HANDLER_RUN "-r"
#define CONSOLE_HANDLER_HELP "-h"
#define CONSOLE_HANDLER_VERSION "-v"
#define CONSOLE_HANDLER_MANUAL "-m"

#define CONSOLE_HANDLER_EXTENTION ".txt"

#define CONSOLE_HANDLER_DATA_FOLDER "data/"
#define CONSOLE_HANDLER_MANUAL_FOLDER "manual/"

#define CONSOLE_HANDLER_VERSION_FILE "version"
#define CONSOLE_HANDLER_CREDITS "credits"
#define CONSOLE_HANDLER_INDEX "index"

#define CONSOLE_HANDLER_LINE_MAX_SIZE 150

#define CONSOLE_HANDLER_NO_ARGUMENT "\nPlease, use an argument:\n'%s' to run the program\n'%s' to see all avaliable basic arguments\n\n"
#define CONSOLE_HANDLER_UNKNOWN_ARGUMENT "\nArgument '%s' does not exist.\nPlease use '%s' to list all basic arguments.\n\n"
#define CONSOLE_HANDLER_HELP_RUN "'%s'\tRuns the program\n"
#define CONSOLE_HANDLER_HELP_HELP "'%s'\tPrints this screen\n"
#define CONSOLE_HANDLER_HELP_VERSION "'%s'\tPrints the current version, and its contributors\n"
#define CONSOLE_HANDLER_HELP_MANUAL "'%s ?'\tPrints the manual for something\n"

#define CONSOLE_HANDLER_VERSION_NOT_FOUND "\nVersion file not found :(\n\n"
#define CONSOLE_HANDLER_CREDITS_NOT_FOUND "\nCredits file not found :(\n\n"
#define CONSOLE_HANDLER_MANUALS_NOT_FOUND "\nNo manual file or folder found :(\n\n"

#define CONSOLE_HANDLER_RUNNING "\nRunning\n\n"

int handleArgs(int argc,char *argv[]){
    if(argc <= 1){
        return noArgument();
    }

    if(strcmp(argv[1],CONSOLE_HANDLER_RUN) == 0){
        return run();
    }
    if(strcmp(argv[1],CONSOLE_HANDLER_HELP) == 0){
        return printHelp();
    }
    if(strcmp(argv[1],CONSOLE_HANDLER_VERSION) == 0){
        return printVersion();
    }
    if(strcmp(argv[1],CONSOLE_HANDLER_MANUAL) == 0){
        if(argc <= 2){
            return printManual(CONSOLE_HANDLER_INDEX);
        }
        return printManual(argv[2]);
    }

    return unknownArgument(argv[1]);
}

int noArgument(){
    printf(CONSOLE_HANDLER_NO_ARGUMENT,CONSOLE_HANDLER_RUN,CONSOLE_HANDLER_HELP);
    return -1;
}

int unknownArgument(char* arg){
    printf(CONSOLE_HANDLER_UNKNOWN_ARGUMENT,arg,CONSOLE_HANDLER_HELP);
    return -1;
}

int run(){
    printf(CONSOLE_HANDLER_RUNNING);
    return 0;
}

int printHelp(){
    printf(CONSOLE_HANDLER_HELP_RUN,CONSOLE_HANDLER_RUN);
    printf(CONSOLE_HANDLER_HELP_HELP,CONSOLE_HANDLER_HELP);
    printf(CONSOLE_HANDLER_HELP_VERSION,CONSOLE_HANDLER_VERSION);
    printf(CONSOLE_HANDLER_HELP_MANUAL,CONSOLE_HANDLER_MANUAL);
    return 1;
}

int printFile(char* path,char* notFound){
    FILE *fptr;

    fptr = fopen(path, "r");

    int status = 0;

    if(fptr != NULL){
        status = 1;
        char content[CONSOLE_HANDLER_LINE_MAX_SIZE];

        printf("\n");
        while(!feof(fptr)){
            fgets(content,CONSOLE_HANDLER_LINE_MAX_SIZE,fptr);

            printf("%s",content);
        }
        printf("\n\n");
    }
    else{
        if(notFound != NULL){
            printf("%s",notFound);
        }
    }

    fclose(fptr);
    return status;
}

int printVersion(){
    char pth[200];

    strcpy(pth,CONSOLE_HANDLER_DATA_FOLDER);
    strcat(pth,CONSOLE_HANDLER_VERSION_FILE);
    strcat(pth,CONSOLE_HANDLER_EXTENTION);

    printFile(pth,CONSOLE_HANDLER_VERSION_NOT_FOUND);

    strcpy(pth,CONSOLE_HANDLER_DATA_FOLDER);
    strcat(pth,CONSOLE_HANDLER_CREDITS);
    strcat(pth,CONSOLE_HANDLER_EXTENTION);

    printFile(pth,CONSOLE_HANDLER_CREDITS_NOT_FOUND);

    return 1;
}

int printManual(char* arg){
    char pth[200];

    strcpy(pth,CONSOLE_HANDLER_DATA_FOLDER);
    strcat(pth,CONSOLE_HANDLER_MANUAL_FOLDER);
    strcat(pth,arg);
    strcat(pth,CONSOLE_HANDLER_EXTENTION);

    if(printFile(pth,NULL) == 0){
        strcpy(pth,CONSOLE_HANDLER_DATA_FOLDER);
        strcat(pth,CONSOLE_HANDLER_MANUAL_FOLDER);
        strcat(pth,arg);
        strcat(pth,"/");
        strcat(pth,CONSOLE_HANDLER_INDEX);
        strcat(pth,CONSOLE_HANDLER_EXTENTION);

        printFile(pth,CONSOLE_HANDLER_MANUALS_NOT_FOUND);
    }

    return 1;
}

#endif