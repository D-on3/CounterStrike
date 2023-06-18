#include "Weapons/Pistol.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * Decrease currBullets with 1.
 * @param self pointer to struct of type Pistols
 */
static void fireOneBullet(Pistol *self)
{
    self->currClipBullets --;
}

/**
 * Decrease remainingShots with 1.
 * @param self pointer to struct of type Pistols
 */
static void decreaseRemainingShots(Pistol *self)
{
    self->remainingShots--;
}

/**
 * Checks if there are currClipBullets, if no -> reload bullets.
 * @param self pointer to struct of type Pistols
 * @return bool: true if there are bullets, and false if there are no bullets (before reloading).
 */
static bool checkAmmo(Pistol *self){
    if(self->currClipBullets <= 0){
        self->reload(self);
        return false;
    }
    return true;
}

/**
 * Sets damageToArmor and damageToHealth of pistol.
 * @param self pointer to struct of type Pistols
 * @param armorStatus bool, according to which are damages set
 */
static void setDamagesAccToArmorStatus(bool armorStatus, Pistol *self)
{
    self->damageToArmor = self->damagePerRound[armorStatus][DAMAGE_TO_ARMOR];
    self->damageToHealth = self->damagePerRound[armorStatus][DAMAGE_TO_HEALTH];
}

/**
 * Sets initial damages of pistol.
 * @param pistol pointer to struct of type Pistols
 * @param pistolDamagePerRound int, according to which are damages set
 */
static void setInitialDamage(Pistol *pistol, int pistolDamagePerRound)
{
    pistol->fullDamage = pistolDamagePerRound;
    pistol->damageToArmor = 0;
    pistol->damageToHealth = 0;
    pistol->damagePerRound[WITHOUT_ARMOR][DAMAGE_TO_HEALTH] = pistol->fullDamage;
    pistol->damagePerRound[WITHOUT_ARMOR][DAMAGE_TO_ARMOR] = 0;
}

/**
 * Sets aim (member of pistol) to a function.
 * @param pistol pointer to struct of type Pistols
 * @param typeOfPistol int, type of pistol (from Defines)
 * @param action void function pointer
 */
static void setAim(Pistol *self, int typeOfPistol, void* action)
{
    self->aim[typeOfPistol] = action;
}

/**
 * Reloads pistol with ammo.
 * @param self pointer to struct of type Pistols
 */
static void reload(Pistol *self){

    if (self->remainingAmmo <= 0)
    {
        printf("No ammo left\n");
        return;
    }

    if (self->remainingAmmo < self->fullClipSize)
    {
        self->currClipBullets = self->remainingAmmo;
        self->remainingAmmo = 0;
    }
    else
    {
        self->currClipBullets = self->fullClipSize;
        self->remainingAmmo -= self->fullClipSize;
        if (self->remainingAmmo < 0)
        {
            self->remainingAmmo = 0;
        }
    }

    printf("Reloading...\ncurrClipBullets: %d, remainingAmmo: %d\n",self->currClipBullets,self->remainingAmmo);
}

/**
 * Shooting Attack of pistol DesertEagle against target.
 * @param target pointer to struct of type PlayerVitalData
 * @param attackingPistol pointer to struct of type Pistols
 */
static bool DesertEagleShoot(PlayerVitalData *target, Pistol *attackingPistol)
{
    setDamagesAccToArmorStatus(target->armorStatus, attackingPistol);

    damageArmor(target, attackingPistol->damageToArmor);
    damageHealth(target, attackingPistol->damageToHealth);
    fireOneBullet(attackingPistol);

    printf("Enemy left with: %d health and %d armor\n",target->health,target->armor);

    return target->healthStatus;
}

/**
 * Initiates shooting Attack of pistol Glock against target.
 * @param target pointer to struct of type PlayerVitalData
 * @param attackingPistol pointer to struct of type Pistols
 */
static bool GlockShoot(PlayerVitalData *target, Pistol *attackingPistol)
{
    int numberOfShots = attackingPistol->remainingShots;
    
    for(int shot = 0; shot < numberOfShots; shot++)
    {
        bool isAmmoInPistol = checkAmmo(attackingPistol);
        if (!isAmmoInPistol)
        {
            return target->healthStatus;
        }

        damageArmor(target, attackingPistol->damageToArmor);
        damageHealth(target, attackingPistol->damageToHealth);
        fireOneBullet(attackingPistol);

        printf("Enemy left with: %d health and %d armor\n", target->health, target->armor);
        
        if(target->healthStatus)
        {
            break;
        }

        decreaseRemainingShots(attackingPistol);

        setDamagesAccToArmorStatus(target->armorStatus, attackingPistol);
    }

    return target->healthStatus;
}

void initPistol(Pistol *pistol, int pistolId, int pistolDamagePerRound, int pistolClipSize, int pistolRemainingAmmo)
{
    pistol->pistolType = pistolId;
    setInitialDamage(pistol, pistolDamagePerRound);
    pistol->fullClipSize = pistolClipSize;
    pistol->currClipBullets = pistolClipSize;
    pistol->remainingAmmo = pistolRemainingAmmo;
    pistol->remainingShots = WITHOUT_ARMOR;

    pistol->reload = reload;

    switch (pistolId){
        case GLOCK:         setAim(pistol,NORMAL,GlockShoot);
                            pistol->damagePerRound[WITH_ARMOR][DAMAGE_TO_HEALTH] = pistol->fullDamage / 2;
                            pistol->damagePerRound[WITH_ARMOR][DAMAGE_TO_ARMOR] = pistol->fullDamage / 2;
                            break;
    
        case DESERT_EAGLE:  setAim(pistol,NORMAL,DesertEagleShoot);
                            pistol->damagePerRound[WITH_ARMOR][DAMAGE_TO_HEALTH] = (pistol->fullDamage * 3) / 4;
                            pistol->damagePerRound[WITH_ARMOR][DAMAGE_TO_ARMOR] = pistol->fullDamage / 4;
                            break;
    
        default:            break;
    }
}

/**
 * Shooting of pistol against target. Calls aim
 * @param target pointer to struct of type PlayerVitalData
 * @param attackingPistol pointer to struct of type Pistols
 */
static void shooting(PlayerVitalData *target, Pistol *attackingPistol)
{
    attackingPistol->remainingShots = ROUNDS_PER_FIRE;

    setDamagesAccToArmorStatus(target->armorStatus, attackingPistol);

    attackingPistol->aim[NORMAL](target, attackingPistol);
}

void usePistol(PlayerVitalData *target, Pistol *pistol)
{
    bool isAmmoInPistol = checkAmmo(pistol);
    if (isAmmoInPistol)
    {
        shooting(target, pistol);
    }
}
