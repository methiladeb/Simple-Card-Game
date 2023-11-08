/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "Deck.hpp"


/*
   Default constructor for the Deck class.
   Initializes an empty deck.
*/
template <typename CardType>
Deck<CardType>::Deck() {}

/*
   Destructor for the Deck class.
   No dynamic memory management needed, as the deck is based on a vector.
*/
template <typename CardType>
Deck<CardType>::~Deck() {}

/*
   Adds a card to the deck.
   Takes a constant reference to the card and appends it to the deck.
*/
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
    cards_.push_back(card);
}

/*
   Draws a card from the deck.
   If the deck is empty, throws a runtime error.
   Moves the last card in the deck using std::move and returns it.
*/
template <typename CardType>
CardType&& Deck<CardType>::Draw() {
    if (IsEmpty()) {
        throw std::runtime_error("Cannot draw from an empty deck.");
    }
    CardType&& drawnCard = std::move(cards_.back());
    cards_.pop_back();
    return std::move(drawnCard);
}

/*
   Checks if the deck is empty.
   Returns true if the deck has no cards, otherwise false.
*/
template <typename CardType>
bool Deck<CardType>::IsEmpty() const {
    return cards_.empty();
}

/*
   Shuffles the deck using a random number generator.
   Uses std::shuffle to randomize the order of the cards.
*/
template <typename CardType>
void Deck<CardType>::Shuffle() {
    std::mt19937 rng(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

/*
   Returns the current size of the deck.
*/
template <typename CardType>
int Deck<CardType>::getSize() const {
    return cards_.size();
}

/*
   Returns a copy of the deck as a vector of cards.
*/
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
    return cards_;
}
