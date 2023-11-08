/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "Hand.hpp"


/*
   Default constructor for the Hand class.
   Initializes an empty hand.
*/
Hand::Hand() = default;

/*
   Destructor for the Hand class.
   No dynamic memory management needed, as the hand is based on a deque.
*/
Hand::~Hand() {}

/*
   Copy constructor for the Hand class.
   Copies the cards from the provided Hand object.
*/
Hand::Hand(const Hand& other) : cards_(other.cards_) {}

/*
   Copy assignment operator for the Hand class.
   Copies the cards from the provided Hand object, avoiding self-assignment.
*/
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

/*
   Move constructor for the Hand class.
   Moves the cards from the provided Hand object.
*/
Hand::Hand(Hand&& other) {
    cards_ = std::move(other.cards_);
}

/*
   Move assignment operator for the Hand class.
   Moves the cards from the provided Hand object.
*/
Hand& Hand::operator=(Hand&& other) {
    cards_ = std::move(other.cards_);
    return *this;
}

/*
   Returns a constant reference to the cards in the hand.
*/
const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

/*
   Adds a point card to the hand.
   Sets the drawn status of the card to true and appends it to the hand.
*/
void Hand::addCard(PointCard&& card) {
    card.setDrawn(true);
    cards_.push_back(card);
}

/*
   Checks if the hand is empty.
   Returns true if the hand has no cards, otherwise false.
*/
bool Hand::isEmpty() const {
    return cards_.empty();
}

/*
   Reverses the order of cards in the hand.
   Swaps the positions of cards from the left and right ends of the hand.
*/
void Hand::Reverse() {
    int left = 0;
    int right = cards_.size() - 1;
    while (left < right) {
        std::swap(cards_[left], cards_[right]);
        left++;
        right--;
    }
}

/*
   Plays a card from the hand.
   If the hand is empty or the front card is not playable, throws an error.
   Returns the points associated with the played card and removes it from the hand.
*/
int Hand::PlayCard() {
    if(isEmpty()) {
        throw std::runtime_error("Hand is empty. Cannot play a card.");
    }
    else if(!cards_.front().isPlayable()) {
        cards_.pop_front();
        throw std::runtime_error("No playable cards in the hand.");
    }
    PointCard frontOfCard = cards_.front();
    int points = std::stoi(frontOfCard.getInstruction());
    cards_.pop_front();
    return points;
}
