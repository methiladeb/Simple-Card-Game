/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/03/2023
*/
#include "Hand.hpp"

//Default Constructor
Hand::Hand() = default;

//Destructor
Hand::~Hand() {
    
}

//Copy Constructor
Hand::Hand(const Hand& other) : cards_(other.cards_) {}

//Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
    if (this != &other) {
        cards_ = other.cards_;
    }
    return *this;
}

//Move Constructor
Hand::Hand(Hand&& other) {
    cards_ = std::move(other.cards_);
}

//Move Assignment Operator
Hand& Hand::operator=(Hand&& other) {
    cards_ = std::move(other.cards_);
    return *this;
}

//Get the cards in the hand
const std::deque<PointCard>& Hand::getCards() const {
    return cards_;
}

//Add a card to the hand
void Hand::addCard(PointCard&& card) {
    card.setDrawn(true);
    cards_.push_back(card);
}

//Check if the hand is empty
bool Hand::isEmpty() const {
    return cards_.empty();
}

//Reverse the hand
void Hand::Reverse() {
    int left = 0;
    int right = cards_.size() - 1;
    
    while (left < right) {
        // Swap the elements at 'left' and 'right'
        std::swap(cards_[left], cards_[right]);
        left++;
        right--;
    }
}

//Play a card from the hand
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
