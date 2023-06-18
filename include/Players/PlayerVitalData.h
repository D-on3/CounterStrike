#ifndef PLAYER_VITAL_DATA_H
#define PLAYER_VITAL_DATA_H

#include <stdbool.h>

typedef struct {
  int health;
  int armor;
  bool healthStatus;
  bool armorStatus;
} PlayerVitalData;


/**
 * Initialize a player vital data  .
 * @param PlayerVitalData pointer to player vital data
 * @param int health
 * @param int armor
 */
void initPlayerVitalData(PlayerVitalData *playerVitalData, int health, int armor);


/**
 * Set a player status Dead or Alive  .
 * @param PlayerVitalData pointer to player vital data
 */
void setHealthStatusToDeadIfNoHealth(PlayerVitalData *self);


/**
 * Take damage player
 * @param PlayerVitalData pointer to player who was shot.
 * @param int damage from attacker
 */
void damageHealth(PlayerVitalData *target, int damage);


/**
 * Take damage from armor
 * @param PlayerVitalData pointer to player who was shot.
 * @param int damage
 */
void damageArmor(PlayerVitalData *target, int damage);



#endif // PLAYER_VITAL_DATA_H