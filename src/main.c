#include "BattleField.h"
#include <stdlib.h>
int main() {
    
    BattleField battleField;

    if (createPlayers(&battleField))
    {
        return EXIT_FAILURE;
    }

    if (buyPistols(&battleField))
    {
        return EXIT_FAILURE;
    }
    
    if (startBattle(&battleField))
    {
        return EXIT_FAILURE;
    }

    deInit(&battleField);

    return EXIT_SUCCESS;
}
