#include "board.hpp"
#include "vertex.hpp"
#include "edge.hpp"

board::board(){
    make();

}

void board::make(){

     // Resize the vectors first
    vertexes_.resize(54);
    edges_.resize(72);
    hexagons_.resize(19);

    
    // Initialize vertices with their respective ids and connections
    vertexes_[0] = vertex(0, {resourceTypes::stone}, 0, {&vertexes_[1], &vertexes_[8]});
    vertexes_[1] = vertex(1, {resourceTypes::stone}, 0, {&vertexes_[0], &vertexes_[2]});
    vertexes_[2] = vertex(2, {resourceTypes::stone, resourceTypes::sheep}, 0, {&vertexes_[1], &vertexes_[3], &vertexes_[10]});
    vertexes_[3] = vertex(3, {resourceTypes::sheep}, 0, {&vertexes_[2], &vertexes_[4]});
    vertexes_[4] = vertex(4, {resourceTypes::sheep, resourceTypes::wood}, 0, {&vertexes_[3], &vertexes_[5], &vertexes_[12]});
    vertexes_[5] = vertex(5, {resourceTypes::wood}, 0, {&vertexes_[4], &vertexes_[6]});
    vertexes_[6] = vertex(6, {resourceTypes::wood}, 0, {&vertexes_[5], &vertexes_[14]});
    vertexes_[7] = vertex(7, {resourceTypes::wheat}, 0, {&vertexes_[8], &vertexes_[17]});
    vertexes_[8] = vertex(8, {resourceTypes::stone, resourceTypes::wheat}, 0, {&vertexes_[0], &vertexes_[7], &vertexes_[9]});
    vertexes_[9] = vertex(9, {resourceTypes::stone, resourceTypes::wheat, resourceTypes::clay}, 0, {&vertexes_[8], &vertexes_[10], &vertexes_[19]});
    vertexes_[10] = vertex(10, {resourceTypes::stone, resourceTypes::sheep, resourceTypes::clay}, 0, {&vertexes_[2], &vertexes_[9], &vertexes_[11]});
    vertexes_[11] = vertex(11, {resourceTypes::sheep, resourceTypes::clay}, 0, {&vertexes_[10], &vertexes_[12], &vertexes_[21]});
    vertexes_[12] = vertex(12, {resourceTypes::wood, resourceTypes::sheep}, 0, {&vertexes_[4], &vertexes_[11], &vertexes_[13]});
    vertexes_[13] = vertex(13, {resourceTypes::wood, resourceTypes::sheep, resourceTypes::clay}, 0, {&vertexes_[12], &vertexes_[14], &vertexes_[23]});
    vertexes_[14] = vertex(14, {resourceTypes::wood, resourceTypes::clay}, 0, {&vertexes_[6], &vertexes_[13], &vertexes_[15]});
    vertexes_[15] = vertex(15, {resourceTypes::clay}, 0, {&vertexes_[14], &vertexes_[25]});
    vertexes_[16] = vertex(16, {resourceTypes::wheat}, 0, {&vertexes_[17], &vertexes_[27]});
    vertexes_[17] = vertex(17, {resourceTypes::wheat}, 0, {&vertexes_[7], &vertexes_[16], &vertexes_[18]});
    vertexes_[18] = vertex(18, {resourceTypes::wood, resourceTypes::wheat}, 0, {&vertexes_[17], &vertexes_[19], &vertexes_[29]});
    vertexes_[19] = vertex(19, {resourceTypes::wheat, resourceTypes::wood, resourceTypes::clay}, 0, {&vertexes_[9], &vertexes_[18], &vertexes_[20]});
    vertexes_[20] = vertex(20, {resourceTypes::wood, resourceTypes::desert, resourceTypes::clay}, 0, {&vertexes_[19], &vertexes_[21], &vertexes_[31]});
    vertexes_[21] = vertex(21, {resourceTypes::desert, resourceTypes::sheep, resourceTypes::clay}, 0, {&vertexes_[11], &vertexes_[20], &vertexes_[22]});
    vertexes_[22] = vertex(22, {resourceTypes::desert, resourceTypes::sheep, resourceTypes::wood}, 0, {&vertexes_[21], &vertexes_[23], &vertexes_[33]});
    vertexes_[23] = vertex(23, {resourceTypes::wood, resourceTypes::sheep, resourceTypes::clay}, 0, {&vertexes_[13], &vertexes_[22], &vertexes_[24]});
    vertexes_[24] = vertex(24, {resourceTypes::wood, resourceTypes::stone, resourceTypes::clay}, 0, {&vertexes_[23], &vertexes_[25], &vertexes_[35]});
    vertexes_[25] = vertex(25, {resourceTypes::stone, resourceTypes::clay}, 0, {&vertexes_[15], &vertexes_[24], &vertexes_[26]});
    vertexes_[26] = vertex(26, {resourceTypes::stone, resourceTypes::sea}, 0, {&vertexes_[25], &vertexes_[37]});
    vertexes_[27] = vertex(27, {resourceTypes::wheat, resourceTypes::sea}, 0, {&vertexes_[16], &vertexes_[28]});
    vertexes_[28] = vertex(28, {resourceTypes::sea, resourceTypes::wood, resourceTypes::wheat}, 0, {&vertexes_[27], &vertexes_[29], &vertexes_[38]});
    vertexes_[29] = vertex(29, {resourceTypes::wood, resourceTypes::wheat}, 0, {&vertexes_[18], &vertexes_[28], &vertexes_[30]});
    vertexes_[30] = vertex(30, {resourceTypes::wood, resourceTypes::stone}, 0, {&vertexes_[29], &vertexes_[31], &vertexes_[40]});
    vertexes_[31] = vertex(31, {resourceTypes::wood, resourceTypes::stone}, 0, {&vertexes_[20], &vertexes_[30], &vertexes_[32]});
    vertexes_[32] = vertex(32, {resourceTypes::wheat, resourceTypes::stone}, 0, {&vertexes_[31], &vertexes_[33], &vertexes_[42]});
    vertexes_[33] = vertex(33, {resourceTypes::wood, resourceTypes::wheat}, 0, {&vertexes_[22], &vertexes_[32], &vertexes_[34]});   
    vertexes_[34] = vertex(34, {resourceTypes::wood, resourceTypes::sheep, resourceTypes::stone}, 0, {&vertexes_[33], &vertexes_[35], &vertexes_[44]});
    vertexes_[35] = vertex(35, {resourceTypes::wood, resourceTypes::sheep, resourceTypes::stone}, 0, {&vertexes_[24], &vertexes_[34], &vertexes_[36]});
    vertexes_[36] = vertex(36, {resourceTypes::stone, resourceTypes::sheep, resourceTypes::sea}, 0, {&vertexes_[35], &vertexes_[46], &vertexes_[37]});
    vertexes_[37] = vertex(37, {resourceTypes::stone, resourceTypes::sea}, 0, {&vertexes_[26], &vertexes_[36], &vertexes_[38]});
    vertexes_[38] = vertex(38, {resourceTypes::wood, resourceTypes::sea}, 0, {&vertexes_[28], &vertexes_[39], &vertexes_[47]});
    vertexes_[39] = vertex(39, {resourceTypes::wood, resourceTypes::sea, resourceTypes::clay}, 0, {&vertexes_[38], &vertexes_[40], &vertexes_[47]});
    vertexes_[40] = vertex(40, {resourceTypes::wood, resourceTypes::stone, resourceTypes::clay}, 0, {&vertexes_[30], &vertexes_[39], &vertexes_[41]});
    vertexes_[41] = vertex(41, {resourceTypes::stone, resourceTypes::wheat, resourceTypes::clay}, 0, {&vertexes_[40], &vertexes_[42], &vertexes_[49]});
    vertexes_[42] = vertex(42, {resourceTypes::wheat, resourceTypes::stone}, 0, {&vertexes_[32], &vertexes_[41], &vertexes_[43]});
    vertexes_[43] = vertex(43, {resourceTypes::wheat, resourceTypes::sheep}, 0, {&vertexes_[42], &vertexes_[44], &vertexes_[51]});
    vertexes_[44] = vertex(44, {resourceTypes::wheat, resourceTypes::sheep}, 0, {&vertexes_[34], &vertexes_[43], &vertexes_[45]});
    vertexes_[45] = vertex(45, {resourceTypes::sea, resourceTypes::sheep}, 0, {&vertexes_[44], &vertexes_[46], &vertexes_[53]});
    vertexes_[46] = vertex(46, {resourceTypes::sea, resourceTypes::sheep}, 0, {&vertexes_[36], &vertexes_[45], &vertexes_[52]});
    vertexes_[47] = vertex(47, {resourceTypes::sea, resourceTypes::clay}, 0, {&vertexes_[38], &vertexes_[48], &vertexes_[39]});
    vertexes_[48] = vertex(48, {resourceTypes::sea, resourceTypes::clay}, 0, {&vertexes_[47], &vertexes_[49], &vertexes_[50]});
    vertexes_[49] = vertex(49, {resourceTypes::sea, resourceTypes::wheat, resourceTypes::clay}, 0, {&vertexes_[48], &vertexes_[50], &vertexes_[41]});
    vertexes_[50] = vertex(50, {resourceTypes::wheat, resourceTypes::sea}, 0, {&vertexes_[49], &vertexes_[51], &vertexes_[48]});
    vertexes_[51] = vertex(51, {resourceTypes::wheat, resourceTypes::sheep, resourceTypes::sea}, 0, {&vertexes_[43], &vertexes_[50], &vertexes_[52]});
    vertexes_[52] = vertex(52, {resourceTypes::sea, resourceTypes::sheep}, 0, {&vertexes_[51], &vertexes_[53], &vertexes_[46]});
    vertexes_[53] = vertex(53, {resourceTypes::sea, resourceTypes::sheep}, 0, {&vertexes_[45], &vertexes_[52], &vertexes_[46]});

    
    edges_[0]=edge(0,nullptr,{vertexes_[0], vertexes_[1]});
    edges_[1]=edge(1,nullptr,{vertexes_[1], vertexes_[2]});
    edges_[2]=edge(2,nullptr,{vertexes_[2], vertexes_[3]});
    edges_[3]=edge(3,nullptr,{vertexes_[3], vertexes_[4]});
    edges_[4]=edge(4,nullptr,{vertexes_[4], vertexes_[5]});
    edges_[5]=edge(5,nullptr,{vertexes_[5], vertexes_[6]});
    edges_[6]=edge(6,nullptr,{vertexes_[0], vertexes_[8]});
    edges_[7]=edge(7,nullptr,{vertexes_[2], vertexes_[10]});
    edges_[8]=edge(8,nullptr,{vertexes_[4], vertexes_[12]});
    edges_[9]=edge(9,nullptr,{vertexes_[6], vertexes_[14]});
    edges_[10]=edge(10,nullptr,{vertexes_[7], vertexes_[8]});
    edges_[11]=edge(11,nullptr,{vertexes_[8], vertexes_[9]});
    edges_[12]=edge(12,nullptr,{vertexes_[9], vertexes_[10]});
    edges_[13]=edge(13,nullptr,{vertexes_[10], vertexes_[11]});
    edges_[14]=edge(14,nullptr,{vertexes_[11], vertexes_[12]});
    edges_[15]=edge(15,nullptr,{vertexes_[12], vertexes_[13]});
    edges_[16]=edge(16,nullptr,{vertexes_[13], vertexes_[14]});
    edges_[17]=edge(17,nullptr,{vertexes_[14], vertexes_[15]});
    edges_[18]=edge(18,nullptr,{vertexes_[7], vertexes_[17]});
    edges_[19]=edge(19,nullptr,{vertexes_[9], vertexes_[19]});
    edges_[20]=edge(20,nullptr,{vertexes_[11], vertexes_[21]});
    edges_[21]=edge(21,nullptr,{vertexes_[13], vertexes_[23]});
    edges_[22]=edge(22,nullptr,{vertexes_[15], vertexes_[25]});
    edges_[23]=edge(23,nullptr,{vertexes_[16], vertexes_[17]});
    edges_[24]=edge(24,nullptr,{vertexes_[17], vertexes_[18]});
    edges_[25]=edge(25,nullptr,{vertexes_[18], vertexes_[19]});
    edges_[26]=edge(26,nullptr,{vertexes_[19], vertexes_[20]});
    edges_[27]=edge(27,nullptr,{vertexes_[20], vertexes_[21]});
    edges_[28]=edge(28,nullptr,{vertexes_[21], vertexes_[22]});
    edges_[29]=edge(29,nullptr,{vertexes_[22], vertexes_[23]});
    edges_[30]=edge(30,nullptr,{vertexes_[23], vertexes_[24]});
    edges_[31]=edge(31,nullptr,{vertexes_[24], vertexes_[25]});
    edges_[32]=edge(32,nullptr,{vertexes_[25], vertexes_[26]});
    edges_[33]=edge(33,nullptr,{vertexes_[16], vertexes_[27]});
    edges_[34]=edge(34,nullptr,{vertexes_[18], vertexes_[29]});
    edges_[35]=edge(35,nullptr,{vertexes_[20], vertexes_[31]});
    edges_[36]=edge(36,nullptr,{vertexes_[22], vertexes_[33]});
    edges_[37]=edge(37,nullptr,{vertexes_[24], vertexes_[35]});
    edges_[38]=edge(38,nullptr,{vertexes_[26], vertexes_[37]});
    edges_[39]=edge(39,nullptr,{vertexes_[27], vertexes_[28]});
    edges_[40]=edge(40,nullptr,{vertexes_[28], vertexes_[29]});
    edges_[41]=edge(41,nullptr,{vertexes_[29], vertexes_[30]});
    edges_[42]=edge(42,nullptr,{vertexes_[30], vertexes_[31]});
    edges_[43]=edge(43,nullptr,{vertexes_[31], vertexes_[32]});
    edges_[44]=edge(44,nullptr,{vertexes_[32], vertexes_[33]});
    edges_[45]=edge(45,nullptr,{vertexes_[33], vertexes_[34]});
    edges_[46]=edge(46,nullptr,{vertexes_[34], vertexes_[35]});
    edges_[47]=edge(47,nullptr,{vertexes_[35], vertexes_[36]});
    edges_[48]=edge(48,nullptr,{vertexes_[36], vertexes_[37]});
    edges_[49]=edge(49,nullptr,{vertexes_[28], vertexes_[38]});
    edges_[50]=edge(50,nullptr,{vertexes_[30], vertexes_[40]});
    edges_[51]=edge(51,nullptr,{vertexes_[32], vertexes_[42]});
    edges_[52]=edge(52,nullptr,{vertexes_[34], vertexes_[44]});
    edges_[53]=edge(53,nullptr,{vertexes_[36], vertexes_[46]});
    edges_[54]=edge(54,nullptr,{vertexes_[38], vertexes_[39]});
    edges_[55]=edge(55,nullptr,{vertexes_[39], vertexes_[40]});
    edges_[56]=edge(56,nullptr,{vertexes_[40], vertexes_[41]});
    edges_[57]=edge(57,nullptr,{vertexes_[41], vertexes_[42]});
    edges_[58]=edge(58,nullptr,{vertexes_[42], vertexes_[43]});
    edges_[59]=edge(59,nullptr,{vertexes_[43], vertexes_[44]});
    edges_[60]=edge(60,nullptr,{vertexes_[44], vertexes_[45]});
    edges_[61]=edge(61,nullptr,{vertexes_[45], vertexes_[46]});
    edges_[62]=edge(62,nullptr,{vertexes_[39], vertexes_[47]});
    edges_[63]=edge(63,nullptr,{vertexes_[41], vertexes_[49]});
    edges_[64]=edge(64,nullptr,{vertexes_[43], vertexes_[51]});
    edges_[65]=edge(65,nullptr,{vertexes_[45], vertexes_[53]});
    edges_[66]=edge(66,nullptr,{vertexes_[47], vertexes_[48]});
    edges_[67]=edge(67,nullptr,{vertexes_[48], vertexes_[49]});
    edges_[68]=edge(68,nullptr,{vertexes_[49], vertexes_[50]});
    edges_[69]=edge(69,nullptr,{vertexes_[50], vertexes_[51]});
    edges_[70]=edge(70,nullptr,{vertexes_[51], vertexes_[52]});
    edges_[71]=edge(71,nullptr,{vertexes_[52], vertexes_[53]});

    
    
    hexagons_[0]=hexagon(0, 10, resourceTypes::stone, {vertexes_[0], vertexes_[1], vertexes_[2], vertexes_[8], vertexes_[9], vertexes_[10]}, {edges_[0], edges_[1], edges_[6], edges_[7], edges_[11], edges_[12]});
    hexagons_[1]=hexagon(1, 2, resourceTypes::sheep, {vertexes_[2], vertexes_[3], vertexes_[4], vertexes_[10], vertexes_[11], vertexes_[12]}, {edges_[2], edges_[3], edges_[7], edges_[8], edges_[13], edges_[14]});
    hexagons_[2]=hexagon(2, 9, resourceTypes::wood, {vertexes_[4], vertexes_[5], vertexes_[6], vertexes_[12], vertexes_[13], vertexes_[14]}, {edges_[4], edges_[5], edges_[8], edges_[9], edges_[15], edges_[16]});
    hexagons_[3]=hexagon(3, 12, resourceTypes::wheat, {vertexes_[7], vertexes_[8], vertexes_[9], vertexes_[17], vertexes_[18], vertexes_[19]}, {edges_[10], edges_[11], edges_[24], edges_[25], edges_[18], edges_[19]});
    hexagons_[4]=hexagon(4, 6, resourceTypes::clay, {vertexes_[9], vertexes_[10], vertexes_[11], vertexes_[19], vertexes_[20], vertexes_[21]}, {edges_[12], edges_[13], edges_[26], edges_[27], edges_[20], edges_[19]});
    hexagons_[5]=hexagon(5, 4, resourceTypes::sheep, {vertexes_[11], vertexes_[12], vertexes_[13], vertexes_[21], vertexes_[22], vertexes_[23]}, {edges_[14], edges_[15], edges_[28], edges_[29], edges_[20], edges_[21]});
    hexagons_[6]=hexagon(6, 10, resourceTypes::clay, {vertexes_[13], vertexes_[14], vertexes_[15], vertexes_[23], vertexes_[24], vertexes_[25]}, {edges_[16], edges_[17], edges_[30], edges_[31], edges_[22], edges_[21]});
    hexagons_[7]=hexagon(7, 9, resourceTypes::wheat, {vertexes_[16], vertexes_[17], vertexes_[18], vertexes_[27], vertexes_[28], vertexes_[29]}, {edges_[23], edges_[24], edges_[39], edges_[40], edges_[33], edges_[34]});
    hexagons_[8]=hexagon(8, 11, resourceTypes::stone, {vertexes_[18], vertexes_[19], vertexes_[20], vertexes_[29], vertexes_[30], vertexes_[31]}, {edges_[25], edges_[26], edges_[41], edges_[42], edges_[35], edges_[34]});
    hexagons_[9]=hexagon(9, 0, resourceTypes::desert, {vertexes_[20], vertexes_[21], vertexes_[22], vertexes_[31], vertexes_[32], vertexes_[33]}, {edges_[27], edges_[28], edges_[43], edges_[44], edges_[36], edges_[35]});
    hexagons_[10]=hexagon(10, 3, resourceTypes::wood, {vertexes_[22], vertexes_[23], vertexes_[24], vertexes_[33], vertexes_[34], vertexes_[35]}, {edges_[29], edges_[30], edges_[45], edges_[46], edges_[37], edges_[36]});
    hexagons_[11]=hexagon(11, 8, resourceTypes::stone, {vertexes_[24], vertexes_[25], vertexes_[26], vertexes_[35], vertexes_[36], vertexes_[37]}, {edges_[31], edges_[32], edges_[47], edges_[48], edges_[38], edges_[37]});
    hexagons_[12]=hexagon(12, 8, resourceTypes::wood, {vertexes_[28], vertexes_[29], vertexes_[30], vertexes_[40], vertexes_[38], vertexes_[39]}, {edges_[40], edges_[41], edges_[54], edges_[55], edges_[49], edges_[50]});
    hexagons_[13]=hexagon(13, 3, resourceTypes::stone, {vertexes_[30], vertexes_[31], vertexes_[32], vertexes_[42], vertexes_[41], vertexes_[40]}, {edges_[42], edges_[43], edges_[56], edges_[57], edges_[51], edges_[50]});
    hexagons_[14]=hexagon(14, 4, resourceTypes::wheat, {vertexes_[32], vertexes_[33], vertexes_[34], vertexes_[44], vertexes_[43], vertexes_[42]}, {edges_[44], edges_[45], edges_[58], edges_[59], edges_[52], edges_[51]});
    hexagons_[15]=hexagon(15, 5, resourceTypes::sheep, {vertexes_[34], vertexes_[35], vertexes_[36], vertexes_[46], vertexes_[45], vertexes_[44]}, {edges_[46], edges_[47], edges_[60], edges_[61], edges_[53], edges_[52]});
    hexagons_[16]=hexagon(16, 5, resourceTypes::clay, {vertexes_[39], vertexes_[40], vertexes_[41], vertexes_[48], vertexes_[47], vertexes_[49]}, {edges_[55], edges_[56], edges_[66], edges_[67], edges_[62], edges_[63]});
    hexagons_[17]=hexagon(17, 6, resourceTypes::wheat, {vertexes_[41], vertexes_[42], vertexes_[43], vertexes_[49], vertexes_[50], vertexes_[51]}, {edges_[57], edges_[58], edges_[68], edges_[69], edges_[64], edges_[63]});
    hexagons_[18]=hexagon(18, 11, resourceTypes::sheep, {vertexes_[43], vertexes_[44], vertexes_[45], vertexes_[51], vertexes_[52], vertexes_[53]}, {edges_[59], edges_[60], edges_[70], edges_[71], edges_[65], edges_[64]});

}

// Method to get a vertex by its ID
vertex& board::getVertex(int vertexId) {
    if (vertexId < 0 || vertexId >= static_cast<int>(vertexes_.size())) {
        throw std::out_of_range("Vertex ID is out of range");
    }
    return vertexes_.at(vertexId);
}




