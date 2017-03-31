#include "minesweeper.ih"

ostream &operator<<(ostream &out,
                                 Minesweeper const &minesweeper)
{
    for (auto const &row: minesweeper.d_gameBoard)
    {
        for (auto const &element: row)
        {
            out << element.state();
        }
        out << '\n';
    }
    return out;
}