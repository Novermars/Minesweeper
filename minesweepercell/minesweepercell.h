#ifndef MINESWEEPERCELL_H_
#define MINESWEEPERCELL_H_

#include <cstddef>

class MinesweeperCell
{
    bool d_isBomb = false;
    char d_state = '*';             // * or F
    std::size_t d_numBombsNear = 0;
    bool d_visited = false;
    
    public:
        MinesweeperCell() = default;
        void setBomb();
        bool isBomb() const;
        void setState(char const ch);
        char state() const;
        void setNumBombsNear(std::size_t num);
        std::size_t numBombsNear() const;
        bool visited() const;
        void setVisited();
};

#endif
