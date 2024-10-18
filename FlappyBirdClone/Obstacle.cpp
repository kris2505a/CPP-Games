#include "Headers/Obstacle.h"


Obstacle::Obstacle() {
	int arr[] = {0, 50, 100, 150 };
	int loc = GetRandomValue(0, 3);
	int arr2[] = { -1, 1 };
	int pos = GetRandomValue(0, 1);
	location.y = (static_cast<float>(GetScreenHeight()) / 2) + arr[loc] * arr2[pos];
	location.x = GetScreenWidth() - 100;
	upperRectangle.width = lowerRectangle.width = 100;
	upperRectangle.height = location.y - 100;
	lowerRectangle.height = GetScreenHeight() - location.y + 100;
	upperRectangle.x = location.x;
	upperRectangle.y = location.y - 450;
	lowerRectangle.x = location.x;
	lowerRectangle.y = location.y + 100;
	active = true;
}

void Obstacle::draw() {
	if (!active)
		return;
	DrawRectangleRec(upperRectangle, RED);
	DrawRectangleRec(lowerRectangle, RED);
}


void Obstacle::update(Bird *player) {
	if (active && location.x > -100) {
		location.x -= 3.0f;
		upperRectangle.x = location.x;
		upperRectangle.y = 0;
		lowerRectangle.x = location.x;
		lowerRectangle.y = location.y + 60;
	}
	else
		active = false;

	player->setGotHit(isHit(player->getRect()));
}


bool Obstacle::isHit(Rectangle player) {
	return (CheckCollisionRecs(this->lowerRectangle, player) ||
		CheckCollisionRecs(this->upperRectangle, player));	
}


