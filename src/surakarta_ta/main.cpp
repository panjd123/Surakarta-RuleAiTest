#include <chrono>
#include <iostream>
#include <thread>
#include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include "surakarta/surakarta_common.h"
#include "surakarta/surakarta_game.h"
#include "surakarta_rule_manager_imp.h"

#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_MOVE_TO_START "\033[H"

int main() {
    SurakartaGame game;
    game.StartGame();
    std::shared_ptr<SurakartaRuleManagerImp> rule_manager = std::make_shared<SurakartaRuleManagerImp>(game.GetBoard(), game.GetGameInfo());
    std::shared_ptr<SurakartaAgentRandom> agent = std::make_shared<SurakartaAgentRandom>(game.GetBoard(), game.GetGameInfo(), rule_manager);
    game.SetRuleManager(rule_manager);
    std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    while (!game.IsEnd()) {
        auto move = agent->CalculateMove();
        game.Move(move);
        std::cout << *game.GetBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    }
    std::cout << *game.GetBoard();
    std::cout << game.GetGameInfo()->end_reason_ << std::endl;
}