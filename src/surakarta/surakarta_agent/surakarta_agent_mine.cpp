#include "surakarta/surakarta_agent/surakarta_agent_mine.h"

SurakartaMove SurakartaAgentMine::CalculateMove() {
    // TODO: Implement your own ai here.
    return SurakartaMove({0, 0}, {0, 0}, game_info_->current_player_);
}