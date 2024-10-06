#include "headers/aiPlatform.h"


void aiPlatform::update(float ball) {
	if (yAxis + height / 2 > ball)
		yAxis -= speed;
	if (yAxis + height / 2 < ball)
		yAxis += speed;
	platformLimit();
}


aiPlatform::aiPlatform(float x, float y, float w, float h, int sp)
	: Platform(x, y, w, h, sp) {}

