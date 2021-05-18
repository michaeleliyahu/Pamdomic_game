#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist &Scientist::discover_cure(Color color)
{
    //check if station exist
    if (!check_exist(this->_board.station_list, this->_city))
    {
        throw std::invalid_argument("Scientist: discover_cure: dont have station in this city");
    }
    //check if cure exist
    if (!this->_board.cure_exist[color])
    {
        //check if there is enuagh card in that color
        int num_card = check_enuagh_card(card_list, color);
        if (num_card < _x)
        {
            throw std::invalid_argument("Scientist: discover_cure: not enough card in that color");
        }
        this->_board.cure_exist[color] = true;
    }
    // set<City> help = this->_board.station_list;
    // //check if station exist
    // if (!check_exist(help, this->_city))
    // {
    //     throw std::invalid_argument("Scientist: dont have station in this city");
    // }
    // //check if cure exist
    // if (this->_board.cure_exist[color])
    // {
    //     return *this;
    // }

    // int count_card = 0;
    // set<City> temp;//keep card for delete
    // set<City>::iterator it = card_list.begin();
    // while (it != card_list.end() && count_card < _x)
    // {
    //     if (city_color[*it] == color)
    //     {
    //         count_card++;
    //         temp.insert(*it);
    //     }
    //     it++;
    // }
    // //if there is enough card
    // if (count_card >= _x)
    // {
    //     this->_board.cure_exist[color] = true;
    //     delete_card(temp);
    // }
    // else
    // {
    //     throw std::invalid_argument("Scientist: not enough card in that color");
    // }
    return *this;
}