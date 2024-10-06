#pragma once
#include "raylib.h"
class Platform {
protected:
	float xAxis{ 0.f }, yAxis{ 0.f };
	float width{ 0.f }, height{ 0.f };
	int speed{ 0 };
	int score{ 0 };
	void platformLimit();

public:
	Platform(float x, float y, float w, float h, int sp);
	void draw();
	void update();
	Rectangle getRect();

};