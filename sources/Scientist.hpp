#include "Player.hpp"
namespace pandemic
{

    class Scientist : public Player
    {
    public:
        int _x;
        Scientist(Board &board, City city, int x) : Player(board, city), _x(x) {}

        Scientist &discover_cure(Color color);
        std::string role()
        {
            return "Scientist";
        }
    };
}