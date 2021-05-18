#include "Player.hpp"
namespace pandemic
{

    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board &board, City city) : Player(board, city) {}

        Dispatcher &fly_direct(City city);
        std::string role()
        {
            return "Dispatcher";
        }
    };
}