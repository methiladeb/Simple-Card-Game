/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "Card.hpp"

/*
   Destructor for the Card class.
   Deletes the dynamically allocated memory for the bitmap array.
*/
Card::~Card() {
    delete[] bitmap_;
}

/*
   Copy constructor for the Card class.
   Copies the attributes from the provided Card object.
*/
Card::Card(const Card& rhs) : cardType_{rhs.cardType_}, instruction_{rhs.instruction_}, bitmap_{rhs.bitmap_}, drawn_{rhs.drawn_} {}

/*
   Copy assignment operator for the Card class.
   Copies the attributes from the provided Card object, ensuring proper handling of the bitmap array.
*/
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

/*
   Move constructor for the Card class.
   Moves the attributes from the provided Card object.
*/
Card::Card(Card&& rhs) {
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
}

/*
   Move assignment operator for the Card class.
   Moves the attributes from the provided Card object.
*/
Card& Card::operator=(Card&& rhs) {
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
    return *this;
}

/*
   Default constructor for the Card class.
   Initializes the card as a point card with empty instruction, zero bitmap, and not drawn.
*/
Card::Card() {
    cardType_ = POINT_CARD;
    instruction_ = "";
    bitmap_ = 0;
    drawn_ = false;
}

/*
   Returns a string representation of the card type ("POINT_CARD" or "ACTION_CARD").
*/
std::string Card::getType() const {
    return (cardType_ == POINT_CARD) ? "POINT_CARD" : "ACTION_CARD";
}

/*
   Sets the card type to the provided type (POINT_CARD or ACTION_CARD).
*/
void Card::setType(const CardType& type) {
    cardType_ = type;
}

/*
   Returns a constant reference to the instruction associated with the card.
*/
const std::string& Card::getInstruction() const {
    return instruction_;
}

/*
   Sets the instruction for the card.
*/
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}

/*
   Returns a constant pointer to the bitmap data associated with the card.
*/
const int* Card::getImageData() const {
    return bitmap_;
}

/*
   Sets the bitmap data for the card.
*/
void Card::setImageData(int* data) {
    bitmap_ = data;
}

/*
   Returns a boolean indicating whether the card has been drawn.
*/
bool Card::getDrawn() const {
    return drawn_;
}

/*
   Sets the drawn status for the card.
*/
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}