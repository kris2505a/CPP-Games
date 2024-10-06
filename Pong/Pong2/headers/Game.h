#pragma once

class Game {
private:
	const int windowWidth{ 1280 };
	const int windowHeight{ 720 };
	const int fps{ 120 };
	const int ballSpeed{ 7 };



public:
	void run();
};