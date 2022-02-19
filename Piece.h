//
// Created by maxim on 12.02.2022.
//

#ifndef PY_CHESS_PIECE_H
#define PY_CHESS_PIECE_H

#include "main.h"

// type (b,r,q), position, direction
static short int sliding_piece_distances[3][64][8] = {
        {{0, 0, 0, 0, 0, 0, 0, 7}, {0, 0, 0, 0, 0, 1, 0, 6}, {0, 0, 0, 0, 0, 2, 0, 5}, {0, 0, 0, 0, 0, 3, 0, 4}, {0, 0, 0, 0, 0, 4, 0, 3}, {0, 0, 0, 0, 0, 5, 0, 2}, {0, 0, 0, 0, 0, 6, 0, 1}, {0, 0, 0, 0, 0, 7, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 6}, {1, 0, 1, 0, 0, 1, 0, 6}, {1, 0, 1, 0, 0, 2, 0, 5}, {1, 0, 1, 0, 0, 3, 0, 4}, {1, 0, 1, 0, 0, 4, 0, 3}, {1, 0, 1, 0, 0, 5, 0, 2}, {1, 0, 1, 0, 0, 6, 0, 1}, {1, 0, 0, 0, 0, 6, 0, 0},
                {0, 0, 2, 0, 0, 0, 0, 5}, {1, 0, 2, 0, 0, 1, 0, 5}, {2, 0, 2, 0, 0, 2, 0, 5}, {2, 0, 2, 0, 0, 3, 0, 4}, {2, 0, 2, 0, 0, 4, 0, 3}, {2, 0, 2, 0, 0, 5, 0, 2}, {2, 0, 1, 0, 0, 5, 0, 1}, {2, 0, 0, 0, 0, 5, 0, 0},
                {0, 0, 3, 0, 0, 0, 0, 4}, {1, 0, 3, 0, 0, 1, 0, 4}, {2, 0, 3, 0, 0, 2, 0, 4}, {3, 0, 3, 0, 0, 3, 0, 4}, {3, 0, 3, 0, 0, 4, 0, 3}, {3, 0, 2, 0, 0, 4, 0, 2}, {3, 0, 1, 0, 0, 4, 0, 1}, {3, 0, 0, 0, 0, 4, 0, 0},
                {0, 0, 4, 0, 0, 0, 0, 3}, {1, 0, 4, 0, 0, 1, 0, 3}, {2, 0, 4, 0, 0, 2, 0, 3}, {3, 0, 4, 0, 0, 3, 0, 3}, {4, 0, 3, 0, 0, 3, 0, 3}, {4, 0, 2, 0, 0, 3, 0, 2}, {4, 0, 1, 0, 0, 3, 0, 1}, {4, 0, 0, 0, 0, 3, 0, 0},
                {0, 0, 5, 0, 0, 0, 0, 2}, {1, 0, 5, 0, 0, 1, 0, 2}, {2, 0, 5, 0, 0, 2, 0, 2}, {3, 0, 4, 0, 0, 2, 0, 2}, {4, 0, 3, 0, 0, 2, 0, 2}, {5, 0, 2, 0, 0, 2, 0, 2}, {5, 0, 1, 0, 0, 2, 0, 1}, {5, 0, 0, 0, 0, 2, 0, 0},
                {0, 0, 6, 0, 0, 0, 0, 1}, {1, 0, 6, 0, 0, 1, 0, 1}, {2, 0, 5, 0, 0, 1, 0, 1}, {3, 0, 4, 0, 0, 1, 0, 1}, {4, 0, 3, 0, 0, 1, 0, 1}, {5, 0, 2, 0, 0, 1, 0, 1}, {6, 0, 1, 0, 0, 1, 0, 1}, {6, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 7, 0, 0, 0, 0, 0}, {1, 0, 6, 0, 0, 0, 0, 0}, {2, 0, 5, 0, 0, 0, 0, 0}, {3, 0, 4, 0, 0, 0, 0, 0}, {4, 0, 3, 0, 0, 0, 0, 0}, {5, 0, 2, 0, 0, 0, 0, 0}, {6, 0, 1, 0, 0, 0, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0}},

        {{0, 0, 0, 0, 7, 0, 7, 0}, {0, 0, 0, 1, 6, 0, 7, 0}, {0, 0, 0, 2, 5, 0, 7, 0}, {0, 0, 0, 3, 4, 0, 7, 0}, {0, 0, 0, 4, 3, 0, 7, 0}, {0, 0, 0, 5, 2, 0, 7, 0}, {0, 0, 0, 6, 1, 0, 7, 0}, {0, 0, 0, 7, 0, 0, 7, 0},
                {0, 1, 0, 0, 7, 0, 6, 0}, {0, 1, 0, 1, 6, 0, 6, 0}, {0, 1, 0, 2, 5, 0, 6, 0}, {0, 1, 0, 3, 4, 0, 6, 0}, {0, 1, 0, 4, 3, 0, 6, 0}, {0, 1, 0, 5, 2, 0, 6, 0}, {0, 1, 0, 6, 1, 0, 6, 0}, {0, 1, 0, 7, 0, 0, 6, 0},
                {0, 2, 0, 0, 7, 0, 5, 0}, {0, 2, 0, 1, 6, 0, 5, 0}, {0, 2, 0, 2, 5, 0, 5, 0}, {0, 2, 0, 3, 4, 0, 5, 0}, {0, 2, 0, 4, 3, 0, 5, 0}, {0, 2, 0, 5, 2, 0, 5, 0}, {0, 2, 0, 6, 1, 0, 5, 0}, {0, 2, 0, 7, 0, 0, 5, 0},
                {0, 3, 0, 0, 7, 0, 4, 0}, {0, 3, 0, 1, 6, 0, 4, 0}, {0, 3, 0, 2, 5, 0, 4, 0}, {0, 3, 0, 3, 4, 0, 4, 0}, {0, 3, 0, 4, 3, 0, 4, 0}, {0, 3, 0, 5, 2, 0, 4, 0}, {0, 3, 0, 6, 1, 0, 4, 0}, {0, 3, 0, 7, 0, 0, 4, 0},
                {0, 4, 0, 0, 7, 0, 3, 0}, {0, 4, 0, 1, 6, 0, 3, 0}, {0, 4, 0, 2, 5, 0, 3, 0}, {0, 4, 0, 3, 4, 0, 3, 0}, {0, 4, 0, 4, 3, 0, 3, 0}, {0, 4, 0, 5, 2, 0, 3, 0}, {0, 4, 0, 6, 1, 0, 3, 0}, {0, 4, 0, 7, 0, 0, 3, 0},
                {0, 5, 0, 0, 7, 0, 2, 0}, {0, 5, 0, 1, 6, 0, 2, 0}, {0, 5, 0, 2, 5, 0, 2, 0}, {0, 5, 0, 3, 4, 0, 2, 0}, {0, 5, 0, 4, 3, 0, 2, 0}, {0, 5, 0, 5, 2, 0, 2, 0}, {0, 5, 0, 6, 1, 0, 2, 0}, {0, 5, 0, 7, 0, 0, 2, 0},
                {0, 6, 0, 0, 7, 0, 1, 0}, {0, 6, 0, 1, 6, 0, 1, 0}, {0, 6, 0, 2, 5, 0, 1, 0}, {0, 6, 0, 3, 4, 0, 1, 0}, {0, 6, 0, 4, 3, 0, 1, 0}, {0, 6, 0, 5, 2, 0, 1, 0}, {0, 6, 0, 6, 1, 0, 1, 0}, {0, 6, 0, 7, 0, 0, 1, 0},
                {0, 7, 0, 0, 7, 0, 0, 0}, {0, 7, 0, 1, 6, 0, 0, 0}, {0, 7, 0, 2, 5, 0, 0, 0}, {0, 7, 0, 3, 4, 0, 0, 0}, {0, 7, 0, 4, 3, 0, 0, 0}, {0, 7, 0, 5, 2, 0, 0, 0}, {0, 7, 0, 6, 1, 0, 0, 0}, {0, 7, 0, 7, 0, 0, 0, 0}},

        {{0, 0, 0, 0, 7, 0, 7, 7}, {0, 0, 0, 1, 6, 1, 7, 6}, {0, 0, 0, 2, 5, 2, 7, 5}, {0, 0, 0, 3, 4, 3, 7, 4}, {0, 0, 0, 4, 3, 4, 7, 3}, {0, 0, 0, 5, 2, 5, 7, 2}, {0, 0, 0, 6, 1, 6, 7, 1}, {0, 0, 0, 7, 0, 7, 7, 0},
                {0, 1, 1, 0, 7, 0, 6, 6}, {1, 1, 1, 1, 6, 1, 6, 6}, {1, 1, 1, 2, 5, 2, 6, 5}, {1, 1, 1, 3, 4, 3, 6, 4}, {1, 1, 1, 4, 3, 4, 6, 3}, {1, 1, 1, 5, 2, 5, 6, 2}, {1, 1, 1, 6, 1, 6, 6, 1}, {1, 1, 0, 7, 0, 6, 6, 0},
                {0, 2, 2, 0, 7, 0, 5, 5}, {1, 2, 2, 1, 6, 1, 5, 5}, {2, 2, 2, 2, 5, 2, 5, 5}, {2, 2, 2, 3, 4, 3, 5, 4}, {2, 2, 2, 4, 3, 4, 5, 3}, {2, 2, 2, 5, 2, 5, 5, 2}, {2, 2, 1, 6, 1, 5, 5, 1}, {2, 2, 0, 7, 0, 5, 5, 0},
                {0, 3, 3, 0, 7, 0, 4, 4}, {1, 3, 3, 1, 6, 1, 4, 4}, {2, 3, 3, 2, 5, 2, 4, 4}, {3, 3, 3, 3, 4, 3, 4, 4}, {3, 3, 3, 4, 3, 4, 4, 3}, {3, 3, 2, 5, 2, 4, 4, 2}, {3, 3, 1, 6, 1, 4, 4, 1}, {3, 3, 0, 7, 0, 4, 4, 0},
                {0, 4, 4, 0, 7, 0, 3, 3}, {1, 4, 4, 1, 6, 1, 3, 3}, {2, 4, 4, 2, 5, 2, 3, 3}, {3, 4, 4, 3, 4, 3, 3, 3}, {4, 4, 3, 4, 3, 3, 3, 3}, {4, 4, 2, 5, 2, 3, 3, 2}, {4, 4, 1, 6, 1, 3, 3, 1}, {4, 4, 0, 7, 0, 3, 3, 0},
                {0, 5, 5, 0, 7, 0, 2, 2}, {1, 5, 5, 1, 6, 1, 2, 2}, {2, 5, 5, 2, 5, 2, 2, 2}, {3, 5, 4, 3, 4, 2, 2, 2}, {4, 5, 3, 4, 3, 2, 2, 2}, {5, 5, 2, 5, 2, 2, 2, 2}, {5, 5, 1, 6, 1, 2, 2, 1}, {5, 5, 0, 7, 0, 2, 2, 0},
                {0, 6, 6, 0, 7, 0, 1, 1}, {1, 6, 6, 1, 6, 1, 1, 1}, {2, 6, 5, 2, 5, 1, 1, 1}, {3, 6, 4, 3, 4, 1, 1, 1}, {4, 6, 3, 4, 3, 1, 1, 1}, {5, 6, 2, 5, 2, 1, 1, 1}, {6, 6, 1, 6, 1, 1, 1, 1}, {6, 6, 0, 7, 0, 1, 1, 0},
                {0, 7, 7, 0, 7, 0, 0, 0}, {1, 7, 6, 1, 6, 0, 0, 0}, {2, 7, 5, 2, 5, 0, 0, 0}, {3, 7, 4, 3, 4, 0, 0, 0}, {4, 7, 3, 4, 3, 0, 0, 0}, {5, 7, 2, 5, 2, 0, 0, 0}, {6, 7, 1, 6, 1, 0, 0, 0}, {7, 7, 0, 7, 0, 0, 0, 0}}};


class Piece {
public:
    Piece(bool piece_color, int piece_type);

    Piece(bool piece_color, piece_types piece_type);

    Piece() {
        color = false;
        type = none;
    }

    [[nodiscard]] bool get_color() const { return color; };

    piece_types get_type() { return type; };

    [[nodiscard]] int get_amount_moves() const { return amount_moves; }

    void set_moves(const int *new_moves, int amount);

    void set_amount_moves(int amount) { amount_moves = amount; }

    void set_moves(int &position, int value) { moves[position] = value; }

    void add_move(int value) {
        moves[amount_moves] = value;
        amount_moves++;
    }

private:
    int moves[27]{0};
    int amount_moves = 0;
    bool color;
    piece_types type;
};

int convert_piece(char);

#endif //PY_CHESS_PIECE_H
