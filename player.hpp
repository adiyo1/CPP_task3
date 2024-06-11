// #pragma once
// #include <vector>
// #include <map>
// #include <string>
// #include "vertex.hpp"
// #include "development_card.hpp"
// #include <random>
// // Forward declaration of board class
// class board;

// class player {
// private:
//     std::string name_;
//     std::map<resourceTypes, int> playerResources_;
//     // int monopolCards;

//     int victoryPoints_;
//     static std::vector<player*> players_;
//     std::vector<DevelopmentCard> developmentDeck_;
//     std::map<DevelopmentCard, int> developmentCards_;
//     std::default_random_engine randomEngine_;

//     // void initializeDevelopmentDeck();

// public:
//     // Default constructor
//     player();

//     // Parameterized constructor with default values for the other parameters
//     player(std::string name, std::map<resourceTypes, int> playerResources = {}, int victoryPoints = 0);

//     // Getters
//     std::string getName() const;
//     std::map<resourceTypes, int> getPlayerResources() const;
//     int getVictoryPoints() const;
//     int rollDice();
//     void placeSettlement(board &gameBoard, int vertexId);
//     static player* getPlayerByName(const std::string& name);
//     bool checkFirstSettlements(board& gameBoard, int vertexId);
//     bool checkNeighboringVertices(board& gameBoard, int vertexId);

//     std::map<DevelopmentCard, int> getDevelopmentCards() const;



//     // Method to draw a development card
//     DevelopmentCard drawDevelopmentCard();

//     // Method to get a summary of development cards
//     std::string getDevelopmentCardsSummary() const;
//     void initializeDevelopmentDeck();
// };
#pragma once
#include <vector>
#include <map>
#include <string>
#include "vertex.hpp"
#include "development_card.hpp"
#include <random>

class board;

class player {
private:
    std::string name_;
    std::map<resourceTypes, int> playerResources_;
    int victoryPoints_;
    static std::vector<player*> players_;
    std::vector<DevelopmentCard> developmentDeck_;
    std::map<DevelopmentCard, int> developmentCards_;
    std::default_random_engine randomEngine_;

public:
    player();
    player(const std::string& name, std::map<resourceTypes, int> playerResources = {}, int victoryPoints = 0);

    std::string getName() const;
    std::map<resourceTypes, int> getPlayerResources() const;
    int getVictoryPoints() const;
    int rollDice();
    void placeSettlement(board& gameBoard, int vertexId);
    static player* getPlayerByName(const std::string& name);
    bool checkFirstSettlements(board& gameBoard, int vertexId);
    bool checkNeighboringVertices(board& gameBoard, int vertexId);
    std::map<DevelopmentCard, int> getDevelopmentCards() const;
    DevelopmentCard drawDevelopmentCard();
    std::string getDevelopmentCardsSummary() const;
    void initializeDevelopmentDeck();
};
