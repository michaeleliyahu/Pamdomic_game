#include "Dispatcher.hpp"
#include "iostream"

using namespace std;
using namespace pandemic;

Dispatcher &Dispatcher::fly_direct(City city)
{
    //check if its the same city
    if (this->_city == city)
    {
        throw std::invalid_argument("Dispatcher: cannot fly from city to it self");
    }

    //checl if there is a station in that city
    if (check_exist(this->_board.station_list, this->_city))
    {
        set_city(city);
    }
    else
    {
        //if there is no station in the city, check if he had the card
        if (check_exist(card_list, city))
        {
            set_city(city);
            card_list.erase(city);
        }
        else
        {
            throw std::invalid_argument("dispatcher cant fly direct");
        }
    }
    return *this;
}