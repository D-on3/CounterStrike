#ifndef PISTOL_H
#define PISTOL_H

#include "Utilities/Defines.h"
#include "Players/PlayerVitalData.h"
#include <stdbool.h>


typedef struct Pistol{
    enum PistolType pistolType;
    int fullDamage;
    int damageToHealth;
    int damageToArmor;
    int damagePerRound[TOTAL_ARMOR_STATUSES][TOTAL_DAMAGE_OPTIONS];
    int fullClipSize;
    int currClipBullets;
    int remainingAmmo;
    int remainingShots;
    void (*aim[TOTAL_AIMS])(PlayerVitalData *target, struct Pistol *self);
    void (*reload)(struct Pistol *self);
} Pistol;


/**
 * Initialize a new weapon of type pistols .
 * @param Pistol pointer to struct of type pistol
 * @param int Damage per round
 * @param int Clip size
 * @param int remaining ammo in drop pouch
 */
void initPistol(Pistol *pistol, int pistolId, int pistolDamagePerRound, int pistolClipSize, int pistolRemainingAmmo);


/**
 * Generate pistol attack , first check for ammo in clip.
 * @param PlayerVitalData pointer to health and armor stats
 * @param Pistol pointer to struct of type Pistols
 */
void usePistol(PlayerVitalData *target, Pistol *pistol);


#endif /* PISTOL_H_ */
