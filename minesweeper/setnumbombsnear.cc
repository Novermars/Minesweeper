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
            for (size_t l = 0; l < 8 /*sizeof(move) / sizeof(move[0]) */; ++l) 
            {
                size_t ti = row + moves[l][0];
                size_t tj = col + moves[l][1];
                if (ti < 0 || ti >= d_size || tj < 0 || tj >= d_size) 
                    continue;
                num += d_gameBoard[ti][tj].isBomb() ? 1 : 0;
            }
            d_gameBoard[row][col].setNumBombsNear(num);
        }
    }
}
