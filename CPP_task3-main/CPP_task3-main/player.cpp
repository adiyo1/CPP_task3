
#include "player.hpp"
#include "board.hpp"
#include <random>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include "catan.hpp"

std::vector<player *> player::players_;

player::player()
    : name_(""), playerResources_(), victoryPoints_(0)
{
    std::random_device rd;
    randomEngine_ = std::default_random_engine(rd());
}

player::player(const std::string &name, std::map<resourceTypes, int> playerResources, int victoryPoints, std::vector<vertex *> settlements, std::vector<edge *> roads, int NumOfRoads, int numSettlements, int NumOfCities, int NumOfKnights, bool isMyTurn)
    : name_(name), playerResources_(playerResources), victoryPoints_(victoryPoints), settlements_(settlements), roads_(roads), NumOfRoads_(NumOfRoads), NumOfSettlements_(numSettlements), NumOfCities_(NumOfCities), NumOfKnights_(NumOfKnights), isMyTurn_(isMyTurn)
{
    
    players_.push_back(this);
    std::random_device rd;
    randomEngine_ = std::default_random_engine(rd());
    // this->intializeDevelopmentDeck();
}

std::string player::getName() const
{
    return name_;
}

std::map<resourceTypes, int> player::getPlayerResources() const
{
    return playerResources_;
}

int player::getVictoryPoints() const
{
    return victoryPoints_;
}

int player::rollDice()
{
    std::uniform_int_distribution<int> distribution(2, 12);
    return distribution(randomEngine_);
}

player *player::getPlayerByName(const std::string &name)
{
    for (player *p : players_)
    {
        if (p->getName() == name)
        {
            return p;
        }
    }
    return nullptr;
}

void player::placeSettlement(board &gameBoard, int vertexId)
{
    if(isMyTurn_==false)
    {
        std::cout << "It is not your turn" << std::endl;
        return;
    }
    // std::cout <<"OWNER "<< gameBoard.getVertex(vertexId).getVertexOwner()<< std::endl;
    if (gameBoard.getVertex(vertexId).getVertexOwner() != 0 || gameBoard.getVertex(vertexId).getVertexOwner() != nullptr)
    {
        throw std::invalid_argument("There is already a settlement in this vertex.");
    }
    if (!checkNeighboringVertices(gameBoard, vertexId))
    {
        throw std::invalid_argument("There is already a settlement in this area.");
    }
    // if(settlements_.size()>0)
    // {
    //     if(playerResources_[resourceTypes::wood]==0||playerResources_[resourceTypes::clay]==0||playerResources_[resourceTypes::wheat]==0||playerResources_[resourceTypes::sheep]==0)
    //     {
    //         throw std::invalid_argument("You do not have enough resources to place a settlement.");
    //     }
    // }
    if (settlements_.size() < 2)
    {
        std::vector<resourceTypes> resources = gameBoard.getVertex(vertexId).getVertexResources();
        for (resourceTypes resource : resources)
        {
            playerResources_[resource]++;
            std::cout << "Player " << name_ << " received 1 " << resource << std::endl;
        }

        // gameBoard.getVertex(vertexId).getVertexResources();
        // gameBoard.getVertex(vertexId).setVertexOwner(this);
        // gameBoard.getVertex(vertexId).setAvaliable(1);//1 is have a settlement 0 is not
        // std::cout << "Player " << name_ << " placed a settlement on vertex " << vertexId << std::endl;
    }
    else
    {
        if (playerResources_[resourceTypes::wood] == 0 || playerResources_[resourceTypes::clay] == 0 || playerResources_[resourceTypes::wheat] == 0 || playerResources_[resourceTypes::sheep] == 0)
        {
            throw std::invalid_argument("You do not have enough resources to place a settlement.");
        }
        if (NumOfSettlements_ >= 5)
        {
            throw std::invalid_argument("You can only place 5 settlements.");
        }
        playerResources_[resourceTypes::wood]--;
        playerResources_[resourceTypes::clay]--;
        playerResources_[resourceTypes::wheat]--;
        playerResources_[resourceTypes::sheep]--;
    }
    settlements_.push_back(&gameBoard.getVertex(vertexId));
    NumOfSettlements_++;
    gameBoard.getVertex(vertexId).setVertexOwner(this);
    // vertex& targetVertex = gameBoard.getVertex(vertexId);
    // targetVertex.setVertexOwner(this);
    gameBoard.getVertex(vertexId).setAvaliable(1); // 1 is have a settlement 0 is not
    std::cout << "Player " << name_ << " placed a settlement on vertex " << vertexId << std::endl;
    victoryPoints_++;
    GAME_IS_OVER();
    gameBoard.getVertex(vertexId).setAvaliable(1);
}

