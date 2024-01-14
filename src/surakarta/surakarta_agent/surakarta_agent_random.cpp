#include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include <algorithm>
#include <cstdlib>
#include <random>
#include <vector>
#include "surakarta/surakarta_common.h"

SurakartaMove SurakartaAgentRandom::CalculateMove() {
    std::vector<SurakartaPosition> from;
    std::vector<SurakartaPosition> to;
    for (unsigned int i = 0; i < board_size_; i++) {
        for (unsigned int j = 0; j < board_size_; j++) {
            SurakartaPosition position = {i, j};
            if ((*board_)[i][j]->GetColor() == game_info_->current_player_) {
                from.push_back(position);
            } else {
                to.push_back(position);
            }
        }
    }
    std::shuffle(from.begin(), from.end(), std::default_random_engine(std::random_device()()));
    std::shuffle(to.begin(), to.end(), std::default_random_engine(std::random_device()()));
    for (auto& p1 : from) {
        for (auto& p2 : to) {
            SurakartaMove move = {p1, p2, game_info_->current_player_};
            if (IsLegalMoveReason(rule_manager_->JudgeMove(move))) {
                return move;
            }
        }
    }
    return SurakartaMove({0, 0}, {0, 0}, game_info_->current_player_);
}