#pragma once
#include "raylib.h"
#include "Headers/Bird.h"


class Obstacle {
private:
	Rectangle upperRectangle;
	Rectangle lowerRectangle;
	//Texture2D upperBlock;
	//Texture2D lowerBlock;
	Vector2 location;
	//Bird* bird;

public:
	Obstacle();
	~Obstacle() = default; 
	bool active{ false };
	//bool getHit();


	void draw();
	void update(Bird *player);
	bool isHit(Rectangle player);
};

