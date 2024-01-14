#pragma once

#include <memory>
#include <vector>
#include "surakarta_piece.h"

#define BOARD_SIZE 6

class SurakartRow : public std::vector<std::shared_ptr<SurakartaPiece>> {
   public:
    SurakartRow(unsigned int board_size)
        : std::vector<std::shared_ptr<SurakartaPiece>>(board_size) {}
};

class SurakartaBoard : public std::vector<SurakartRow> {
   public:
    unsigned int board_size_;
    SurakartaBoard(unsigned int board_size)
        : board_size_(board_size) {
        for (unsigned int i = 0; i < board_size_; i++) {
            this->push_back(SurakartRow(board_size_));
        }
    }

    bool IsInside(const SurakartaPosition& position) const {
        return position.x < board_size_ && position.y < board_size_;
    }

    friend inline std::ostream& operator<<(std::ostream& os, const SurakartaBoard& board) {
        for (unsigned int y = 0; y < board.board_size_; y++) {
            for (unsigned int x = 0; x < board.board_size_; x++) {
                os << (*board[x][y]) << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend inline std::istream& operator>>(std::istream& is, SurakartaBoard& board) {
        for (unsigned int y = 0; y < board.board_size_; y++) {
            for (unsigned int x = 0; x < board.board_size_; x++) {
                char ch;
                is >> ch;
                PieceColor color;
                switch (ch) {
                    case 'B':
                        color = PieceColor::BLACK;
                        break;
                    case 'W':
                        color = PieceColor::WHITE;
                        break;
                    default:
                        color = PieceColor::NONE;
                        break;
                }
                board[x][y] = std::make_shared<SurakartaPiece>(x, y, color);
            }
        }
        return is;
    }
};
