#ifndef ELEMENTAL_ALCHEMY
#define ELEMENTAL_ALCHEMY

//VVDDD999_88877766_65554443_33222111 [D = Dominant element][V = Leftover Valence] 

#include <stdio.h>

#define ELEMENT_COMPOUND_SIZE 9
#define ELEMENT_INDEX_SIZE 3
#define ELEMENT_MASK 0b111

int alchemy_next_free_slot(int compound){
    int i = 0;
    for(i = 0;i<ELEMENT_COMPOUND_SIZE;i++){
        if(!((compound>>(i*ELEMENT_INDEX_SIZE))&ELEMENT_MASK)){
            return i;
        }
    }
    return -1;
}

int alchemy_fetch_element_valence(int element){
    //"Inneficient, it should be an static value", you say, and i agree.
    return ((element)&0b1)+((element>>1)&0b1)+((element>>2)&0b1);
}

int alchemy_fetch_compound_element(int compound,int index){
    return (compound>>index*ELEMENT_INDEX_SIZE)&ELEMENT_MASK;
}

int alchemy_fetch_compound_valence(int compound){
    return (compound>>30)&0b11;//XX000000_00000000_00000000_00000000
}

int alchemy_fetch_compound_dominant(int compound){
    return alchemy_fetch_compound_element(compound,ELEMENT_COMPOUND_SIZE);//00XXX000_00000000_00000000_00000000
}

int alchemy_calculate_dominance(int compound){
    int i = 0;
    int currentElement = 0;
    int currentValence = 0;
    int finalElement = 0;
    int finalValence = 0;
    for(i = 0;i<ELEMENT_COMPOUND_SIZE;i++){
        currentElement = (compound>>(i*ELEMENT_INDEX_SIZE))&ELEMENT_MASK;
        currentValence = alchemy_fetch_element_valence(currentElement);

        if(!currentElement){
            continue;
        }

        if(currentValence >= finalValence){
            finalElement = currentElement;
            finalValence = currentValence-finalValence;
        }
        else{
            finalValence = finalValence-currentValence;
        }
    }

    int output = compound^(compound&0xf8000000);//Forces Valence and Dominance bits to become 0
    return output|(((finalValence<<ELEMENT_INDEX_SIZE)|finalElement)<<27);
}

//Requires Colorable Console
void print_colored_compound(int compound){
    int valence = alchemy_fetch_compound_valence(compound);
    printf("\033[48;2;%d;%d;%dm%02x",valence*0x55,valence*0x55,valence*0x55,valence);
    int i = 0;
    int currentElement = 0;
    for(i = 9;i>0;i--){
        currentElement = alchemy_fetch_compound_element(compound,i);
        printf("\033[48;2;%d;%d;%dm%03x",((currentElement&0b100)>>2)*0xff,((currentElement&0b10)>>1)*0xff,(currentElement&0b1)*0xff,currentElement);
    }
    printf("\033[0m");
}

#endif