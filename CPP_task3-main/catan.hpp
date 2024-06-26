
#pragma once

#include <vector>
// #include "player.hpp"
#include "board.hpp"
#include <random> 
enum class DevelopmentCard {
    Monopol,
    BuildingRoads,
    YearOfPlenty,
    Knight,
    VictoryPoint
};
class catan {
private:
    std::vector<player*> players_;
    player* currentPlayer_;
    board *gameBoard_;
    std::vector<DevelopmentCard> developmentDeck_;
    std::default_random_engine randomEngine_;


    

public:
    catan(player& p1, player& p2, player& p3);
    ~catan();
    board &getBoard();
    void ChooseStartingPlayer(player& p);
    // void catan::rollDiceAndDistributeResources(player& currentPlayer);
    void rollDiceAndDistributeResources(player& currentPlayer);
    void initializeDevelopmentDeck();
     std::vector<DevelopmentCard>& getDevelopmentDeck() ;
     player* getCurrentPlayer();
    //  void GAME_IS_OVER();

};

