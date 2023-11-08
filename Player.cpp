/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "Player.hpp"


Player::Player() : score_(0), opponent_(nullptr), actiondeck_(nullptr), pointdeck_(nullptr) {}


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


const Hand& Player::getHand() const {
    return hand_;
}


void Player::setHand(const Hand& hand) {
    hand_ = hand;
}


int Player::getScore() const {
    return score_;
}


void Player::setScore(const int& score) {
    score_ = score;
}


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


void Player::drawPointCard() {
    if(pointdeck_ && !pointdeck_->IsEmpty()) {
        hand_.addCard(std::move(pointdeck_->Draw()));
    }
}


void Player::playPointCard() {
    if(!hand_.isEmpty()) {
        int cardPoints = hand_.PlayCard();
        score_ += cardPoints;
    }
}


void Player::setOpponent(Player* opponent) {
    opponent_ = opponent; 
}


Player* Player::getOpponent() {
    return opponent_;
}


void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
    actiondeck_ = actiondeck;
}


Deck<ActionCard>* Player::getActionDeck() {
    return actiondeck_;
}


void Player::setPointDeck(Deck<PointCard>* pointdeck) {
    pointdeck_ = pointdeck;
}


Deck<PointCard>* Player::getPointDeck() {
    return pointdeck_;
}