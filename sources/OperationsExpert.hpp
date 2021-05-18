#include "Player.hpp"
namespace pandemic
{

    class OperationsExpert : public Player
    {
    public:

        OperationsExpert(Board &board, City city) : Player(board,city){}

        OperationsExpert &build();

        std::string role()
        {
            return "OperationsExpert";
        }
    };
}