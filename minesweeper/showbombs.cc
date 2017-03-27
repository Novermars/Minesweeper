#include "minesweeper.h"

void Minesweeper::showBombs()
{
    for (auto &location : d_bombLocations)
    {
        d_gameBoard[location.first][location.second].setState('B');
    }
}