
#include "player.hpp"
#include "board.hpp"
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <iostream>

std::vector<player*> player::players_;

player::player()
    : name_(""), playerResources_(), victoryPoints_(0) {}

player::player(const std::string& name, std::map<resourceTypes, int> playerResources, int victoryPoints)
    : name_(name), playerResources_(playerResources), victoryPoints_(victoryPoints) {
    players_.push_back(this);
}

std::string player::getName() const {
    return name_;
}

std::map<resourceTypes, int> player::getPlayerResources() const {
    return playerResources_;
}

int player::getVictoryPoints() const {
    return victoryPoints_;
}

int player::rollDice() {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    return distribution(rng);
}

player* player::getPlayerByName(const std::string& name) {
    for (player* p : players_) {
        if (p->getName() == name) {
            return p;
        }
    }
    return nullptr;
}

void player::placeSettlement(board& gameBoard, int vertexId) {
    if (gameBoard.getVertex(vertexId).getVertexOwner() != nullptr) {
        throw std::invalid_argument("There is already a settlement in this location.");
    }
    if (!checkNeighboringVertices(gameBoard, vertexId)) {
        throw std::invalid_argument("There is already a settlement in this area.");
    }
    gameBoard.getVertex(vertexId).setVertexOwner(this);
    victoryPoints_++;
}

bool player::checkNeighboringVertices(board& gameBoard, int vertexId) {
    std::vector<vertex*> neighboringVertices = gameBoard.getVertex(vertexId).getNeighboringVertices();
    for (vertex* v : neighboringVertices) {
        if (v->getVertexOwner() != nullptr) {
            return false;
        }
    }
    return true;
}

bool player::checkFirstSettlements(board& gameBoard, int vertexId) {
    return gameBoard.getVertex(vertexId).getVertexOwner() == nullptr && checkNeighboringVertices(gameBoard, vertexId);
}

std::map<DevelopmentCard, int> player::getDevelopmentCards() const {
    return developmentCards_;
}

void player::initializeDevelopmentDeck() {
    developmentDeck_.clear();
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::Monopol);
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::YearOfPlenty);
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::BuildingRoads);
    developmentDeck_.insert(developmentDeck_.end(), 14, DevelopmentCard::Knight);
    developmentDeck_.insert(developmentDeck_.end(), 5, DevelopmentCard::VictoryPoint);

    std::shuffle(developmentDeck_.begin(), developmentDeck_.end(), randomEngine_);
}

DevelopmentCard player::drawDevelopmentCard() {
    if (developmentDeck_.empty()) {
        throw std::out_of_range("No more development cards available");
    }
    DevelopmentCard drawnCard = developmentDeck_.back();
    developmentDeck_.pop_back();
    developmentCards_[drawnCard]++;
    return drawnCard;
}

std::string player::getDevelopmentCardsSummary() const {
    std::ostringstream oss;
    for (const auto& card : developmentCards_) {
        std::string cardType;
        switch (card.first) {
            case DevelopmentCard::Monopol:
                cardType = "Monopol";
                break;
            case DevelopmentCard::YearOfPlenty:
                cardType = "Year Of Plenty";
                break;
            case DevelopmentCard::BuildingRoads:
                cardType = "Building Roads";
                break;
            case DevelopmentCard::Knight:
                cardType = "Knight";
                break;
            case DevelopmentCard::VictoryPoint:
                cardType = "Victory Point";
                break;
        }
        oss << cardType << ": " << card.second << "\n";
    }
    std:: cout << "player "<< name_<<" have this development cards:"<< std::endl;

    return oss.str();
}
