#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Medic &Medic::treat(City city)
{
    //if not the same city throw error
    if (this->_city != city)
    {
        throw std::invalid_argument("Medic: you are not in the city.");
    }

    //if there is zero cube throw error
    if (this->_board.disease_list.find(city)->second == 0)
    {
        throw std::invalid_argument("medic treat: zero cubes");
    }
    this->_board.disease_list.find(city)->second=0;
    return *this;
}