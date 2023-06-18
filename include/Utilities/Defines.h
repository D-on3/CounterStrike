#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdbool.h>


enum PistolType {
  GLOCK = 0, DESERT_EAGLE
};

enum HealthStatus{
  ALIVE = 0, DEAD,
};

enum ArmorStatus{
  WITHOUT_ARMOR = 0, WITH_ARMOR = 1, TOTAL_ARMOR_STATUSES
};
enum Teams {
  TERRORISTS = 0, COUTER_TERRORISTS, NUMBER_OF_TEAMS
};

enum pistolsActions{
  GLOCK_ATTACK = 0, DESERT_EAGLE_ATTACK, NUMBER_OF_PISTOLS
};

enum Aim{
    NORMAL = 0, TOTAL_AIMS
};
enum damgeOptions{
    DAMAGE_TO_HEALTH, DAMAGE_TO_ARMOR, TOTAL_DAMAGE_OPTIONS
};

enum GlockDefines {
  ROUNDS_PER_FIRE = 3
};

enum PlayerDefines {
  PLAYER_ONE, PLAYER_TWO, PLAYERS_COUNT
};


enum ClipState{
    EMPTY = 0 , FULL
};

#endif /* DEFINES_H_ */
