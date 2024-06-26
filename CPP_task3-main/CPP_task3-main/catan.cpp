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
#include <algorithm>
catan::catan(player &p1, player &p2, player &p3)
{
    players_.push_back(&p1);
    players_.push_back(&p2);
    players_.push_back(&p3);

    currentPlayer_ = &p1;
    gameBoard_ = new board();
    initializeDevelopmentDeck();
}
void catan::initializeDevelopmentDeck()
{
    developmentDeck_.clear();
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::Monopol);
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::YearOfPlenty);
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::BuildingRoads);
    developmentDeck_.insert(developmentDeck_.end(), 14, DevelopmentCard::Knight);
    developmentDeck_.insert(developmentDeck_.end(), 5, DevelopmentCard::VictoryPoint);

    std::shuffle(developmentDeck_.begin(), developmentDeck_.end(), randomEngine_);
}
std::vector<DevelopmentCard> &catan::getDevelopmentDeck()
{
    return developmentDeck_;
}

catan::~catan()
{
    delete gameBoard_;
}

board &catan::getBoard()
{
    return *gameBoard_;
}
player *catan::getCurrentPlayer()
{
    return currentPlayer_;
}

void catan::ChooseStartingPlayer(player &p)
{
    player *startingPlayer = &p;
    startingPlayer->setIsMyTurn(true);
    std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
}
int catan::rollDiceAndDistributeResources(player &currentPlayer)
{
    if (currentPlayer.getIsMyTurn(*this) == false)
    {
        throw std::invalid_argument("It is not your turn");
    }

    int roll = currentPlayer.rollDice();
    // int roll = 6;

    std::cout << currentPlayer.getName() << " rolled a " << roll << std::endl;

    for (int i = 0; i < 54; i++)
    {
        const vertex vert = getBoard().getVertex(i);
        if (vert.getVertexOwner() != nullptr && vert.getVertexOwner() != 0)
        {
            for (int j = 0; j < vert.getCirclesNumbers().size(); j++)
            {
                if (vert.getCirclesNumbers()[j] == roll)
                {
                    for (int k = 0; k < getBoard().getHexagons().size(); k++)
                    {
                        if (getBoard().getHexagons()[k].getHexagonCircleNumber() == roll)
                        {
                            vert.getVertexOwner()->addResource(getBoard().getHexagons()[k].getResourceType(), 1);
                            // currentPlayer.addResource(getBoard().getHexagons()[k].getResourceType(),vert.getVertexResources()[j]);
                        }
                    }
                }
            }
        }
    }
    ////const vertex& vert = vertexes[12];
    // const vertex &vert = getBoard().getVertex(i);
    // if (vert.getVertexOwner() == nullptr || vert.getVertexOwner() == 0)
    // {
    //     ;
    // }
    // else
    // {
    //     // std::cout << "Vertexvjhmvj, "  << std::endl;
    //     for (size_t j = 0; j < vert.getCirclesNumbers().size(); j++)
    //     {
    //         if (vert.getCirclesNumbers()[j] == roll)
    //         {
    //             if (gameBoard_->getVertex(i).getAvaliable() == 1)
    //             {
    //                 std::cout<< "case11111"<<std::endl;
    //                 vert.getVertexOwner()->addResource(vert.getVertexResources()[i],1);
    //                 // vert.getVertexOwner()->getPlayerResources()[vert.getVertexResources()[i]]++;
    //                 std::cout<< vert.getVertexResources()[i] << std::endl;
    //                 std::cout << currentPlayer.getName() << " received 1 " << vert.getVertexResources()[i] << std::endl;
    //             }
    //             if (gameBoard_->getVertex(i).getAvaliable() == 2)
    //             {
    //                 vert.getVertexOwner()->addResource(vert.getVertexResources()[i],2);
    //                 // vert.getVertexOwner()->getPlayerResources()[vert.getVertexResources()[i]] += 2;
    //                 std::cout << currentPlayer.getName() << " received 2 " << vert.getVertexResources()[i] << std::endl;
    //             }
    //         }
    //     }
    // }

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

    if (roll == 7)
    {
        for (player *player : players_)
        {
            int sum = 0;
            sum = +player->getPlayerResources()[resourceTypes::clay];
            sum += player->getPlayerResources()[resourceTypes::wood];
            sum += player->getPlayerResources()[resourceTypes::sheep];
            sum += player->getPlayerResources()[resourceTypes::wheat];
            sum += player->getPlayerResources()[resourceTypes::stone];
            if (sum > 7)
            {
                player->getPlayerResources()[resourceTypes::clay] = player->getPlayerResources()[resourceTypes::clay] / 2;
                player->getPlayerResources()[resourceTypes::wood] = player->getPlayerResources()[resourceTypes::wood] / 2;
                player->getPlayerResources()[resourceTypes::sheep] = player->getPlayerResources()[resourceTypes::sheep] / 2;
                player->getPlayerResources()[resourceTypes::wheat] = player->getPlayerResources()[resourceTypes::wheat] / 2;
                player->getPlayerResources()[resourceTypes::stone] = player->getPlayerResources()[resourceTypes::stone] / 2;
            }
        }
    }
    return roll;
}
