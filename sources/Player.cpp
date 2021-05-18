#include "Player.hpp"
#include "Board.hpp"
#include "iostream"
#include <string>
#include <set>
using namespace std;
using namespace pandemic;

Player &Player::take_card(const City city)
{
    card_list.insert(city);
    return *this;
}

Player &Player::build()
{
    //check if he had this card
    if (!check_exist(card_list, this->_city))
    {
        throw std::invalid_argument("Player: build: no suitable card");
    }
    this->_board.station_list.insert(this->_city);
    card_list.erase(this->_city);

    return *this;
}

Player &Player::drive(const City city)
{
    check_if_medic(city);
    set<City> temp = this->_board.city_con[this->_city];
    //check if city connected
    if (temp.find(city) == temp.end())
    {
        throw std::invalid_argument("Player: drive: city are not connected");
    }
    set_city(city);
    return *this;
}

Player &Player::fly_direct(const City city)
{
    check_if_medic(city);
    auto it = card_list.find(city);
    //check if he had dest card
    if (it != card_list.end())
    {
        card_list.erase(it);
        set_city(city);
    }
    else
    {
        throw std::invalid_argument("Player: fly_direct: no suitable card");
    }
    return *this;
}

Player &Player::fly_charter(const City city)
{
    check_if_medic(city);
    auto it = card_list.find(this->_city);
    //check if he had src card
    if (it != card_list.end())
    {
        card_list.erase(it);
        set_city(city);
    }
    else
    {
        throw std::invalid_argument("Player: fly_charter: no suitable card");
    }
    return *this;
}

Player &Player::fly_shuttle(const City city)
{
    check_if_medic(city);
    if (this->_city == city)
    {
        throw std::invalid_argument("Player: fly_shuttle: cannot fly from city to it self");
    }
    set<City> temp = this->_board.station_list;
    //check if there is a station in both cities
    if (!check_exist(temp, this->_city) || !check_exist(temp, city))
    {
        throw std::invalid_argument("Player: fly_shuttle: station isnt exist in one city");
    }
    set_city(city);
    return *this;
}

Player &Player::treat(const City city)
{
    if (this->_city != city)
    {
        throw std::invalid_argument("Player: treat: you are not in the city.");
    }

    map<City, int>::iterator it = this->_board.disease_list.find(city);
    if (it->second == 0)
    {
        throw std::invalid_argument("Player: treat: zero cubes");
    }
    //if there is cure already reset cube
    if (this->_board.cure_exist[this->_board.city_color[city]])
    {
        it->second = 0;
        return *this;
    }
    it->second--;

    return *this;
}

Player &Player::discover_cure(const Color color)
{
    set<City> help = this->_board.station_list;
    //check if station exist
    if (!check_exist(help, this->_city))
    {
        throw std::invalid_argument("Player: discover_cure: dont have station in this city");
    }
    //check if cure exist
    if (this->_board.cure_exist[color])
    {
        return *this;
    }

    //check if there is enuagh card in that color
    int num_card = check_enuagh_card(card_list, color);
    if (num_card < MIN_CARD)
    {
        throw std::invalid_argument("Player: discover_cure: dont have enough card");
    }

    return *this;
}

string Player::role()
{
    return "null";
}

bool Player::check_exist(std::set<City> list,const  City city)
{
    bool exist = true;
    auto it = list.find(city);
    if (it != list.end())
    {
        return exist;
    }
    return false;
}
void Player::check_if_medic(const City city)
{
    if (check_medic && this->_board.cure_exist[this->_board.city_color[city]])
    {
        _board.disease_list[city] = 0;
    }
}
void Player::delete_card(std::set<City> &list)
{
    set<City>::iterator it2 = list.begin();
    while (it2 != list.end())
    {
        card_list.erase(*it2);
        it2++;
    }
}
void Player::check_size(const int x) const
{
    if (x < MIN_CARD)
    {
        throw std::invalid_argument("dont have enagth card");
    }
}
int Player::check_enuagh_card(std::set<City> &list,const Color color)
{
    int counter = 0;
    set<City> temp; //keep card for delete
    set<City>::iterator it = list.begin();
    //counter card in that color
    while (it != list.end() && counter < MIN_CARD)
    {
        if (this->_board.city_color[*it] == color)
        {
            counter++;
            temp.insert(*it);
        }
        it++;
    }
    if (counter >= MIN_CARD)
    {
        delete_card(temp);
        this->_board.cure_exist[color] = true;
    }

    return counter;
}
