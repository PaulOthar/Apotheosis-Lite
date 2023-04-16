#ifndef EASY_ARGUMENTS
#define EASY_ARGUMENTS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
required folders:
./data
./data/manual

required files:
./data/version.txt
./data/credits.txt
./data/manual/index.txt

Every folder inside manual, including manual, must have a 'index.txt'.

If you so desire, you may change the name of the files and folders, on the definitions below.

Treat the return code as a way to run different things
*/

int handleArgs(int argc,char *argv[]);

void noArgument();

void unknownArgument(char* arg);

int run(char *argv);

void printHelp();

void printVersion();

void printManual(char* arg);

#define EASY_ARGUMENTS_RUN "-r"
#define EASY_ARGUMENTS_HELP "-h"
#define EASY_ARGUMENTS_VERSION "-v"
#define EASY_ARGUMENTS_MANUAL "-m"

#define EASY_ARGUMENTS_EXTENTION ".txt"

#define EASY_ARGUMENTS_DATA_FOLDER "data/"
#define EASY_ARGUMENTS_MANUAL_FOLDER "manual/"

#define EASY_ARGUMENTS_VERSION_FILE "version"
#define EASY_ARGUMENTS_CREDITS "credits"
#define EASY_ARGUMENTS_INDEX "index"

#define EASY_ARGUMENTS_LINE_MAX_SIZE 150

#define EASY_ARGUMENTS_NO_ARGUMENT "\nPlease, use an argument:\n'%s' to run the program\n'%s' to see all avaliable basic arguments\n\n"
#define EASY_ARGUMENTS_UNKNOWN_ARGUMENT "\nArgument '%s' does not exist.\nPlease use '%s' to list all basic arguments.\n\n"
#define EASY_ARGUMENTS_HELP_RUN "'%s'\tRuns the program\n"
#define EASY_ARGUMENTS_HELP_HELP "'%s'\tPrints this screen\n"
#define EASY_ARGUMENTS_HELP_VERSION "'%s'\tPrints the current version, and its contributors\n"
#define EASY_ARGUMENTS_HELP_MANUAL "'%s ?'\tPrints the manual for something\n"

#define EASY_ARGUMENTS_VERSION_NOT_FOUND "\nVersion file not found :(\n\n"
#define EASY_ARGUMENTS_CREDITS_NOT_FOUND "\nCredits file not found :(\n\n"
#define EASY_ARGUMENTS_MANUALS_NOT_FOUND "\nNo manual file or folder found :(\n\n"

#define EASY_ARGUMENTS_RUNNING "\nRunning (%d)\n\n"
#define EASY_ARGUMENTS_DEFAULT_RETURN_CODE -1

int handleArgs(int argc,char *argv[]){
    if(argc <= 1){
        noArgument();
    }
    else if(strcmp(argv[1],EASY_ARGUMENTS_RUN) == 0){
        if(argc <= 2){
            return run("");
        }
        else{
            return run(argv[2]);
        }
    }
    else if(strcmp(argv[1],EASY_ARGUMENTS_HELP) == 0){
        printHelp();
    }
    else if(strcmp(argv[1],EASY_ARGUMENTS_VERSION) == 0){
        printVersion();
    }
    else if(strcmp(argv[1],EASY_ARGUMENTS_MANUAL) == 0){
        if(argc <= 2){
            printManual(EASY_ARGUMENTS_INDEX);
        }
        else{
            printManual(argv[2]);
        }
    }
    else{
        unknownArgument(argv[1]);
    }
    
    return EASY_ARGUMENTS_DEFAULT_RETURN_CODE;
}

void noArgument(){
    printf(EASY_ARGUMENTS_NO_ARGUMENT,EASY_ARGUMENTS_RUN,EASY_ARGUMENTS_HELP);
}

void unknownArgument(char* arg){
    printf(EASY_ARGUMENTS_UNKNOWN_ARGUMENT,arg,EASY_ARGUMENTS_HELP);
}

int run(char *argv){
    int code = 0;
    if(strcmp(argv,"") != 0){
        code = atoi(argv);
    }
    printf(EASY_ARGUMENTS_RUNNING,code);
    return code;
}

void printHelp(){
    printf(EASY_ARGUMENTS_HELP_RUN,EASY_ARGUMENTS_RUN);
    printf(EASY_ARGUMENTS_HELP_HELP,EASY_ARGUMENTS_HELP);
    printf(EASY_ARGUMENTS_HELP_VERSION,EASY_ARGUMENTS_VERSION);
    printf(EASY_ARGUMENTS_HELP_MANUAL,EASY_ARGUMENTS_MANUAL);
}

int printFile(char* path,char* notFound){
    FILE *fptr;

    fptr = fopen(path, "r");

    int status = 0;

    if(fptr != NULL){
        status = 1;
        char content[EASY_ARGUMENTS_LINE_MAX_SIZE];

        printf("\n");
        while(!feof(fptr)){
            fgets(content,EASY_ARGUMENTS_LINE_MAX_SIZE,fptr);

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

void printVersion(){
    char pth[200];

    strcpy(pth,EASY_ARGUMENTS_DATA_FOLDER);
    strcat(pth,EASY_ARGUMENTS_VERSION_FILE);
    strcat(pth,EASY_ARGUMENTS_EXTENTION);

    printFile(pth,EASY_ARGUMENTS_VERSION_NOT_FOUND);

    strcpy(pth,EASY_ARGUMENTS_DATA_FOLDER);
    strcat(pth,EASY_ARGUMENTS_CREDITS);
    strcat(pth,EASY_ARGUMENTS_EXTENTION);

    printFile(pth,EASY_ARGUMENTS_CREDITS_NOT_FOUND);
}

void printManual(char* arg){
    char pth[200];

    strcpy(pth,EASY_ARGUMENTS_DATA_FOLDER);
    strcat(pth,EASY_ARGUMENTS_MANUAL_FOLDER);
    strcat(pth,arg);
    strcat(pth,EASY_ARGUMENTS_EXTENTION);

    if(printFile(pth,NULL) == 0){
        strcpy(pth,EASY_ARGUMENTS_DATA_FOLDER);
        strcat(pth,EASY_ARGUMENTS_MANUAL_FOLDER);
        strcat(pth,arg);
        strcat(pth,"/");
        strcat(pth,EASY_ARGUMENTS_INDEX);
        strcat(pth,EASY_ARGUMENTS_EXTENTION);

        printFile(pth,EASY_ARGUMENTS_MANUALS_NOT_FOUND);
    }
}

#endif