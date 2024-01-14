#pragma once

#include "surakarta_agent/surakarta_agent_base.h"
#include "surakarta_common.h"
#include "surakarta_rule_manager.h"

class SurakartaMoveResponse {
   public:
    SurakartaMoveResponse(SurakartaIllegalMoveReason move_reason)
        : move_reason_(move_reason), end_reason_(SurakartaEndReason::NONE), winner_(SurakartaPlayer::NONE) {}

    SurakartaMoveResponse(SurakartaIllegalMoveReason move_reason, SurakartaEndReason end_reason, SurakartaPlayer winner)
        : move_reason_(move_reason), end_reason_(end_reason), winner_(winner) {}

    bool IsLegal() const {
        return IsLegalMoveReason(move_reason_);
    }

    bool IsEnd() const {
        return end_reason_ != SurakartaEndReason::NONE;
    }

    SurakartaIllegalMoveReason GetMoveReason() const {
        return move_reason_;
    }

    SurakartaEndReason GetEndReason() const {
        return end_reason_;
    }

    SurakartaPlayer GetWinner() const {
        return winner_;
    }

    //    private:
    SurakartaIllegalMoveReason move_reason_;
    SurakartaEndReason end_reason_;
    SurakartaPlayer winner_;
};

class SurakartaGame {
   public:
    SurakartaGame(unsigned board_size = BOARD_SIZE, unsigned int max_no_capture_round = 40)
        : board_size_(board_size),
          board_(std::make_shared<SurakartaBoard>(board_size)),
          game_info_(std::make_shared<SurakartaGameInfo>(max_no_capture_round)),
          rule_manager_(std::make_shared<SurakartaRuleManager>(board_, game_info_)),
          agent_(std::make_shared<SurakartaAgentBase>(board_, game_info_, rule_manager_)) {}

    /**
     * @brief Start the game. If file_name is empty, the board will be initialized to the initial state. Otherwise, the board will be initialized to the state in the file.
     */
    void StartGame(std::string file_name = "");

    /**
     * @brief Save the game to a file.
     * @param file_name The file name.
     */
    void SaveGame(std::string file_name) const;

    /**
     * @brief Update game info, this function should be called after each move.
     * @param reason SurakartaIllegalMoveReason.
     */
    void UpdateGameInfo(SurakartaIllegalMoveReason move_reason, SurakartaEndReason end_reason, SurakartaPlayer winner);

    /**
     * @brief Move a piece, and update game info.
     * @param move The move to be made.
     * @return See SurakartaMoveResponse.
     */
    SurakartaMoveResponse Move(const SurakartaMove& move);

    /**
     * @brief Set the agent.
     */
    void SetAgent(std::shared_ptr<SurakartaAgentBase> agent) { agent_ = agent; }

    unsigned int GetBoardSize() const { return board_size_; }
    std::shared_ptr<SurakartaBoard> GetBoard() const { return board_; }
    std::shared_ptr<SurakartaGameInfo> GetGameInfo() const { return game_info_; }
    std::shared_ptr<SurakartaAgentBase> GetAgent() const { return agent_; }
    bool IsEnd() const { return game_info_->IsEnd(); }

    void SetRuleManager(std::shared_ptr<SurakartaRuleManager> rule_manager) {  // For testing.
        rule_manager_ = rule_manager;
    }
    std::shared_ptr<SurakartaRuleManager> GetRuleManager() const { return rule_manager_; }  // For testing.

    //    private:
    unsigned int board_size_;
    std::shared_ptr<SurakartaBoard> board_;
    std::shared_ptr<SurakartaGameInfo> game_info_;
    std::shared_ptr<SurakartaRuleManager> rule_manager_;
    std::shared_ptr<SurakartaAgentBase> agent_;
};