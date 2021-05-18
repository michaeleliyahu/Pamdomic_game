#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
namespace pandemic
{

    class Board
    {
    public:
        std::map<City, std::set<City>> city_con = {
            {City::Algiers, {City::Madrid, City::Paris, City::Istanbul, Cairo}},
            {City::Atlanta, {City::Chicago, City::Miami, City::Washington}},
            {City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}},
            {City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}},
            {City::Beijing, {City::Shanghai, City::Seoul}},
            {City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}},
            {City::BuenosAires, {City::Bogota, City::SaoPaulo}},
            {City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}},
            {City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}},
            {City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}},
            {City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}},
            {City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}},
            {City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}},
            {City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}},
            {City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}},
            {City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}},
            {City::Johannesburg, {City::Kinshasa, City::Khartoum}},
            {City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}},
            {City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}},
            {City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg}},
            {City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong}},
            {City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa}},
            {City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}},
            {City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris}},
            {City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}},
            {City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}},
            {City::Manila, {City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}},
            {City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}},
            {City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}},
            {City::Milan, {City::Essen, City::Paris, City::Istanbul}},
            {City::Montreal, {City::Chicago, City::Washington, City::NewYork}},
            {City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}},
            {City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}},
            {City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid}},
            {City::Osaka, {City::Taipei, City::Tokyo}},
            {City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}},
            {City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi}},
            {City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}},
            {City::Santiago, {City::Lima}},
            {City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}},
            {City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo}},
            {City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}},
            {City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}},
            {City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles}},
            {City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila}},
            {City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi}},
            {City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}},
            {City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}}};
        std::map<City, Color> city_color =
            {
                {Chicago, Blue},
                {Atlanta, Blue},
                {MexicoCity, Yellow},
                {Khartoum, Yellow},
                {Kinshasa, Yellow},
                {HoChiMinhCity, Red},
                {Johannesburg, Yellow},
                {SaoPaulo, Yellow},
                {BuenosAires, Yellow},
                {Washington, Blue},
                {Madrid, Blue},
                {Taipei, Red},
                {Sydney, Red},
                {Seoul, Red},
                {LosAngeles, Yellow},
                {Miami, Yellow},
                {Bogota, Yellow},
                {Lima, Yellow},
                {Seoul, Red},
                {HongKong, Red},
                {Bangkok, Red},
                {Cairo, Black},
                {Beijing, Red},
                {Algiers, Black},
                {Istanbul, Black},
                {Paris, Blue},
                {Baghdad, Black},
                {Tehran, Black},
                {Riyadh, Black},
                {Karachi, Black},
                {Kolkata, Black},
                {Chennai, Black},
                {Jakarta, Red},
                {Shanghai, Red},
                {Delhi, Black},
                {Essen, Blue},
                {Manila, Red},
                {Baghdad, Black},
                {Tehran, Black},
                {Riyadh, Black},
                {Karachi, Black},
                {Kolkata, Black},
                {Chennai, Black},
                {Jakarta, Red},
                {Shanghai, Red},
                {Delhi, Black},
                {Osaka, Red},
                {Lagos, Yellow},
                {SanFrancisco, Blue},
                {Milan, Blue},
                {Mumbai, Black},
                {Montreal, Blue},
                {NewYork, Blue},
                {StPetersburg, Blue},
                {Santiago, Yellow},
                {Moscow, Black},
                {Tokyo, Red},
                {London, Blue}};

        std::map<City, int> disease_list;
        std::set<City> station_list;
        std::map<Color, bool> cure_exist = {{Blue, false}, {Red, false}, {Yellow, false}, {Black, false}};

        int &operator[](City city);
        bool is_clean();

        
        void remove_cures()
        {
            cure_exist.clear();
        }
        void remove_station()
        {
            station_list.clear();
        }
        friend std::ostream &operator<<(std::ostream &input, const Board &nl);
    };

}