#ifndef PLAYER_H
#define PLAYER_H

#include "Weapons/Pistol.h"
#include "Utilities/ErrorHandling.h"


typedef struct Player {
    PlayerVitalData playerData;
    Pistol pistol;
    int playerId;
}Player;


/**
 * Initialize a new player in game.
 * @param int health
 * @param int armor
 * @param Error pointer to err return
 * @return Player
 */
Player *initPlayerData(int health, int armor, Error *err);

#endif /* PLAYER_H_ */