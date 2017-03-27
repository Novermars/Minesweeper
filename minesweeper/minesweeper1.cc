#include "minesweeper.ih"

Minesweeper::Minesweeper(size_t const size)
:
    d_size{size},
    d_gameBoard{std::vector<std::vector<MinesweeperCell>>(size, std::vector<MinesweeperCell>(size))}
{
    initializeBoard();
    setNumBombsNear();
}