#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>

// Define your enum class or enum
enum class resourceTypes {
    wood, stone, clay, sheep, wheat, desert, sea 
};

// Overload operator<< for resourceTypes
inline std::ostream& operator<<(std::ostream& os, resourceTypes rt) {
    switch (rt) {
        case resourceTypes::wood:
            os << "wood";
            break;
        case resourceTypes::stone:
            os << "stone";
            break;
        case resourceTypes::clay:
            os << "clay";
            break;
        case resourceTypes::sheep:
            os << "sheep";
            break;
        case resourceTypes::wheat:
            os << "wheat";
            break;
        case resourceTypes::desert:
            break;
        case resourceTypes::sea:
            break;
            
        // default:
        //     os << "Unknown";
            // break;
    }
    return os;
}

#endif // ENUMS_HPP
