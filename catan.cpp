// #include "catan.hpp"
// #include "player.hpp"

// catan::catan(player p1, player p2, player p3) {
//     // Initialize players
//     players_.push_back(&p1);
//     players_.push_back(&p2);
//     players_.push_back(&p3);

//     // Initialize current player to the first player
//     currentPlayer_ = &p1;

//     // Create and initialize the game board
//     gameBoard_ = new board();
//     // You may need to implement a method to initialize the board based on game rules
// }

// // Destructor definition
// catan::~catan() {
//     // Clean up dynamically allocated memory, if any
//     delete gameBoard_;
// }

// board& catan::getBoard() {
//     // Implement your logic here to access the game board
//     return *gameBoard_;
// }

// void catan::ChooseStartingPlayer()
// {
//     player* startingPlayer = players_[0];
//     std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
// }
#include "catan.hpp"
#include "player.hpp"

catan::catan(player& p1, player& p2, player& p3) {
    players_.push_back(&p1);
    players_.push_back(&p2);
    players_.push_back(&p3);
    currentPlayer_ = &p1;
    gameBoard_ = new board();
}

catan::~catan() {
    delete gameBoard_;
}

board& catan::getBoard() {
    return *gameBoard_;
}

void catan::ChooseStartingPlayer() {
    player* startingPlayer = players_[0];
    std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
}
// void catan::rollDiceAndDistributeResources(player& currentPlayer) {
//     int roll = currentPlayer.rollDice() + currentPlayer.rollDice();
//     std::cout << currentPlayer.getName() << " rolled a " << roll << std::endl;

//     for (hexagon& hex : gameBoard_->getHexagons()) {
//         if (hex.getNumber() == roll) {
//             for (vertex* vert : hex.getVertices()) {
//                 player* owner = vert->getVertexOwner();
//                 if (owner != nullptr) {
//                     owner->getPlayerResources()[hex.getResourceType()]++;
//                     std::cout << owner->getName() << " received 1 " << hex.getResourceType() << std::endl;
//                 }
//             }
//         }
//     }
// }