#include "minesweeper.ih"

Minesweeper::Minesweeper(size_t const size)
:
    d_size{size},
    d_gameBoard{vector<vector<MinesweeperCell>>(size, vector<MinesweeperCell>(size))}
{
    initializeBoard();
    setNumBombsNear();
}