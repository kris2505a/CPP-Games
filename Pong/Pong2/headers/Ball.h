#pragma once
#include "raylib.h"

class Ball {
private:
	float xAxis{ 0.f }, yAxis{ 0.f };
	int speedX{ 0 }, speedY{ 0 };
	int radius{ 0 };

public:
	Ball(float x, float y, int spX, int spY, int rad);
	void draw();
	void update();
	void reset();
	Ball *getBall();
	Vector2 getAxis();
	void reverseBall();
	float getYAxis();
	float getXAxis();


	int playerScore{ 0 }, aiScore{ 0 };
	void updateScore();
};
