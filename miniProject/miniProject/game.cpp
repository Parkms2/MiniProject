#include"game.h"


BasicCookie*  basicCookie = new BasicCookie();
MapBackground* mapBackground = new MapBackground();
MapFloor* mapFloor = new MapFloor();

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);	


			basicCookie->basicCookieRun(m_pRenderer);
			mapBackground->mapBackgroundInit(m_pRenderer);
			mapFloor->mapFloorInit(m_pRenderer);

		}
		else return false;
	}
	else return true;
}
void Game::render() {
	
	SDL_RenderClear(m_pRenderer);

	mapBackground->mapBackgroundRender(m_pRenderer);

	basicCookie->basicCookieRender(m_pRenderer);
	mapFloor->mapFloorRender(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);

}
void Game::update() {
	double tick = SDL_GetTicks();

	basicCookie->basicCookieUpdate(tick);
	mapBackground->mapBackgroundUpdate(tick);
	mapFloor->mapFloorUpdate(tick);

}
void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				basicCookie->sdlKeyUp();
				break;
			case SDLK_DOWN:
				basicCookie->sdlKeyDown();
				break;
			}
		default:
			break;
		}
	}
}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

	