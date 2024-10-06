#include "headers/Platform.h"


Platform::Platform(float x, float y, float w, float h, int sp)
	: xAxis{ x }, yAxis{ y }, width{ w }, height{ h }, speed{ sp } {}
	


void Platform::draw() {
	DrawRectangleRounded(Rectangle{ xAxis, yAxis, width, height }, 0.8f, 15, WHITE);
}

void Platform::update() {
	if (IsKeyDown(KEY_UP)) {
		yAxis -= speed;
	}
	if (IsKeyDown(KEY_DOWN)) {
		yAxis += speed;
	}
	platformLimit();
	
}

void Platform::platformLimit() {
	if (yAxis < 0)
		yAxis = 0;
	if (yAxis + height > GetScreenHeight())
		yAxis = GetScreenHeight() - height;
}

Rectangle Platform::getRect() {
	return Rectangle{ xAxis, yAxis, width, height };
}





