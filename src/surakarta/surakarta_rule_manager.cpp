#include "surakarta_rule_manager.h"
#include <iostream>

void SurakartaRuleManager::OnUpdateBoard() {
    // TODO:
    // Every time the board is updated, this function will be called.
    // You don't need to implement this function if you don't need it.
    // A more delicate way is to use Qt's signal and slot mechanism, but that's the advanced part.
}

SurakartaIllegalMoveReason SurakartaRuleManager::JudgeMove(const SurakartaMove& move) {
    // TODO: Implement this function.

    // An example of how to get the color of a piece and the current player.
    for (unsigned int i = 0; i < board_size_; i++) {
        for (unsigned int j = 0; j < board_size_; j++) {
            PieceColor color = (*board_)[i][j]->GetColor();
            if (color == PieceColor::BLACK) {
                // i,j is the position of a black piece
            } else if (color == PieceColor::WHITE) {
                // i,j is the position of a white piece
            } else {
                // i,j is an empty position
            }
        }
    }
    SurakartaPlayer current_player = game_info_->current_player_;
    if (current_player == SurakartaPlayer::BLACK) {
        // black player's turn
    } else if (current_player == SurakartaPlayer::WHITE) {
        // white player's turn
    }

    return SurakartaIllegalMoveReason::LEGAL;
}

std::pair<SurakartaEndReason, SurakartaPlayer> SurakartaRuleManager::JudgeEnd(const SurakartaIllegalMoveReason reason) {
    SurakartaPlayer winner = SurakartaPlayer::NONE;

    // You can directly use the following code to judge whether it is a stalemate.
    if (game_info_->num_round_ - game_info_->last_captured_round_ >= game_info_->max_no_capture_round_ &&
        reason == SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE) {
        // TODO: winner is the player who has more pieces. winner = NONE if draw.
        // winner = xxxx
        return std::make_pair(SurakartaEndReason::STALEMATE, winner);
    }

    // TODO: If one player's last piece is captured, the other player wins. Remember the board hasn't been updated yet.
    if (false) {
        // winner = xxxx;
        return std::make_pair(SurakartaEndReason::CHECKMATE, winner);
    }

    // TODO: If the move is illegal, the other player wins.
    if (false) {
        // winner = xxxx;
        return std::make_pair(SurakartaEndReason::ILLIGAL_MOVE, winner);
    }

    return std::make_pair(SurakartaEndReason::NONE, winner);
}

std::unique_ptr<std::vector<SurakartaPosition>> SurakartaRuleManager::GetAllLegalTarget(const SurakartaPosition postion) {
    // TODO:
    // We don't test this function, you don't need to implement this function if you don't need it.
    return std::make_unique<std::vector<SurakartaPosition>>();
}

void SurakartaRuleManager::HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}