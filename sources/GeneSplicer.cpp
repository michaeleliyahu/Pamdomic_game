#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

GeneSplicer &GeneSplicer::discover_cure(Color color)
{
    //if there is a cure already return
    if (this->_board.cure_exist[color]){return *this;}

    //if size lower then 5 throw error
    check_size(card_list.size()); 

    if (check_exist(this->_board.station_list, this->_city))
    {
        int counter = 0;
        set<City>::iterator it = card_list.begin();

        //delete five card from list
        while (it != card_list.end() && counter < MIN_CARD)
        {
            counter++;
            card_list.erase(*it);
        }
        this->_board.cure_exist[color] = true;
    }
    else
    {
        throw std::invalid_argument("GeneSplicer: dont have station in this city");
    }
    return *this;
}