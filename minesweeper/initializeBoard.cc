#include "minesweeper.ih"

void Minesweeper::initializeBoard()
{
    size_t numOfBombs = 0;
    uniform_int_distribution<int> distribution(0, d_size - 1);
    default_random_engine generator(random_device{}());
    
    while (numOfBombs != d_size + 1)
    {
        // generate a pair of indices
        pair<int, int> randomNums{distribution(generator), distribution(generator)};
        if (d_gameBoard[randomNums.first][randomNums.second].isBomb())
            continue;
        ++numOfBombs;
        d_gameBoard[randomNums.first][randomNums.second].setBomb();
        d_bombLocations.push_back(randomNums);
    }
}