int player::getNumOfRoads()
{
    return NumOfRoads_;
}
// bool player::checkNeighboringVertices(const board& gameBoard, int vertexId) {
//     const std::vector<int>& neighbors = gameBoard.getNeighboringVertices(vertexId);
//     for (int neighborId : neighbors) {
//         if (gameBoard.getVertex(neighborId).getVertexOwner() != 0) {
//             return false; // Found an occupied neighboring vertex
//         }
//     }
//     return true;
// }

bool player::checkNeighboringVertices(board &gameBoard, int vertexId)
{
    std::vector<vertex *> neighboringVertices = gameBoard.getVertex(vertexId).getNeighboringVertices();
    for (vertex *v : neighboringVertices)
    {
        // Print the ID of the neighboring vertex
        std::cout << v->getVertexId() << std::endl;
        // Print the owner of the neighboring vertex
        std::cout << v->getVertexOwner() << std::endl;
        if (v->getVertexOwner() != nullptr)
        { // 1 is have a settlement 0 is not
            std::cout << "You can not put a settlement on vertex " << v->getVertexId() << " becouse this vertex is owned by player " << v->getVertexOwner()->getName() << std::endl;
            return false;
        }
        if (v->getVertexOwner() != 0)
        {
            std::cout << "Vertex " << v->getVertexId() << " is owned by player " << v->getVertexOwner()->getName() << std::endl;
            return false;
        }
        // if(v->getAvaliable()==1)
        // {
        //     std::cout << "3Vertex " << v->getVertexId() << " is owned by player " << v->getVertexOwner()->getName() << std::endl;
        //     return false;
        // }
    }
    return true;
}

void player::placeRoad(board &gameBoard, int edgeId)
{
    if(isMyTurn_==false)
    {
        std::cout << "It is not your turn" << std::endl;
        return;
    }
    if (gameBoard.getEdge(edgeId).getEdgeOwner() != nullptr)
    {
        throw std::invalid_argument("There is already a road in this edge.");
    }
    // if(canPlaceRoad(gameBoard, edgeId) == false)
    // {
    //     throw std::invalid_argument("You can only place a road on an edge that is connected to one of your settlements.");
    // }
    if ((gameBoard.getEdge(edgeId).getVertexesOfTheEdge()[0]->getVertexOwner() != this && gameBoard.getEdge(edgeId).getVertexesOfTheEdge()[1]->getVertexOwner() != this) && canPlaceRoad(gameBoard, edgeId) == false)
    {
        throw std::invalid_argument("You can only place a road on an edge that is connected to one of your settlements or to one of your roads.");
    }
    
    if (NumOfRoads_ >= 14)
    {
        throw std::invalid_argument("You can only place 14 roads.");
    }
    
    else
    {
        if (gameBoard.getEdge(edgeId).getEdgeOwner() == this)
        {
            throw std::invalid_argument("You can only place a road on an edge that is not already occupied by you.");
        }
        if (NumOfRoads_ < 2)
        {
            this->playerResources_[resourceTypes::wood]++;
            this->playerResources_[resourceTypes::clay]++;
        }
        if (this->getPlayerResources()[resourceTypes::wood] == 0 || this->getPlayerResources()[resourceTypes::clay] == 0)
        {
            throw std::invalid_argument("You do not have enough resources to place a road.");
        }
        
        this->playerResources_[resourceTypes::wood]--;
        this->playerResources_[resourceTypes::clay]--;
    }
    roads_.push_back(&gameBoard.getEdge(edgeId));
    NumOfRoads_++;
    gameBoard.getEdge(edgeId).setEdgeOwner(this);
    std::cout << "Player " << name_ << " placed a road on edge " << edgeId << std::endl;
}

