#include "minesweeper.ih"

void Minesweeper::play()
{
    bool notDone = true;
    cout << *this;
    while (notDone)
    {
        char cmd;
        cin >> cmd;
        if (cmd ==  'q')
            break;

        size_t xCoord, yCoord;
        cin >> xCoord >> yCoord;
        if (xCoord < 0 or xCoord >= d_size or yCoord < 0 or yCoord >= d_size)
        {
            cout << "Please input valid coordinates\n";
            continue;
        }

        notDone = processInput(cmd, xCoord, yCoord);

        cout << *this;
    }
}

