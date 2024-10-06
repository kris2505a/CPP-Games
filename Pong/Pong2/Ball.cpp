#include "headers/Ball.h"

Ball::Ball(float x, float y, int spX, int spY, int rad)
	: xAxis{ x }, yAxis{ y }, speedX{ spX }, speedY{ spY }, radius{ rad } {}


void Ball::draw() {
	DrawCircle(xAxis, yAxis, radius, BLUE);
}


void Ball::update() {

	xAxis += speedX;
	yAxis += speedY;

	if (yAxis <= 0 || yAxis >= 720)
		speedY = -speedY;

	//if (xAxis <= 0 || xAxis >= 1280)
		//reset();
}


void Ball::reset() {
	xAxis = GetScreenWidth() / 2;
	yAxis = GetScreenHeight() / 2;
	int direction[2] = { -1, 1 };
	speedX *= direction[GetRandomValue(0, 1)];
	speedY *= direction[GetRandomValue(0, 1)];
}


Ball *Ball::getBall() {
	return this;
}

Vector2 Ball::getAxis() {
	return Vector2{ xAxis, yAxis };
}


void Ball::reverseBall() {
	speedX = -speedX;
}


float Ball::getYAxis() {
	return yAxis;
}


float Ball::getXAxis() {
	return xAxis;
}


void Ball::updateScore() {
	if (xAxis - radius > GetScreenWidth()) {
		playerScore++;
		reset();
	}
	if (xAxis + radius < 0) {
		aiScore++;
		reset();
	}
		
}