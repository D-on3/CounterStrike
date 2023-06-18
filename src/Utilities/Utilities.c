#include "Utilities/Utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE 100

/**
 * Fixes some bugs with no return values in release build
 * @param unused_result number returned from a function, to be ignored here
 */
//
static inline void ignore_result(long long int unused_result){
    (void)unused_result;
}

void getValidInputDamage(int *pistolId, int *pistolDamagePerRound, int* pistolClipSize, int* pistolRemainingAmmo){

    bool isValidPistolId = false;
    bool isValidDamage = false;
    bool isValidClipSize = false;
    bool isValidRemainingAmmo = false;
    bool isValidInput = false;
    char Id[BUF_SIZE];
    char pistolDamage[BUF_SIZE];
    char clipSize[BUF_SIZE];
    char remainingAmmo[BUF_SIZE];


    do{
        ignore_result(scanf("%s %s %s %s", Id, pistolDamage, clipSize, remainingAmmo));
        while( getchar() != '\n' );
        isValidPistolId = validInput(Id);
        isValidDamage = validInput(pistolDamage);
        isValidClipSize = validInput(clipSize);
        isValidRemainingAmmo = validInput(remainingAmmo);

        if(isValidPistolId && isValidDamage && isValidClipSize && isValidRemainingAmmo )
        {
            isValidInput = true;
            *pistolId = atoi(Id);
            *pistolDamagePerRound = atoi(pistolDamage);
            *pistolClipSize = atoi(clipSize);
            *pistolRemainingAmmo = atoi(remainingAmmo);
        }
        else{
            printf("Format must be only a digits\n");
        }
        if (*pistolDamagePerRound % 4 != 0)
        {
            printf("Damage must be dividable by 4! Try again.\n");
        }
    }
    while (*pistolDamagePerRound % 4 != 0 || isValidInput == false  );

}


void getValidInputHealthArmor(int *playerHealth, int* playerArmor )
{
    bool isValidInput = false;
    bool isValidHealth = false;
    bool isValidArmor = false;
    char health[BUF_SIZE];
    char armor[BUF_SIZE];
    do{
        ignore_result( scanf("%s %s" , health, armor));
        while( getchar() != '\n' );
        isValidHealth = validInput(health);
        isValidArmor = validInput(armor);

        if(isValidHealth && isValidArmor) {
            isValidInput = true;
            *playerHealth = atoi(health);
            *playerArmor = atoi(armor);
        }
        if(isValidInput == false || *playerArmor < 0 || *playerHealth <= 0 )
        {
            printf("Please enter valid input\n");
        }

    } while (isValidInput == false || *playerArmor < 0 || *playerHealth <= 0 );


}

bool validInput(char input[])
{
    unsigned int i = 0 ;
    unsigned int len = strlen(input);

    while (i  < len )
    {
        if(!isdigit(input[i]))
        {
            return false;
        }
        i++;
    }

    return true ;

}

