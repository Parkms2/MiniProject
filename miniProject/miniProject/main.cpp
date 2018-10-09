#include"header.h"
#include"game.h"

Game* g_game = 0;

int main(int argc, char*args[]) {
	g_game = new Game();
	g_game->init("miniProject", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (g_game->running()) {
		// Util init
		//g_game->SdlDeltaTime();

		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}