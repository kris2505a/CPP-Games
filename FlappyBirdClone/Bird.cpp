#include "Headers/Bird.h"

Bird::Bird(int typ) {
	type = typ;
	switch (type) {
	case 1:
		image = LoadTexture("Textures/bird1.png");
		break;
		
	case 2:
		image = LoadTexture("Textures/bird2.png");
		break;

	default:
		image = LoadTexture("Textures/bird1.png");
		break;
	}
	location.x = static_cast<float>(GetScreenWidth()) / 3;
	location.y = static_cast<float>(GetScreenHeight()) / 2;
	collisionRectangle.width = collisionRectangle.height = 30;
	collisionRectangle.x = location.x;
	collisionRectangle.y = location.y;
}


Bird::~Bird() {
	UnloadTexture(image);
	delete this;
}


void Bird::draw() {
	DrawTextureV(image, location, WHITE);
	DrawRectangleRec(collisionRectangle, BLANK);
	
}


void Bird::update() {
	location.y += fallRate;
	collisionRectangle.y += fallRate;
	if (location.y < 0)
		location.y = 0;
}


void Bird::push() {
	collisionRectangle.y -= 8.0f;
	location.y -= 8.0f;
}


bool Bird::notCrashed() {
	return location.y < GetScreenHeight() - 50;
}


Rectangle Bird::getRect() const {
	return this->collisionRectangle;
}


void Bird::setGotHit(bool condition) {
	gotHit = condition;
}

bool Bird::getGotHit() {
	return gotHit;
}