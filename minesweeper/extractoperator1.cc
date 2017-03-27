#include "minesweeper.ih"

ostream &operator<<(ostream &out,
                                 Minesweeper const &minesweeper)
{
    for (auto &row: minesweeper.d_gameBoard)
    {
        for (auto &element: row)
        {
            out << element.state();
        }
        out << '\n';
    }
}