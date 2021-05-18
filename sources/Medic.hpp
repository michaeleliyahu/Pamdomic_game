#include "Player.hpp"
namespace pandemic
{

    class Medic : public Player
    {
    public:
        Medic(Board &board, City city) : Player(board, city)
        {
            check_medic = true;
        }

        Medic &treat(City city);
        std::string role()
        {
            return "Medic";
        }
    };
}