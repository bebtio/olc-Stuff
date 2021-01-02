file( GLOB SRCS *.cpp *.h )

SET(CMAKE_CXX_FLAGS "-std=c++0x")
add_executable( battleship ${SRCS} Board.cpp Board.h BattleShip.cpp BattleShip.h ProbabilityCalculator.cpp ProbabilityCalculator.h BoxHighestScore.h BoxResult.h)
