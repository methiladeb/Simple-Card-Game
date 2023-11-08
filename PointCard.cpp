/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/08/2023
*/

#include "PointCard.hpp"


/*
   Default constructor for the PointCard class.
   Sets the card type to POINT_CARD upon construction.
*/
PointCard::PointCard() {
    setType(CardType::POINT_CARD); 
}

/*
   Checks if the point card is playable.
   Attempts to convert the instruction to an integer.
   Returns true if successful, indicating a playable card. Otherwise, returns false.
*/
bool PointCard::isPlayable() {
    const std::string instruction = getInstruction();
    try {
        int points = std::stoi(instruction);
        return true; 
    } 
    catch (const std::invalid_argument&) {
        return false; 
    }
}

/*
   Prints information about the PointCard.
   Displays the card type, points, and the associated image data (if available).
*/
void PointCard::Print() const {
    std::cout << "Type: POINT_CARD" << std::endl;
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl;

    const int* imageData = getImageData();
    if (imageData != nullptr) {
        for (int i = 0; i < 80; i++) {
            std::cout << imageData[i] << " ";
        }
    } 
    else {
        std::cout << "No image data";
    }
    std::cout << std::endl;
}
