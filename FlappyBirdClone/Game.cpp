#include "Headers/Game.h"
#include "Headers/Bird.h"
#include "Headers/Obstacle.h"


Game::Game(int wW, int wH, int wfps, std::string tit)
	:winWidth{wW},
	 winHeight{wH},
	 fps{wfps},
	title{ tit } {

	InitWindow(winWidth, winHeight, title.c_str());
	SetTargetFPS(fps);
}


Game::~Game() {
	CloseWindow();
}

void Game::startGame() {
	bird = new Bird(2);
	//obst = new Obstacle();
	gameLoop();
}


void Game::gameLoop() {
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);
		BeginDrawing();
		tick();
		EndDrawing();
	}
}



void Game::tick() {
	if (bird->notCrashed()) {
		handleInput();
		update();
		draw();
	}
	
}


void Game::draw() {
	//draw functions
	if (!bird->getGotHit()) {
		for (auto& i : obstacles) {
			i.draw();
			bird->draw();
		}
	}
	else {
		DrawText("Game Over!", 240, 450, 50, RED);
	}
	//obst->draw();
}


void Game::update() {
	//update functions
	if (bird->getGotHit()) {
		//DrawText("Game Over!", 300, 450, 50, RED);
		return;
	}
	else {
		for (auto& i : obstacles)
			i.update(bird);
		bird->update();
		//obst->update();
		createObstacles();
		deleteOffRangeObstacle();
	}
}



void Game::handleInput() {
	if (IsKeyDown(KEY_SPACE)) {
		bird->push();
	}
}


void Game::createObstacles() {
	if (GetTime() - lastObstacleTime >= 1.2f) {
		obstacles.push_back(Obstacle());
		lastObstacleTime = GetTime();
	}
}


void Game::deleteOffRangeObstacle() {
	for (auto i = obstacles.begin(); i < obstacles.end(); i++) {
		if (!i->active) 
			i = obstacles.erase(i);
		else
			++i;
	}
}