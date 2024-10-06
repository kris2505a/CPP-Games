#include "headers/Game.h"
#include "raylib.h"
#include "headers/Ball.h"
#include "headers/Platform.h"
#include "headers/aiPlatform.h"


void Game::run() {
	InitWindow(windowWidth, windowHeight, "PONGIIIII");
	SetTargetFPS(fps);

	Ball ball(windowWidth / 2, windowHeight / 2, ballSpeed, ballSpeed, 15);
	Platform leftPlatform(10.f, ((windowHeight - 120) / 2), 20.f, 120.f, 10);
	aiPlatform rightPlatform((windowWidth - 30), ((windowWidth - 120)/2), 20.f, 120.f, 10);
	
	while (!WindowShouldClose()) {
		ball.update();
		leftPlatform.update();
		rightPlatform.update(ball.getYAxis());
		if (CheckCollisionCircleRec(ball.getAxis(), 15, leftPlatform.getRect()))
			ball.reverseBall();
		if (CheckCollisionCircleRec(ball.getAxis(), 15, rightPlatform.getRect()))
			ball.reverseBall();
		ball.updateScore();
		BeginDrawing();
		
		ClearBackground(GREEN);
		DrawLine(windowWidth / 2, 0, windowWidth / 2, windowHeight, WHITE);
		DrawCircleLines(windowWidth / 2, windowHeight / 2, 100, WHITE);

		ball.draw();
		leftPlatform.draw();
		rightPlatform.draw();
		DrawText(TextFormat("%i", ball.playerScore), windowWidth / 4, 20, 80, WHITE);
		DrawText(TextFormat("%i", ball.aiScore), 3 * windowWidth / 4, 20, 80, WHITE);


		EndDrawing();
	}
}

