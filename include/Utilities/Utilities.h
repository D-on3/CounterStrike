#ifndef COUNTER_STRIKE_UTILITIES_H
#define COUNTER_STRIKE_UTILITIES_H

#include <stdbool.h>


/**
 * Get user input for pistol information and check for validation.
 * @param int pistol ID
 * @param int Damage
 * @param int Clip size
 * @param int Remainig ammo
 */
void getValidInputDamage(int *pistolId, int *pistolDamagePerRound, int* pistolClipSize, int* pistolRemainingAmmo);


/**
 * Get user input for new player health and armor
 * @param int Health
 * @param int Armor
 */
void getValidInputHealthArmor(int *playerHealth, int* playerArmor );


/**
 * Check for correct and valid input
 * @param char input
 */
bool validInput(char input[]);




#endif //COUNTER_STRIKE_UTILITIES_H
