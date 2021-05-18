#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

OperationsExpert &OperationsExpert::build()
{
    //if there is no station already, add station
    if (this->_board.station_list.find(this->_city) == this->_board.station_list.end())
    {
         this->_board.station_list.insert(this->_city);
    }

    return *this;
}
