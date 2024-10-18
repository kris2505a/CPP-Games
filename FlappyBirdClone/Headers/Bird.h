#pragma once
#include "raylib.h"


class Bird {
private:
	int type;
	Vector2 location;
	Texture2D image;
	float fallRate{ 2.0f };
	//bool fall{ true };
	Rectangle collisionRectangle;
	bool gotHit{ false };

public:
	Bird(int typ);
	~Bird();
	void draw();
	void update();
	void push();
	bool notCrashed();
	Rectangle getRect() const;
	void setGotHit(bool condition);
	bool getGotHit();
};

