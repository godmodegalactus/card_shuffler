#include <iostream>
#include <random>
#include <iostream>
#include <assert.h>
#include <fstream>
#include <algorithm>

#include "card.hpp"

std::vector<Card> shuffle_cards_randomly()
{
    std::random_device rd;
    std::vector<Card> cards;
    std::mt19937 gen(rd());
    cards.reserve(52);
    std::uniform_int_distribution<> distrib(0, 51);
    // generate cards
    for( short i = 0; i < static_cast<short>(Suit::_max); ++i )
    {
        for (short j = 0; j < static_cast<short>(CardValue::_max); ++j)
        {
            cards.push_back(Card{static_cast<Suit>(i), static_cast<CardValue>(j)});
        }
    }

     random_shuffle( cards.begin(), cards.end(), [&gen, &distrib](){return distrib(gen);} );
}

int main(int argc, char** argv) {
    if(argc != 2)
    {
        return -1;
    }
    std::random_device rd;
    if(rd.entropy() == 0)
    {
        std::cerr << "random device is not supported";
        return -1;
    }

    auto cards = shuffle_cards_randomly();
    assert(cards.size()==52);
    
    std::fstream out_file(argv[1], std::ios_base::out);
}
