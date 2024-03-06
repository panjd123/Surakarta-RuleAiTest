#pragma once

#include <memory>
#include <stdexcept>
#include <vector>
#include "surakarta/surakarta_rule_manager.h"

class SurakartaRuleManagerImp : public SurakartaRuleManager {
    using SurakartaRuleManager::board_;
    using SurakartaRuleManager::board_size_;
    using SurakartaRuleManager::game_info_;

   private:
    SurakartaPosition RotateGoto(const SurakartaPosition& current) const;
    std::unique_ptr<std::vector<SurakartaMove>> GetAllLegalCaptureMoveStartFrom(const SurakartaPosition& position) const;

   public:
    using SurakartaRuleManager::SurakartaRuleManager;

    void OnUpdateBoard() override;
    SurakartaIllegalMoveReason JudgeMove(const SurakartaMove& move) override;
    std::pair<SurakartaEndReason, SurakartaPlayer> JudgeEnd(const SurakartaIllegalMoveReason reason) override;
    std::unique_ptr<std::vector<SurakartaPosition>> GetAllLegalTarget(const SurakartaPosition postion) override;

    // For testing, if no valid moves are available, it will still output randomly
    SurakartaMove GenerateMove(double p_random, double p_legal);

   private:
    std::vector<SurakartaMove> legal_capture_moves_;

    // For testing
    std::vector<std::shared_ptr<SurakartaPiece>> white_pieces_;
    std::vector<std::shared_ptr<SurakartaPiece>> black_pieces_;
};