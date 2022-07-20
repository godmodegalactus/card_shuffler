#include <iostream>
#include <random>
#include <iostream>
#include <assert.h>
#include <fstream>
#include <algorithm>

#include "card.hpp"

std::vector<Card> shuffle_cards_randomly()
{
    std::vector<Card> cards;
    cards.reserve(52);
    // generate cards
    for( short i = 0; i < static_cast<short>(Suit::_max); ++i )
    {
        for (short j = 0; j < static_cast<short>(CardValue::_max); ++j)
        {
            cards.push_back(Card{static_cast<Suit>(i), static_cast<CardValue>(j)});
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle( cards.begin(), cards.end(), gen);
    return cards;
}

int main(int argc, char** argv) {
    std::random_device rd;
    if(rd.entropy() == 0)
    {
        std::cerr << "random device is not supported";
        std::cout << "random device is not supported";
        return -1;
    }

    auto cards = shuffle_cards_randomly();
    assert(cards.size()==52);
    
    for (auto card : cards)
    {
        std::cout << card.to_string() << "\n";
    }
    return 0;
}
