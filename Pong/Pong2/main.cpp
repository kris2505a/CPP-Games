#include "headers/Game.h"
#include <memory>
#include <iostream>




void main() {
	std::unique_ptr<Game> game = std::make_unique<Game>();
	//game = nullptr;
	if (game == nullptr) {
		std::cout << "Unable to initialize game!" << std::endl;
		return;
	}
		
	game->run();
}