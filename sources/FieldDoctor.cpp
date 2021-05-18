#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

FieldDoctor &FieldDoctor::treat(City city)
{
    set<City> temp = this->_board.city_con[this->_city];

    //check if city connected
    if (temp.find(city) == temp.end()&&city!=this->_city)
    {
        throw std::invalid_argument("FieldDoctor: city are not connected");
    }

    //check if there is cube to remove
    if (this->_board.disease_list[city] >= 1)
    {
        this->_board.disease_list[city]--;
    }
    else
    {
        throw std::invalid_argument("FieldDoctor: not cubes to remove");
    }

    return *this;
}