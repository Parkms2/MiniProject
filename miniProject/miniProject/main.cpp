#include"header.h"
#include"game.h"

Game* g_game = 0;

int main(int argc, char*args[]) {
	g_game = new Game();
	g_game->init("miniProject", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
	//m_mapControl->initMap();
	while (g_game->running()) {
		g_game->habdleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;
}