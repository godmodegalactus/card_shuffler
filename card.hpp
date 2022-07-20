#pragma once

enum class Suit : short
{
    spades = 0,
    hearts,
    clubs,
    diamonds,
    _max
};

enum class CardValue : short
{
    ace = 0,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    _max
};

namespace std
{
    std::string to_string(Suit s)
    {
        switch (s)
        {
        case Suit::spades:
            return "spades";
            break;
        case Suit::hearts:
            return "hearts";
        case Suit::clubs:
            return "clubs";
        case Suit::diamonds:
            return "diamonds";
        default:
            break;
        }
        return "Invalid";
    }

    std::string to_string(CardValue v)
    {
        switch (v)
        {
        case CardValue::ace:
            return "ace";
            break;
        case CardValue::two:
            return "two";
        case CardValue::three:
            return "three";
        case CardValue::four:
            return "four";
        case CardValue::five:
            return "five";
        case CardValue::six:
            return "six";
        case CardValue::seven:
            return "seven";
        case CardValue::eight:
            return "eight";
        case CardValue::nine:
            return "nine";
        case CardValue::ten:
            return "ten";
        case CardValue::jack:
            return "jack";
        case CardValue::queen:
            return "queen";
        case CardValue::king:
            return "king";
        default:
            break;
        }
        return "Invalid";
    }
}

struct Card 
{
    Suit suite;
    CardValue value;

    std::string to_string() const
    {
        return std::to_string(value) + " of " + std::to_string(suite);
    }
};