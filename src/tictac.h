#pragma once

// Inside the tictac class, the positions are computed from 0 to 8. However, the human player enter the positions from 1 to 9. Human's pieces are [x]. Machine pieces are [o].

#ifndef TICTAC_H
#define TICTAC_H

#include <iostream>
#include <thread>
#include <chrono>

class tictac {
	void intro();					// Simple presentation explaining how to input the positions.
	char pieces[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };		// Controls the positions on the board and the pieces put on it. Three possible states : ' ', 'x', 'o'.
	void board();					// Shows the board and the pieces on it, based on pieces[9].
	void resetBoard();				// Removes all pieces from the board.

	void enterMove();				// Asks the human player to enter a position and a piece is put on that position.
	void enterMove_2();				// Used in human vs human game. Asks the second human player to enter a	position and a piece is put on that position.

	bool isOccupied(int pos);		// Verifies if one position on the board is ocuppied (true) or not (false).Function used by enterMove().
	bool verifyFull();				// Checks if all possible positions on the board are occupied (true) or not (false).
	int verifyVictory();			// Checks if the current game has a victory of human player (1), victory of the machine(2) or neither(0).
	int verifyEnd();				// Check if the current game has ended and what is the result. Prints result.Uses verifyVictory() and verifyFull(). Victory(1), lose(2), draw(3), neither(0).
	int verifyEnd_2();				// Used in human vs human game. Check if the current game has ended and what is the result.Prints result.Uses verifyVictory() and verifyFull(). Player 1 wins(1), player 2 wins(2), draw(3), neither(0).

	bool AI_1();					// If machine has 2 pieces in line, he completes the line and returns 1. If not, only returns 0.
	bool AI_2();					// If human player has 2 pieces in line, machine complete the line and returns 1. If not, only returns 0.
	bool AI_3();					// If central position is empty, machine puts a piece there and function returns 1. If not, only returns 0.
	bool AI_4();					// Machine puts a piece in a corner and returns 1. If not, returns 0.
	bool AI_5();					// Machine puts a piece in a side and returns 1. If not, returns 0.
	bool AIdecision();				// Machine takes a decision by evaluating AI_1(), AI_2(), AI_3(), AI_4() and AI_5() in this order and puts a piece in some position.

public:
	void run();
};

#endif