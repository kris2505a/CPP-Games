#pragma once
#include "Platform.h"
#include "Ball.h"


class aiPlatform : public Platform {
public:
	void update(float ball);
	aiPlatform(float x, float y, float w, float h, int sp);
};