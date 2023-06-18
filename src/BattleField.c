#include "BattleField.h"
#include "Utilities/Defines.h"
#include "Weapons/Pistol.h"
#include "Utilities/Utilities.h"
#include <stdio.h>
#include <stdlib.h>

int getTypeOfPistol(Pistol *self)
{
    return self->pistolType;
}

Error initTeamVectors(BattleField *battleField)
{
    Error err = NO_ERROR;

    int playersInTeam = PLAYERS_COUNT / NUMBER_OF_TEAMS;

    vectorInit(&battleField->terrorists, playersInTeam);
    err = checkForError(&battleField->terrorists, ALLOCATION_ERROR, CURRENT_FUNC_NAME);

    if(err)
    {
        return err;
    }

    vectorInit(&battleField->counterTerrorists, playersInTeam);
    err = checkForError(&battleField->counterTerrorists, ALLOCATION_ERROR, CURRENT_FUNC_NAME);

    return err;
}

Error createPlayers(BattleField *battleField) {

    Error err = NO_ERROR;

    err = initTeamVectors(battleField);

    if (err)
    {
        return err;
    }
    
    int playerHealth = 0;
    int playerArmor = 0;

    for (int playerId = 0; playerId < PLAYERS_COUNT; playerId++)
    {
        getValidInputHealthArmor(&playerHealth, &playerArmor);
        Player *newPlayer = initPlayerData(playerHealth, playerArmor, &err);
        int team = playerId % NUMBER_OF_TEAMS;

        switch (team)
        {
            case TERRORISTS:        vectorPush(&battleField->terrorists, newPlayer);
                                    break;
            case COUTER_TERRORISTS: vectorPush(&battleField->counterTerrorists, newPlayer);
                                    break;
        }
        //printf("player health %d player armor %d",playerHealth,playerArmor);
    }

    return err;
}

Error buyPistols(BattleField *battleField) {

    Error err = NO_ERROR;
    
    int pistolId = 0;
    int pistolDamagePerRound = 0;
    int pistolClipSize = 0;
    int pistolRemainingAmmo = 0;

    for (int playerId = 0; playerId < PLAYERS_COUNT; playerId++)
    {
        Player *currentPlayer = NULL;
        int team = playerId % NUMBER_OF_TEAMS;
        switch (team)
        {
            case TERRORISTS:        currentPlayer = vectorGet(&battleField->terrorists, playerId / PLAYERS_COUNT);
                                    break;
            case COUTER_TERRORISTS: currentPlayer = vectorGet(&battleField->counterTerrorists, playerId / PLAYERS_COUNT);
                                    break;
        }

        checkForError(currentPlayer, NULL_PARAMETER, CURRENT_FUNC_NAME);
        if (!err)
        {

            getValidInputDamage(&pistolId, &pistolDamagePerRound, &pistolClipSize, &pistolRemainingAmmo);
            initPistol(&currentPlayer->pistol, pistolId, pistolDamagePerRound, pistolClipSize, pistolRemainingAmmo);    
        }

    }

    return err;
}

Error startBattle(BattleField *bf)
{
    Error err = NO_ERROR;
    int playerWinner;

    playerWinner = battle(bf , &err);

    if (err)
    {
        return err;
    }

    printf("\nPlayer with ID: %d wins!\n", playerWinner);
    
    return err;
}

enum HealthStatus playerTurn(PlayerVitalData *enemy, Player *attacker)
{
    printf("\nPlayerID %d turn:\n", attacker->playerId);

    usePistol(enemy, &attacker->pistol);
    
    return enemy->healthStatus;
}

static void removePlayerFromBattleField(Vector *teamOfKilledPlayer, Player **killedPlayer)
{
    free(*killedPlayer);
    *killedPlayer = NULL;
    vectorPop(teamOfKilledPlayer);
}

int battle(BattleField *battleField, Error *err)
{
    *err = NO_ERROR;
    *err = checkForError(battleField, NULL_PARAMETER, CURRENT_FUNC_NAME);

    Player *attackingPlayer = NULL;
    Player *attackedPlayer = NULL;
    Vector *enemyTeam = NULL;
    bool isEnemyKilled = false;
    
    for (int playerId = 0; ; playerId++)
    {
        int attackingTeam = playerId % NUMBER_OF_TEAMS;
        
        switch (attackingTeam) {

            case TERRORISTS:        attackingPlayer = vectorBack(&battleField->terrorists);
                                    enemyTeam = &battleField->counterTerrorists;
                                    break;
            case COUTER_TERRORISTS: attackingPlayer = vectorBack(&battleField->counterTerrorists);
                                    enemyTeam = &battleField->terrorists;
                                    break;
            default:                *err = INVALID_TEAM;
                                    return INVALID_TEAM;
        }

        if (vectorIsEmpty(enemyTeam)) // check here if there was only one player in the game ?? do we need this ?
        {
            return attackingPlayer->playerId;
        }

        attackedPlayer = vectorBack(enemyTeam);
        isEnemyKilled = playerTurn((PlayerVitalData*)attackedPlayer, attackingPlayer);

        if (isEnemyKilled)
        {
            removePlayerFromBattleField(enemyTeam, &attackedPlayer);  
            if (vectorIsEmpty(enemyTeam))
            {
                return attackingPlayer->playerId;
            }
        }

    }
}

void deInit(BattleField *battleField)
{
   for(size_t teamPlayersA = 0; teamPlayersA < vectorGetSize(&battleField->counterTerrorists); teamPlayersA++){
       free(battleField->counterTerrorists.items[teamPlayersA]);
       battleField->counterTerrorists.items[teamPlayersA]= NULL;
   }


   for(size_t teamPlayersB = 0;  teamPlayersB < vectorGetSize(&battleField->terrorists); teamPlayersB++){
       free(battleField->terrorists.items[teamPlayersB]);
       battleField->terrorists.items[teamPlayersB]= NULL;
   }

   vectorFree(&battleField->counterTerrorists);
   vectorFree(&battleField->terrorists);
}
