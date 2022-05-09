#pragma once

#include "LeftBoard.h"
#include "TopBoard.h"
#include "CircuitBoard.h"
#include <iostream>

class Simulator
{
public:
	CircuitBoard* circuitBoard;
	TopBoard* topBoard;
	LeftBoard* leftBoard;
	sf::RenderWindow* window;

	//Funcs
	Simulator(sf::RenderWindow* w);
	~Simulator();
	void close();
	void draw();
	void handleClick(sf::Vector2f mp);
};
