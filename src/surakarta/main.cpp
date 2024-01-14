#include <chrono>
#include <iostream>
#include <thread>
#include "surakarta/surakarta_agent/surakarta_agent_mine.h"
#include "surakarta/surakarta_agent/surakarta_agent_random.h"
#include "surakarta/surakarta_common.h"
#include "surakarta/surakarta_game.h"

#define ANSI_CLEAR_SCREEN "\033[2J"
#define ANSI_MOVE_TO_START "\033[H"

int main() {
    SurakartaGame game(6, 100);  // Default is 6, 40. But random agent may too slow to eat a piece.
    game.GetRuleManager()->HelloWorld();
    game.StartGame();

    // TODO: After you pass the test, uncomment the following code, you should see a random game.
    // std::shared_ptr<SurakartaAgentRandom> agent = std::make_shared<SurakartaAgentRandom>(game.GetBoard(), game.GetGameInfo(), game.GetRuleManager());
    // while (!game.IsEnd()) {
    //     auto move = agent->CalculateMove();
    //     game.Move(move);
    //     std::cout << *game.GetBoard() << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //     std::cout << ANSI_CLEAR_SCREEN << ANSI_MOVE_TO_START;
    // }
    // std::cout << game.GetGameInfo()->end_reason_ << std::endl;

    // TODO: Create 2 agent, one is SurakartaAgentRandom, the other is your own agent. Let them play against each other.
}