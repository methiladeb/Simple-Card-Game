/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "Player.hpp"

/*
   Default constructor for Player class.
   Initializes the player's score to 0 and sets the opponent, action deck, and point deck to nullptr.
*/
Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}

/*
   Destructor for Player class.
   Deletes the action deck and point deck if they exist to prevent memory leaks.
*/
Player::~Player() {
    if (actiondeck_) {
        delete actiondeck_;
        actiondeck_ = nullptr;
    }
    if (pointdeck_) {
        delete pointdeck_;
        pointdeck_ = nullptr;
    }
}

/*
   Returns a constant reference to the player's hand.
*/
const Hand& Player::getHand() const {
    return hand_;
}

/*
   Sets the player's hand with the provided Hand object.
*/
void Player::setHand(const Hand& hand) {
    hand_ = hand;
}

/*
   Returns the player's current score.
*/
int Player::getScore() const {
    return score_;
}

/*
   Sets the player's score to the provided value.
*/
void Player::setScore(const int& score) {
    score_ = score;
}

/*
   Plays the given ActionCard, executing the corresponding action based on the card's instruction.
*/
void Player::play(ActionCard&& card) {
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    if (card.getInstruction().find("DRAW") != std::string::npos) {
        int numberCards = std::stoi(card.getInstruction().substr(card.getInstruction().find("DRAW") +5));
        for (int i = 0; i < numberCards; i++) {
            drawPointCard();
        }
    }
    else if (card.getInstruction().find("PLAY") != std::string::npos) {
        int numberCards = std::stoi(card.getInstruction().substr(card.getInstruction().find("PLAY") +5));
        for (int i = 0; i < numberCards; i++) {
            playPointCard();
        }
    }
    else if(card.getInstruction() == "REVERSE HAND") {
        hand_.Reverse();
    }
    else if (card.getInstruction() == "SWAP HAND WITH OPPONENT") {
        Hand temp = hand_;
        hand_ = opponent_ -> getHand();
        opponent_ -> setHand(temp);
    }
}

/*
   Draws a point card from the player's point deck and adds it to their hand.
*/
void Player::drawPointCard() {
    if(pointdeck_ && !pointdeck_->IsEmpty()) {
        hand_.addCard(std::move(pointdeck_->Draw()));
    }
}

/*
   Plays a point card from the player's hand, updating the player's score.
*/
void Player::playPointCard() {
    if(!hand_.isEmpty()) {
        int cardPoints = hand_.PlayCard();
        score_ += cardPoints;
    }
}

/*
   Sets the opponent of the player.
*/
void Player::setOpponent(Player* opponent) {
    opponent_ = opponent; 
}

/*
   Returns a pointer to the opponent of the player.
*/
Player* Player::getOpponent() {
    return opponent_;
}

/*
   Sets the action deck for the player.
*/
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}

/*
   Returns a pointer to the action deck of the player.
*/
Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}

/*
   Sets the point deck for the player.
*/
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}

/*
   Returns a pointer to the point deck of the player.
*/
Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}