// // #pragma once

// // #include <vector>
// // #include "player.hpp" // Include the player header file
// // #include "board.hpp"  // Include the board header file

// // class catan {
// // private:
// //     std::vector<player*> players_;
// //     player* currentPlayer_;
// //     board* gameBoard_;

// // public:
// //     // catan(std::vector<player*> players = {}, player* currentPlayer = nullptr, board* gameBoard = nullptr);
// //     catan(player p1, player p2, player p3);
// //     ~catan();
// //     board getBoard();
// // };
// #pragma once

// #include <vector>
// #include "player.hpp"
// #include "board.hpp"

// class catan {
// private:
//     // player p1;
//     // player p2;
//     // player p3;
//     std::vector<player*> players_;
//     player* currentPlayer_;
//     board* gameBoard_;

// public:
//     // catan(player p1, player p2, player p3);
//     catan(player p1, player p2, player p3);
//     ~catan();
//     board& getBoard();
//     void ChooseStartingPlayer();
// };
#pragma once

#include <vector>
#include "player.hpp"
#include "board.hpp"

class catan {
private:
    std::vector<player*> players_;
    player* currentPlayer_;
    board* gameBoard_;
    

public:
    catan(player& p1, player& p2, player& p3);
    ~catan();
    board& getBoard();
    void ChooseStartingPlayer();
    // void catan::rollDiceAndDistributeResources(player& currentPlayer);
    void rollDiceAndDistributeResources(player& currentPlayer);
};

