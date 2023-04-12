#ifndef MANA_DATA
#define MANA_DATA

/*
Mana Data Dictates the general data of a item or creature mana reserve.

Some spent mana is required in order to level up.

Level up will have influence in the limit.

it is quite costly, so use carefully.
*/
typedef struct /*ManaData*/{
    int level[8];
    int reserve[8];
    int limit[8];
    int spent[8];
}

#endif