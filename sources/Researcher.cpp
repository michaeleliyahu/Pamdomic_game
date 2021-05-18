#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

Researcher &Researcher::discover_cure(Color color)
{
    //if card list less then five throw error
    check_size(card_list.size());
    if (!this->_board.cure_exist[color])
    {
        //check if there is enuagh card in that color
        int num_card = check_enuagh_card(card_list, color);
        if (num_card < MIN_CARD)
        {
            throw std::invalid_argument("Researcher: dont have enough card");
        }
    }
    return *this;
}