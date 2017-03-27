#include "minesweeper.ih"

void Minesweeper::checkSurrounding(size_t const xCoord, size_t const yCoord)
{
    static int moves[8][2] = { {-1,0}, {-1, -1}, {0, -1}, {1, -1},
                        {1, 0}, {1, 1}, {0, 1}, {-1, 1}     };
    for (size_t l = 0; l < 8 /*sizeof(move) / sizeof(move[0]) */; ++l)
    {
        size_t possibleX = xCoord + moves[l][0];
        size_t possibleY = yCoord + moves[l][1];
        if (possibleX < 0 or possibleX >= d_size or possibleY < 0 or possibleY >= d_size)
            continue;
        if (d_gameBoard[possibleX][possibleY].visited())
            continue;
        if (d_gameBoard[possibleX][possibleY].numBombsNear() == 0)
        {
            cout << "x: " << possibleX << "\t y: " << possibleY << '\n';
            d_gameBoard[possibleX][possibleY].setState('0');
            checkSurrounding(possibleX, possibleY);
        }
        else if (d_gameBoard[possibleX][possibleY].numBombsNear() != 0)
        {
            cout << "nonzero  x: " << possibleX << "\t y: " << possibleY << '\n';
            d_gameBoard[possibleX][possibleY].setState('0' + d_gameBoard[possibleX][possibleY].numBombsNear());
        }
        cout << "test2\n";
        d_gameBoard[possibleX][possibleY].setVisited();
    }

}