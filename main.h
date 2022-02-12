//
// Created by maxim on 12.02.2022.
//

#ifndef PY_CHESS_MAIN_H
#define PY_CHESS_MAIN_H
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <utility>
#include <ctime>
#include <chrono>

using namespace std;
enum piece_types{none, pawn, knight, bishop, rook, queen, king};
struct move{int starting_square, destination_square, promotion_type;};
#endif //PY_CHESS_MAIN_H
