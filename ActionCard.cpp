/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/03/2023
*/
#include "ActionCard.hpp"

/**
 * @post: Construct a new Action Card object
*/
ActionCard::ActionCard() {
    setType(CardType::ACTION_CARD);
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be valid
 * Valid instructions:
 * DRAW x CARD(S) : assume x is a positive integer
 * PLAY x CARD(S) : assume x is a positive integer
 * REVERSE HAND : reverse the order of the cards in the hand
 * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable() {
    std::string instruction = getInstruction();
    std::regex drawRegex("DRAW (\\d+) CARD(?:S)?");
    if (regex_search(instruction, drawRegex)){
        return true;
    }
    std::regex playRegex("PLAY (\\d+) CARD(?:S)?");
    if (regex_search(instruction, playRegex)){
        return true;
    }
    std::regex reverseHandRegex("REVERSE HAND");
    if (regex_search(instruction, reverseHandRegex)){
        return true;
    }
    std::regex swapHandRegex("SWAP HAND WITH OPPONENT");
    if (regex_search(instruction, swapHandRegex)){
        return true;
    }
    return false;
}

        
/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card: 
 * [ImageData]
 * 
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const {
    std::cout << "Type: ACTION_CARD" << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl;

    const int* imageData = getImageData();
    if (imageData != nullptr) {
        for (int i = 0; i < 80; ++i) {
            std::cout << imageData[i] << " ";
        }
    } 
    else {
        std::cout << "No image data";
    }
    std::cout << std::endl;
}