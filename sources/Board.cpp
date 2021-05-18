#include "Board.hpp"
#include <map>
using namespace std;
using namespace pandemic;

//check if disease level in all board are zero
bool Board::is_clean()
{
    map<City, int>::iterator it = disease_list.begin();
    while (it != disease_list.end())
    {
        if (it->second > 0)
        {
            return false;
        }
        it++;
    }   
    return true;
}

int &Board::operator[](City city)
{
    //check if city exist in map, if not add city
    if (disease_list.find(city) == disease_list.end())
    {
        disease_list.insert(pair<City, int>(city, 0));
    }
    return disease_list.find(city)->second;
}


ostream &pandemic::operator<<(ostream &input, const Board &nl)
{
    input << "\n\nnumber of station:"<<nl.station_list.size()<<"\n";

    input << "\nstation in city: ";
    auto it = nl.station_list.begin();
    while (it != nl.station_list.end())
    {
        input << *it++;
        input << ", ";
    }
    input << "\n\ncolor cure:\n";
    auto it1 = nl.cure_exist.begin();
    while (it1 != nl.cure_exist.end())
    {
        input<<it1->first;
        input<<"-";
        input<<it1->second;
        input<<", ";
        it1++;
        
    }
    input<<"\n\n";
    return input;
}