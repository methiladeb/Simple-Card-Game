/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "Card.hpp"

//Destructor
Card::~Card() {
    delete[] bitmap_;
}

//Copy Constructor
Card::Card(const Card& rhs) : cardType_{rhs.cardType_}, instruction_{rhs.instruction_}, bitmap_{rhs.bitmap_}, drawn_{rhs.drawn_} {}

//Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    if(bitmap_ != nullptr){
        bitmap_ = new int[80];
        std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_);
    }
    drawn_ = rhs.drawn_;
    return *this;
}

//Move Constructor
Card::Card(Card&& rhs) {
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
}

//Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
    return *this;
}


//Default Constructor
Card::Card() {
    cardType_ = POINT_CARD;
    instruction_ = "";
    bitmap_ = 0;
    drawn_ = false;
}

//Return string representation of the card type
std::string Card::getType() const {
    return (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
}

//Set card type
void Card::setType(const CardType& type) {
    cardType_ = type;
}

//Return string representation of card instruction
const std::string& Card::getInstruction() const {
    return instruction_;
}

//Set card instruction
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

//Return image data
const int* Card::getImageData() const {
    return bitmap_;
}

//Set image data
void Card::setImageData(int* data) {
    bitmap_ = data;
}

//Return drawn status of the card
bool Card::getDrawn() const {
    return drawn_;
}

//Set drawn status of the card
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}