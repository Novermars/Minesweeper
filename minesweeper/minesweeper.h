#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

#include <cstddef>
#include <vector>
#include <iosfwd>
#include <utility> 

#include "../minesweepercell/minesweepercell.h"

class Minesweeper
{
    std::size_t d_size;        // square only so far
    std::vector<std::vector<MinesweeperCell>> d_gameBoard;
    std::vector<std::pair<int, int>> d_bombLocations;
    public:
        Minesweeper(std::size_t const size = 9);
        void play();
    private:
        void initializeBoard();     // Places randomly d_size + 1 bombs on board
        void setNumBombsNear();
        void checkSurrounding(std::size_t const xCoord, std::size_t const yCoord);
        void showBombs();
        bool processInput(char const cmd, std::size_t const xCoord, std::size_t const yCoord);
        friend std::ostream &operator<<(std::ostream &out,
                                        Minesweeper const &minesweeper);
};

#endif
