# Simple-Card-Game
This is a CSCI 33500 Fall 2023 project that simulates a card game environment with classes such as Player, ActionCard, PointCard, Deck, and Hand. The Player class manages hands, scores, and interactions between players. ActionCard and PointCard extend the Card base class, offering specialized functions for checking playability and printing details. The Deck class, a template, handles the addition, drawing, and shuffling of cards. Lastly, the Hand class manages the player's hand, supporting operations like reversing and playing cards. 

## Instructions:

For the assignment, the program will simulate a simple card game. To do so, the program must perform the following tasks:
1) Read the list of cards and some other information from an input file (.txt), sorting the cards into the "action deck" and "point deck" based on their type (may take multiple steps)
2) Shuffle the decks, if indicated in the input. We're currently testing random number generation for this - more instructions on shuffling will be given later.
3) Create the players and their hands, with each player starting at 0 points with an empty hand.
4) Have players take turns drawing and playing the top card of the action deck, then deleting it.
    a) Make sure the point cards drawn are put in players' hands.
    b) Make sure the point cards played from players' hands are scored then deleted.
5) Implement swapping hands with your opponent.
6) Implement reversing your hand efficiently.

Action Card Instructions:
- Draw x card(s).
- Play x card(s).
- Reverse hand.
- Swap hand with opponent.
