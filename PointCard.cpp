/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Methila Deb
Date: 11/03/2023
*/
#include "PointCard.hpp"

//Constructor
PointCard::PointCard() {
    setType(CardType::POINT_CARD); // Set the card type to POINT_CARD
}

//Determine if the PointCard is playable
bool PointCard::isPlayable() {
    const std::string instruction = getInstruction();
    try {
        int points = std::stoi(instruction);
        return true; // Card is playable
    } 
    catch (const std::invalid_argument&) {
        // Invalid number, card is not playable
        return false; // Card not playable
    }
}

//Print PointCard
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
