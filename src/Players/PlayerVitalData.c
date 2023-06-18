#include "Players/PlayerVitalData.h"
#include "Utilities/Defines.h"



void initPlayerVitalData(PlayerVitalData *playerVitalData, int health, int armor)
{
    playerVitalData->health = health;
    playerVitalData->armor = armor;
    playerVitalData->healthStatus = ALIVE;
    if (armor <= 0 ){
        playerVitalData->armorStatus = WITHOUT_ARMOR;
    }
    else{
        playerVitalData->armorStatus = WITH_ARMOR;

    }
}


void setHealthStatusToDeadIfNoHealth(PlayerVitalData *self)
{
    if(self->health <= 0)
    {
        self->healthStatus = DEAD;
    }
}

void damageHealth(PlayerVitalData *target, int damage)
{
    target->health -= damage;
    
    setHealthStatusToDeadIfNoHealth(target);
}


void damageArmor(PlayerVitalData *target, int damage)
{
    target->armor -= damage;
    damage = 0;
    if (target->armor < 0)
    {
        damage = target->armor * (-1);
        target->armor = 0;
    }
    if (damage > 0)
    {
        damageHealth(target, damage);
    }
}