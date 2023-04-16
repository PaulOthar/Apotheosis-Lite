#include "EasyConsoleGraphics.h"

int main(int argc,char** argv){
    EasyWall* ew = newEasyWall("-","|","+"," ");

    enableEasyWallComplex1(ew,"/","\\","\\","/");
    enableEasyWallComplex2(ew,"<",">","^","v");

    printEasyWall(ew);
    freeEasyWall(ew);
    return 0;
}