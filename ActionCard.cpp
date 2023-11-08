/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "ActionCard.hpp"

/*
   Default constructor for ActionCard class.
   Sets the card type to ACTION_CARD upon construction.
*/
ActionCard::ActionCard() {
    setType(CardType::ACTION_CARD);
}

/*
   Checks if the action card is playable based on its instruction.
   Returns true if the instruction matches any of the valid action patterns, otherwise false.
*/
bool ActionCard::isPlayable() {
    std::string instruction = getInstruction();
    std::regex validActionsRegex("(DRAW (\\d+) CARD(?:S)?)|(PLAY (\\d+) CARD(?:S)?)|(REVERSE HAND)|(SWAP HAND WITH OPPONENT)");
    return regex_search(instruction, validActionsRegex);
}
        
/*
   Prints information about the ActionCard.
   Displays the card type, instruction, and the associated image data (if available).
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