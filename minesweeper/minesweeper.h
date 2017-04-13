#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

#include <cstddef>
#include <vector>
#include <iosfwd>

#include "../minesweepercell/minesweepercell.h"

class Minesweeper
{
    std::size_t d_size = 9;        // square only so far
    std::size_t d_numBombs = 10;
    std::vector<std::vector<MinesweeperCell>> d_gameBoard;
    std::vector<MinesweeperCell *> d_bombLocations;
    
    public:
        Minesweeper();
        Minesweeper(std::size_t const size, std::size_t const numBoms);
        Minesweeper(Minesweeper const &minesweeper) = delete;
        Minesweeper &operator=(Minesweeper const &minesweeper) = delete;
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
