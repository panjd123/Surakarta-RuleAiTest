SET(GAME_SOURCES surakarta_reason.cpp surakarta_game.cpp surakarta_rule_manager.cpp)
SET(AGENT_SOURCES surakarta_agent/surakarta_agent_random.cpp surakarta_agent/surakarta_agent_mine.cpp)

add_library(surakarta ${GAME_SOURCES} ${AGENT_SOURCES})

set_target_properties(surakarta PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(main main.cpp)
target_link_libraries(main surakarta)