#include "minesweeper.ih"

bool Minesweeper::processInput(char const cmd, size_t const xCoord, size_t const yCoord)
{
    switch (cmd)
    {
        case 'f':
            d_gameBoard[xCoord][yCoord].setState('F'); //
            break;
        case 'u':
            d_gameBoard[xCoord][yCoord].setState('*'); //
            break;
        case 'p':
            if (d_gameBoard[xCoord][yCoord].isBomb() and d_gameBoard[xCoord][yCoord].state() != 'F')
            {
                cout << "Boom! You have hit a bomb and lost the game!\n";
                showBombs();
                return false;
            }
            if (d_gameBoard[xCoord][yCoord].state() == 'F')
            {
                cout << "This coordinate is flagged, please unflag first\n";
                break;
            }
            d_gameBoard[xCoord][yCoord].setState('0' + d_gameBoard[xCoord][yCoord].numBombsNear());
            if (d_gameBoard[xCoord][yCoord].numBombsNear() != 0)
                break;
            else
                checkSurrounding(xCoord, yCoord);
            break;
        default:
            cout << "Invalid command, please try again\n";
            break;

    }
    return true;
}