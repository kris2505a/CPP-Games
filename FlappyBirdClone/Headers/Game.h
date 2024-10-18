#pragma once
#include "raylib.h"
#include "Obstacle.h"
#include <string>
#include <vector>

class Game {
private:
	//private variables
	int winWidth;
	int winHeight;
	int fps;
	std::string title;
	class Bird* bird;
	//class Obstacle* obst;
	float lastObstacleTime = 0.0f;

private:
	//private functions
	void draw();
	void update();
	void tick();
	void gameLoop();
	void handleInput();
	void createObstacles();

public:
	//constructor/destructor
	Game(int wW, int wH, int wfps, std::string tit);
	~Game();

public:
	//public variables
	std::vector<Obstacle> obstacles;

public:
	//public functions
	void startGame();
	void deleteOffRangeObstacle();
};



