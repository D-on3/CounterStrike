#include "Players/Player.h"
#include "Utilities/ErrorHandling.h"
#include <stdlib.h>



Player *initPlayerData(int health, int armor, Error *err)
{
    static int playerId = 0;
    *err = NO_ERROR ;
    Player *currentPlayer = (Player*) calloc (1 , sizeof(Player));
    *err = checkForError(currentPlayer, ALLOCATION_ERROR , CURRENT_FUNC_NAME);
    
    initPlayerVitalData(&currentPlayer->playerData, health, armor);
    currentPlayer->playerId = playerId;
    playerId++;

    return currentPlayer;
}