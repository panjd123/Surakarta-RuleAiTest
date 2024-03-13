#include <cstdlib>
#include <iostream>
#include "gtest/gtest.h"
#include "surakarta/surakarta_common.h"
#include "surakarta/surakarta_game.h"
#include "surakarta_ta/surakarta_rule_manager_imp.h"

#ifndef TEST_DATA_DIR
#define TEST_DATA_DIR "/home/panjd123/code/TuringSurakarta/src/tests/test_data/"
#warning TEST_DATA_DIR is not defined, please make sure you are in debug mode
#endif

TEST(SurakartaRuleManagerTest, EndReasonTest) {
    if (BOARD_SIZE != 6) {
        GTEST_SKIP() << "Skip test for BOARD_SIZE!=6";
    }
    SurakartaGame game1;
    SurakartaGame game2;
    std::shared_ptr<SurakartaRuleManagerImp> rule_manager_ta = std::make_shared<SurakartaRuleManagerImp>(game2.GetBoard(), game2.GetGameInfo());
    auto rule_manager_stu = game1.GetRuleManager();
    game2.SetRuleManager(rule_manager_ta);
    std::vector<std::pair<std::string, SurakartaIllegalMoveReason>> tb;
    tb.emplace_back("game6.txt", SurakartaIllegalMoveReason::LEGAL_CAPTURE_MOVE);
    tb.emplace_back("game3.txt", SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE);
    tb.emplace_back("game4.txt", SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE);
    tb.emplace_back("game5.txt", SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE);
    tb.emplace_back("game7.txt", SurakartaIllegalMoveReason::LEGAL_NON_CAPTURE_MOVE);
    for (auto [file_name, reason] : tb) {
        game1.StartGame(TEST_DATA_DIR + file_name);
        game2.StartGame(TEST_DATA_DIR + file_name);
        auto [end_reason_ta, winner_ta] = rule_manager_ta->JudgeEnd(reason);
        auto [end_reason_stu, winner_stu] = rule_manager_stu->JudgeEnd(reason);
        ASSERT_EQ(end_reason_ta, end_reason_stu) << "Board:" << std::endl
                                                 << *game2.GetBoard() << "GameInfo:" << std::endl
                                                 << *game2.GetGameInfo() << "MoveReason: " << std::endl
                                                 << reason << std::endl;
        ASSERT_EQ(winner_ta, winner_stu) << "Board:" << std::endl
                                         << *game2.GetBoard() << "GameInfo:" << std::endl
                                         << *game2.GetGameInfo() << "MoveReason: " << std::endl
                                         << reason << std::endl;
    }
}

TEST(SurakartaRuleManagerTest, MoveReasonTest) {
    if (BOARD_SIZE != 6) {
        GTEST_SKIP() << "Skip test for BOARD_SIZE!=6";
    }
    SurakartaGame game1;
    SurakartaGame game2;
    std::shared_ptr<SurakartaRuleManagerImp> rule_manager_ta = std::make_shared<SurakartaRuleManagerImp>(game2.GetBoard(), game2.GetGameInfo());
    auto rule_manager_stu = game1.GetRuleManager();
    game2.SetRuleManager(rule_manager_ta);
    std::vector<std::pair<std::string, std::vector<SurakartaMove>>> tb;
    tb.push_back(std::make_pair("game1.txt", std::vector<SurakartaMove>{
                                                 {2, 2, 2, 0, SurakartaPlayer::BLACK},
                                                 {2, 2, 2, 1, SurakartaPlayer::BLACK},
                                                 {2, 2, 2, 3, SurakartaPlayer::BLACK},
                                                 {4, 4, 5, 1, SurakartaPlayer::BLACK},
                                                 {4, 5, 5, 1, SurakartaPlayer::BLACK},
                                                 {4, 5, 4, 6, SurakartaPlayer::BLACK},
                                                 {0, 0, 0, 1, SurakartaPlayer::BLACK},
                                                 {2, 0, 1, 0, SurakartaPlayer::BLACK}}));
    tb.push_back(std::make_pair("game2.txt", std::vector<SurakartaMove>{
                                                 {4, 4, 3, 4, SurakartaPlayer::WHITE},
                                                 {3, 5, 5, 3, SurakartaPlayer::WHITE}}));
    tb.push_back(std::make_pair("game8.txt", std::vector<SurakartaMove>{
                                                 {1, 3, 1, 2, SurakartaPlayer::WHITE},
                                                 {1, 2, 1, 3, SurakartaPlayer::WHITE}}));
    tb.push_back(std::make_pair("game9.txt", std::vector<SurakartaMove>{
                                                 {3, 3, 2, 3, SurakartaPlayer::BLACK},
                                                 {3, 3, 3, 1, SurakartaPlayer::BLACK}}));
    for (auto [file_name, moves] : tb) {
        game1.StartGame(TEST_DATA_DIR + file_name);
        game2.StartGame(TEST_DATA_DIR + file_name);
        for (auto move : moves) {
            auto move_reason_ta = rule_manager_ta->JudgeMove(move);
            auto move_reason_stu = rule_manager_stu->JudgeMove(move);

            ASSERT_EQ(move_reason_ta, move_reason_stu) << "Board:" << std::endl
                                                       << *game2.GetBoard() << "GameInfo:" << std::endl
                                                       << *game2.GetGameInfo() << "Move: " << move << std::endl;
        }
    }
}