bool player::canPlaceRoad(board &gameBoard, int edgeId) const
{
    const edge &newEdge = gameBoard.getEdge(edgeId);
    for (const edge *existingEdge : roads_)
    {
        if (newEdge.isConnectedToEdge(*existingEdge))
        {
            return true;
        }
    }
    return false;
}



bool player::checkFirstSettlements(board &gameBoard, int vertexId)
{
    return gameBoard.getVertex(vertexId).getVertexOwner() == nullptr && checkNeighboringVertices(gameBoard, vertexId);
}

std::map<DevelopmentCard, int> player::getDevelopmentCards() const
{
    return developmentCards_;
}

// void player::initializeDevelopmentDeck()
// {
//     developmentDeck_.clear();
//     developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::Monopol);
//     developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::YearOfPlenty);
//     developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::BuildingRoads);
//     developmentDeck_.insert(developmentDeck_.end(), 14, DevelopmentCard::Knight);
//     developmentDeck_.insert(developmentDeck_.end(), 5, DevelopmentCard::VictoryPoint);

//     std::shuffle(developmentDeck_.begin(), developmentDeck_.end(), randomEngine_);
// }

// DevelopmentCard player::drawDevelopmentCard()
// {
//     if (developmentDeck_.empty())
//     {
//         throw std::out_of_range("No more development cards available");
//     }
//     // if (playerResources_[resourceTypes::wheat] == 0 || playerResources_[resourceTypes::sheep] == 0 || playerResources_[resourceTypes::stone] == 0)
//     // {
//     //     throw std::invalid_argument("You do not have enough resources to draw a development card.");
//     // }
//     DevelopmentCard drawnCard = developmentDeck_.back();
//     developmentDeck_.pop_back();
//     developmentCards_[drawnCard]++;
//     if (drawnCard == DevelopmentCard::Knight)
//     {
//         NumOfKnights_++;
//         updateLargestArmy();
//     }
//     switch (drawnCard)
//     {
//         case DevelopmentCard::Monopol:
//             std::cout << "You drew a Monopoly card." << std::endl;
//             break;
//         case DevelopmentCard::YearOfPlenty:
//             std::cout << "You drew a Year of Plenty card." << std::endl;
//             break;
//         case DevelopmentCard::BuildingRoads:
//             std::cout << "You drew a Road Building card." << std::endl;
//             break;
//         case DevelopmentCard::Knight:
//             std::cout << "You drew a Knight card." << std::endl;
//             break;
//         case DevelopmentCard::VictoryPoint:
//             std::cout << "You drew a Victory Point card." << std::endl;
//             break;
//         default:
//             // std::cout << "You drew an unknown development card." << std::endl;
//             break;
//     }
//     return drawnCard;
// }


DevelopmentCard player::drawDevelopmentCard(catan& game) {
    const std::vector<DevelopmentCard>& developmentDeck = game.getDevelopmentDeck(); // Access catan's developmentDeck_
    
    if (developmentDeck.empty()) {
        throw std::out_of_range("No more development cards available");
    }

    DevelopmentCard drawnCard = developmentDeck.back();
    // developmentDeck.pop_back(); // Assuming you have developmentDeck_ as member in player

    developmentCards_[drawnCard]++;

    // Perform specific actions based on the drawn card
    switch (drawnCard) {
        case DevelopmentCard::Monopol:
            std::cout << "You drew a Monopoly card." << std::endl;
            break;
        case DevelopmentCard::YearOfPlenty:
            std::cout << "You drew a Year of Plenty card." << std::endl;
            break;
        case DevelopmentCard::BuildingRoads:
            std::cout << "You drew a Road Building card." << std::endl;
            break;
        case DevelopmentCard::Knight:
            std::cout << "You drew a Knight card." << std::endl;
            NumOfKnights_++;
            updateLargestArmy();
            break;
        case DevelopmentCard::VictoryPoint:
            std::cout << "You drew a Victory Point card." << std::endl;
            break;
        default:
            // Handle unexpected cards
            std::cout << "You drew an unknown development card." << std::endl;
            break;
    }

    return drawnCard;
}

