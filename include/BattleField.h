#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_


#include "Players/Player.h"
#include "Players/PlayerVitalData.h"
#include "Weapons/Pistol.h"
#include "Vector.h"


typedef struct {
  Vector counterTerrorists;
  Vector terrorists;
} BattleField;


/**
 * Construct players with their health and armor specifics
 * @param battleField pointer to struct of Battlefield with Vector counter-terrorists and Vector terrorist.
 * @return Error return type of error or NO_ERROR.
 */
Error createPlayers(BattleField* bf);


/**
 * Players take their weapon with specifics of damage , clip size, remeining ammo
 * @param battleField pointer to struct of Battlefield with Vector counter-terrorists and Vector terrorist.
 * @return Error return type of error or NO_ERROR.
 */
Error buyPistols(BattleField* bf);


/**
 * Check the result of battle
 * @param battleField pointer to struct of Battlefield with Vector counter-terrorists and Vector terrorist.
 * @return Error return type of error or NO_ERROR.
 */
Error startBattle(BattleField *bf);


/**
 * Generate attack of player
 * @param PlayerVitalData pointer to enemy health and armor.
 * @param Player pointer to struct of attacker.
 * @return bool Alive or Destroyed.
 */
enum HealthStatus playerTurn(PlayerVitalData *enemy, Player *attacker);


/**
 * @param BattleField pointer to vectors with teams.
 * @param Error returns type of error with pointer.
 * @return int id of teams who wins.
 */
int battle(BattleField* bf ,Error *err);


/**
 * Free memory for battlefield and fleets
 * @param battleField pointer to struct of Battlefield with Vector counter-terrorists and Vector terrorist.
 */
void deInit(BattleField *battleField);

#endif /* BATTLEFIELD_H_ */