TEST(SurakartaRuleManagerTest, RandomTest) {
    int offline_test_round;
    int num_game;
    int log_level;
    /*
    0: no log
    1: log total moves
    2: log pass
    */
    const char* offline_test_round_str = std::getenv("OFFLINE_TEST_ROUND");
    const char* num_game_str = std::getenv("NUM_GAME");
    const char* log_level_str = std::getenv("LOG_LEVEL");
    offline_test_round = offline_test_round_str ? std::stoi(offline_test_round_str) : 100;
    num_game = num_game_str ? std::stoi(num_game_str) : 10000;
    log_level = log_level_str ? std::stoi(log_level_str) : 2;

    SurakartaGame game1;
    SurakartaGame game2;
    std::shared_ptr<SurakartaRuleManagerImp> rule_manager_ta = std::make_shared<SurakartaRuleManagerImp>(game2.GetBoard(), game2.GetGameInfo());
    auto rule_manager_stu = game1.GetRuleManager();
    game2.SetRuleManager(rule_manager_ta);
    game1.StartGame();
    game2.StartGame();
    int game_cnt = 0;
    int move_cnt = 0;
    while (true) {
        SurakartaMove move;
        for (int i = 0; i < offline_test_round + 1; i++) {
            if (i == offline_test_round) {
                move = rule_manager_ta->GenerateMove(0, 1);
            } else {
                move = rule_manager_ta->GenerateMove(0.5, 0.5);
            }
            auto move_reason_ta = rule_manager_ta->JudgeMove(move);
            auto [end_reason_ta, winner_ta] = rule_manager_ta->JudgeEnd(move_reason_ta);
            auto move_reason_stu = rule_manager_stu->JudgeMove(move);
            auto [end_reason_stu, winner_stu] = rule_manager_stu->JudgeEnd(move_reason_stu);
            ASSERT_EQ(move_reason_ta, move_reason_stu) << "Board:" << std::endl
                                                       << *game2.GetBoard() << "GameInfo:" << std::endl
                                                       << *game2.GetGameInfo() << "Move: " << move << std::endl;
            ASSERT_EQ(end_reason_ta, end_reason_stu) << "Board:" << std::endl
                                                     << *game2.GetBoard() << "GameInfo:" << std::endl
                                                     << *game2.GetGameInfo() << "Move: " << move << std::endl;
            ASSERT_EQ(winner_ta, winner_stu) << "Board:" << std::endl
                                             << *game2.GetBoard() << "GameInfo:" << std::endl
                                             << *game2.GetGameInfo() << "Move: " << move << std::endl;
        }
        game1.Move(move);
        game2.Move(move);
        if (game2.IsEnd()) {
            if (log_level >= 2) {
                std::cout << "Game " << game_cnt << " (" << game2.GetGameInfo()->num_round_ << " round)"
                          << " (" << game2.GetGameInfo()->end_reason_ << ") "
                          << " passed." << std::endl;
            }
            move_cnt += game2.GetGameInfo()->num_round_ * (offline_test_round + 1);
            game1.StartGame();
            game2.StartGame();
            game_cnt++;
            if (game_cnt >= num_game) {
                break;
            }
        }
    }
    if (log_level >= 1) {
        std::cout << "Passed " << move_cnt << " moves." << std::endl;
    }
}