std::string player::getDevelopmentCardsSummary() const
{
    std::ostringstream oss;
    for (const auto &card : developmentCards_)
    {
        std::string cardType;
        switch (card.first)
        {
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
    std::cout << "Player " << name_ << " has the following development cards:\n"
              << oss.str() << std::endl;
    return oss.str();
}

std::vector<vertex *> player::getSettlements()
{
    return settlements_;
}
void player::placeCity(board &gameBoard, int vertexId)
{
    if(isMyTurn_==false)
    {
        std::cout << "It is not your turn" << std::endl;
        return;
    }
    if (gameBoard.getVertex(vertexId).getVertexOwner() != this)
    {
        throw std::invalid_argument("You can only place a city on a settlement that you own.");
    }
    if (playerResources_[resourceTypes::wheat] < 2 || playerResources_[resourceTypes::stone] < 3)
    {
        throw std::invalid_argument("You do not have enough resources to place a city.");
    }
    if (NumOfCities_ >= 4)
    {
        throw std::invalid_argument("You can only place 4 cities.");
    }
    playerResources_[resourceTypes::wheat] -= 2;
    playerResources_[resourceTypes::stone] -= 3;
    victoryPoints_++;
    GAME_IS_OVER();
    gameBoard.getVertex(vertexId).setAvaliable(2);
    NumOfCities_++;
    NumOfSettlements_--;
    std::cout << "Player " << name_ << " placed a city on vertex " << vertexId << std::endl;
}
bool player::hasDevelopmentCard(DevelopmentCard cardType) const
{
    auto it = developmentCards_.find(cardType);
    return it != developmentCards_.end() && it->second > 0;
}
void player::useDevelopmentCardMonopol(resourceTypes resource)
{
    if (!hasDevelopmentCard(DevelopmentCard::Monopol))
    {
        throw std::invalid_argument("You do not have a Monopol card.");
    }
    int sum = 0;
    for (player *p : players_)
    {
        if (p->getName() == name_)
        {
            continue;
        }

        if (p->playerResources_[resource] > 0)
        {
            sum += p->playerResources_[resource]; // Accumulate the resources first
            playerResources_[resource] += p->playerResources_[resource];
            p->playerResources_[resource] = 0;
        }
    }
    developmentCards_[DevelopmentCard::Monopol]--;
    std::cout << "Player " << name_ << " used a Monopol card and got " << sum << " cards of the resource " << resource << std::endl;
    endTurn();
    return;
}
void player::useDevelopmentCardRoadBuilding(board &gameBoard, int edgeId1, int edgeId2)
{
    if (!hasDevelopmentCard(DevelopmentCard::BuildingRoads))
    {
        throw std::invalid_argument("You do not have a Building Roads card.");
    }
    if (NumOfRoads_ >= 14)
    {
        throw std::invalid_argument("You do not have enough roads to use this card.");
    }
    if (!canPlaceRoad(gameBoard, edgeId1) && !canPlaceRoad(gameBoard, edgeId2))
    {
        throw std::invalid_argument("You can only place a road on an edge that is connected to one of your settlements.");
    }
    playerResources_[resourceTypes::wood] += 2;
    playerResources_[resourceTypes::clay] += 2;
    placeRoad(gameBoard, edgeId1);
    placeRoad(gameBoard, edgeId2);
    developmentCards_[DevelopmentCard::BuildingRoads]--;
    std::cout << "Player " << name_ << " used a Building Roads card." << std::endl;
    endTurn();
    
}
void player::useDevelopmentCardYearOfPlenty(resourceTypes resource1, resourceTypes resource2)
{
    if (!hasDevelopmentCard(DevelopmentCard::YearOfPlenty))
    {
        throw std::invalid_argument("You do not have a Year Of Plenty card.");
    }
    playerResources_[resource1]++;
    playerResources_[resource2]++;
    developmentCards_[DevelopmentCard::YearOfPlenty]--;
    std::cout << "Player " << name_ << " used a Year Of Plenty card and recieved 1 " << resource1 << " card and 1 " << resource2 << " card." << std::endl;
    endTurn();

}
void player::useDevelopmentCardVictoryPoint()
{
    if (!hasDevelopmentCard(DevelopmentCard::VictoryPoint))
    {
        throw std::invalid_argument("You do not have a Victory Point Development card.");
    }
    victoryPoints_++;
    GAME_IS_OVER();
    developmentCards_[DevelopmentCard::VictoryPoint]--;
    std::cout << "Player " << name_ << " used a Victory Point card." << std::endl;
    endTurn();
}

void player::updateLargestArmy()
{
    if (NumOfKnights_ >= 3)
    {
        if (playerWithLargestArmy_ == nullptr || NumOfKnights_ > playerWithLargestArmy_->NumOfKnights_)
        {
            if (playerWithLargestArmy_ != nullptr)
            {
                playerWithLargestArmy_->victoryPoints_ -= 2;
            }
            playerWithLargestArmy_ = this;
            victoryPoints_ += 2;
            std:: cout << "Player " << name_ << " has the largest army with " << NumOfKnights_ << " knights and got 2 victory points" << std::endl; 

        }
    }
}

void player::printPoints()
{
    std::cout << "Player " << name_ << " has " << victoryPoints_ << " victory points." << std::endl;
}

std::string player::resourceToString(resourceTypes resource)
{
    switch (resource)
    {
    case resourceTypes::wood:
        return "wood";
    case resourceTypes::stone:
        return "stone";
    case resourceTypes::clay:
        return "clay";
    case resourceTypes::sheep:
        return "sheep";
    case resourceTypes::wheat:
        return "wheat";
    case resourceTypes::desert:
        return "desert";
    case resourceTypes::sea:
        return "sea";

    default:
        return "unknown";
    }
}
void player::replaceResource(resourceTypes resourceThePlayerWants, resourceTypes resourceThePlayerGives, player &playerThePlayerReplaceWith)
{
    if(isMyTurn_==false)
    {
        std::cout << "It is not your turn" << std::endl;
        return;
    }
    if (playerThePlayerReplaceWith.playerResources_[resourceThePlayerWants] == 0)
    {
        throw std::invalid_argument("the player you want to trade with does not have the resource you want.");
    }
    if (playerResources_[resourceThePlayerGives] == 0)
    {
        throw std::invalid_argument("You do not have the resource you want to trade.");
    }
    playerResources_[resourceThePlayerWants]++;
    playerResources_[resourceThePlayerGives]--;
    playerThePlayerReplaceWith.playerResources_[resourceThePlayerGives]++;
    playerThePlayerReplaceWith.playerResources_[resourceThePlayerWants]--;
    std::cout << "Player " << name_ << " traded 1 " << resourceThePlayerGives << " for 1 " << resourceThePlayerWants << " with player " << playerThePlayerReplaceWith.getName() << std::endl;
}
void player::printResources()
{
    std::cout << "Player " << name_ << " has the following resources:\n";
    for (const auto &resource : playerResources_)
    {
        std::cout << resource.first << ": " << resource.second << "\n";
    }
    std::cout << std::endl;
}
DevelopmentCard player::buyDevelopmentCard(catan& game)
{
    if(isMyTurn_==false)
    {
        throw std::invalid_argument("It is not your turn");
    }
    if (playerResources_[resourceTypes::wheat] == 0 || playerResources_[resourceTypes::sheep] == 0 || playerResources_[resourceTypes::stone] == 0)
    {
        throw std::invalid_argument("You do not have enough resources to buy a development card.");
    }
    playerResources_[resourceTypes::wheat]--;
    playerResources_[resourceTypes::sheep]--;
    playerResources_[resourceTypes::stone]--;
     std::vector<DevelopmentCard>& developmentDeck = game.getDevelopmentDeck(); // Access catan's developmentDeck_
    
    if (developmentDeck.empty()) {
        throw std::out_of_range("No more development cards available");
    }

    DevelopmentCard drawnCard = developmentDeck.back();
    developmentDeck.pop_back(); // Assuming you have developmentDeck_ as member in player

    developmentCards_[drawnCard]++;

    // Perform specific actions based on the drawn card
    switch (drawnCard) {
        case DevelopmentCard::Monopol:
            std::cout << "Player "<< this->name_<<" drew a Monopoly card." << std::endl;
            break;
        case DevelopmentCard::YearOfPlenty:
            std::cout << "Player "<< this->name_<<" drew a Year of Plenty card." << std::endl;
            break;
        case DevelopmentCard::BuildingRoads:
            std::cout << "Player "<< this->name_<<" drew a Road Building card." << std::endl;
            break;
        case DevelopmentCard::Knight:
            std::cout << "Player "<< this->name_<<" drew a Knight card." << std::endl;
            NumOfKnights_++;
            updateLargestArmy();
            break;
        case DevelopmentCard::VictoryPoint:
            std::cout << "Player "<< this->name_<<" drew a Victory Point card." << std::endl;
            victoryPoints_++;
            GAME_IS_OVER();
            break;
        default:
            // Handle unexpected cards
            std::cout << "You drew an unknown development card." << std::endl;
            break;
    }

    return drawnCard;
    // drawDevelopmentCard(game);
    
    // std::cout << "Player " << name_ << " bought a development card." << std::endl;

}
void player::GAME_IS_OVER()
    {
        for(player* player : players_)
        {
            if(player->getVictoryPoints()>=10&&player->isMyTurn_==true)
            {
                std::cout<<player->getName()<<" is the winner!"<<std::endl;
            }
        }
    }

bool player:: getIsMyTurn(catan& game){
    return game.getCurrentPlayer()->isMyTurn_;

}
void player::setIsMyTurn(bool isMyTurn)
{
    isMyTurn_ = isMyTurn;
}
void player:: endTurn()
{
    isMyTurn_ = false;
    std::cout << "Player " << name_ << " ended his/her turn." << std::endl;
    if( this->getPlayerIndex() == 2)
    {
        players_[0]->setIsMyTurn(true);
    }
    else
    {
        players_[this->getPlayerIndex()+1]->setIsMyTurn(true);
    }
    std::cout << "Player " << players_[this->getPlayerIndex()]->getName() << " it is your turn." << std::endl;
}
int player:: getPlayerIndex(){
    for(int i = 0; i < 3; i++)
    {
        if(players_[i]->getName() == this->name_)
        {
            return i;
        }
    }
    return -1;
}
void player::setResources(int wood, int clay, int sheep, int wheat, int stone)
{
    playerResources_[resourceTypes::wood] = wood;
    playerResources_[resourceTypes::clay] = clay;
    playerResources_[resourceTypes::sheep] = sheep;
    playerResources_[resourceTypes::wheat] = wheat;
    playerResources_[resourceTypes::stone] = stone;
}
int player::getResourceAmount(resourceTypes resource) const {
    return playerResources_.at(resource);
}
void player::addResource(resourceTypes resource, int amount)
{
    playerResources_[resource] += amount;
}
// std::vector<player*> player::players_;
player *player::playerWithLargestArmy_ = nullptr;
