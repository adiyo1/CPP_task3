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
#include <iostream>
#include "enums.hpp"

catan::catan(player &p1, player &p2, player &p3)
{
    players_.push_back(&p1);
    players_.push_back(&p2);
    players_.push_back(&p3);
    currentPlayer_ = &p1;
    gameBoard_ = new board();
}

catan::~catan()
{
    delete gameBoard_;
}

board &catan::getBoard()
{
    return *gameBoard_;
}

void catan::ChooseStartingPlayer()
{
    player *startingPlayer = players_[0];
    std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
}
void catan::rollDiceAndDistributeResources(player &currentPlayer)
{

    int roll = currentPlayer.rollDice();
    std::cout << currentPlayer.getName() << " rolled a " << roll << std::endl;

    for (int i = 0; i < 53; i++)
    {

        vertex &vert = getBoard().getVertex(i);
        if (vert.getVertexOwner() == nullptr || vert.getVertexOwner() == 0)
        {
            ;
        }
        else
        {
            // std::cout << "Vertexvjhmvj, "  << std::endl;
            for (size_t j = 0; j < vert.getCirclesNumbers().size(); j++)
            {
                if (vert.getCirclesNumbers()[j] == roll)
                {
                    if (gameBoard_->getVertex(i).getAvaliable() == 1)
                    {
                        vert.getVertexOwner()->getPlayerResources()[vert.getVertexResources()[i]]++;
                        // currentPlayer.getPlayerResources()[vert->getVertexResources()[i]]++;
                        std::cout << currentPlayer.getName() << " received 1 " << vert.getVertexResources()[i] << std::endl;
                    }
                    if (gameBoard_->getVertex(i).getAvaliable() == 2)
                    {
                        vert.getVertexOwner()->getPlayerResources()[vert.getVertexResources()[i]] += 2;
                        std::cout << currentPlayer.getName() << " received 2 " << vert.getVertexResources()[i] << std::endl;
                    }
                }
            }
        }

        //     }
        //         for(edge* edge : vert->getEdges()){
        //             if(edge->getEdgeOwner() != nullptr){
        //                 hexagon* hex = edge->getHexagon();
        //                 if(hex->getHexagonCircleNumber() == roll){
        //                     currentPlayer.getPlayerResources()[hex->getResourceType()]++;
        //                     std::cout << currentPlayer.getName() << " received 1 " << hex->getResourceType() << std::endl;
        //                 }
        //             }
        //         }
        //     }
        // }
        // // Iterate through all hexagons on the game board
        // for (hexagon& hex : gameBoard_->getHexagons()) {
        //     if (hex.getHexagonCircleNumber() == roll) {
        //         // Get all vertices (corners) of this hexagon
        //         for (vertex* vert : hex.getVertices()) {
        //             // Check if there is a settlement on this vertex
        //             player* owner = vert->getVertexOwner();
        //             if (owner != nullptr) {
        //                 // Increment the corresponding resource type for the settlement owner
        //                 owner->getPlayerResources()[hex.getResourceType()]++;
        //                 std::cout << owner->getName() << " received 1 " << hex.getResourceType() << std::endl;
        //             }
        //         }
        //     }
        // }
    }
}
