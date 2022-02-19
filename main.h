//
// Created by maxim on 12.02.2022.
//

#ifndef PY_CHESS_MAIN_H
#define PY_CHESS_MAIN_H

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <string>
#include <utility>
#include <ctime>
#include <chrono>

using namespace std;
enum piece_types {
    none, pawn, knight, bishop, rook, queen, king
};
enum game_ends {
    not_over, black_win, white_win, stalemate, threefold, fifty_move_rule, insufficient_material
};
struct stored_move {
    int previews_square, new_square;
    piece_types piece, taken_piece;
    int piece_taken_at;
    int en_passant_square;
    bool castling_rights[4]; // from before move
    int previews_rook_square, new_rook_square
};
struct stored_position {
public:
    double position;
    int en_passant_square;
    int castles;
    bool operator==(const stored_position & other) const {
        return position == other.position && en_passant_square == other.en_passant_square && castles == other.castles;
    }
};
#endif //PY_CHESS_MAIN_H
