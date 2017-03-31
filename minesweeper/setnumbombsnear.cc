#include "minesweeper.ih"

void Minesweeper::setNumBombsNear()
{
    int moves[8][2] = { {-1,0}, {-1, -1}, {0, -1}, {1, -1},
                        {1, 0}, {1, 1}, {0, 1}, {-1, 1}     };
    for (size_t row = 0; row < d_size; ++row) 
    {
        for (size_t col = 0; col < d_size; ++col) 
        {
            size_t num = 0;
            for (size_t idx = 0; idx != 8; ++idx)
            {
                size_t possibleRow = row + moves[idx][0];
                size_t possibleCol = col + moves[idx][1];
                if (possibleRow >= d_size or possibleCol >= d_size)
                    continue;
                num += d_gameBoard[possibleRow][possibleCol].isBomb() ? 1 : 0;
            }
            d_gameBoard[row][col].setNumBombsNear(num);
        }
    }
}
