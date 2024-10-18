#include "Headers/Game.h"
#include <memory>
int main() {
	std::unique_ptr<Game> game = std::make_unique<Game>(720, 900, 120, std::string("Title"));
	game->startGame();
}