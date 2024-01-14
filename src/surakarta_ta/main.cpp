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
    SurakartaGame game(6, 100);  // Default is 6, 40. But random agent may too slow to eat a piece.
    game.GetRuleManager()->HelloWorld();
    game.StartGame();
    std::shared_ptr<SurakartaRuleManagerImp> rule_manager = std::make_shared<SurakartaRuleManagerImp>(game.GetBoard(), game.GetGameInfo());
    std::shared_ptr<SurakartaAgentRandom> agent = std::make_shared<SurakartaAgentRandom>(game.GetBoard(), game.GetGameInfo(), rule_manager);
    game.SetRuleManager(rule_manager);
    game.SetAgent(agent);
    while (!game.IsEnd()) {
        auto move = game.GetAgent()->CalculateMove();
        game.Move(move);
        std::cout << *game.GetBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    }
    std::cout << game.GetGameInfo()->end_reason_ << std::endl;
}