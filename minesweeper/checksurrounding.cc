#include "minesweeper.ih"

void Minesweeper::checkSurrounding(size_t const xCoord, size_t const yCoord)
{
    static int moves[8][2] = { {-1,0}, {-1, -1}, {0, -1}, {1, -1},
                        {1, 0}, {1, 1}, {0, 1}, {-1, 1}     };
    for (size_t idx = 0; idx != 8 /*sizeof(move) / sizeof(move[0]) */; ++idx)
    {
        size_t possibleX = xCoord + moves[idx][0];
        size_t possibleY = yCoord + moves[idx][1];

        if (possibleX < 0 or possibleX >= d_size or possibleY < 0 or possibleY >= d_size)
            continue;

        if (d_gameBoard[possibleX][possibleY].visited())
            continue;

        d_gameBoard[possibleX][possibleY].setVisited();

        if (d_gameBoard[possibleX][possibleY].numBombsNear() == 0)
        {
            d_gameBoard[possibleX][possibleY].setState('0');
            checkSurrounding(possibleX, possibleY);
            continue;
        }

        d_gameBoard[possibleX][possibleY].setState('0' + d_gameBoard[possibleX][possibleY].numBombsNear());
    }
}