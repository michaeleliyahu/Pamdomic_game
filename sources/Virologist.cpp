#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Virologist &Virologist::treat(City city)
{
    if (!check_exist(card_list, city))
    {
        //if its the same city, we dont need this card
        if (this->_city!=city)
        {
             throw std::invalid_argument("dont have this card");
        } 
    }

    //check if there is cube to remove
    if (this->_board.disease_list[city] < 1)
    {
        throw std::invalid_argument("Virologist: not cubes to remove");
    }

    this->_board.disease_list[city]--;
    card_list.erase(city);

    return *this;
}