CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(tic-tac-toe)

ADD_EXECUTABLE(${PROJECT_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/tictac.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/tictac.h
)