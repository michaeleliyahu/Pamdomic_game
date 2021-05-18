#pragma once
#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <set>
#include <sstream>
namespace pandemic
{

    class Player
    {
    protected:

        std::set<City> card_list;
        const int MIN_CARD = 5;
        bool check_medic = false;
        City _city;
        Board &_board;
        
    public:
        Player(Board &board, City city) : _board(board), _city(city) {}
        

        void set_city(City city)
        {
            this->_city = city;
        }
        virtual ~Player() {}

        Player &take_card(const City city);
        Player &drive(const City city);
        virtual Player &build();
        virtual Player &fly_direct(const City city);
        virtual Player &treat(const City city);
        Player &fly_charter(const City city);
        Player &fly_shuttle(const City city);
        virtual Player &discover_cure(const Color color);
        virtual std::string role();

    protected:
        static bool check_exist(std::set<City> list,const  City city);
        void check_if_medic(const City city);
        void delete_card(std::set<City> &list);
        void check_size(const int x) const;
        int check_enuagh_card(std::set<City> &list,const Color color);
    };

}