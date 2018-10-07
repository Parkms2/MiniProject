#include"mapControl.h"

bool MapControl::initMap() {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			SDL_Surface* pTempSurface = IMG_Load("assets/floor/level1Floor.png");
			if (pTempSurface == NULL) m_bRunning = false; //이미지 불러오기 실패하면 실행
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			SDL_FreeSurface(pTempSurface);
			m_sourceRectangle.x = 0;
			m_sourceRectangle.y = 0;
			m_sourceRectangle.w = 150;
			m_sourceRectangle.h = 100;
			m_destinationRectangle.x = 300;
			m_destinationRectangle.y = 400;
			m_destinationRectangle.w = m_sourceRectangle.w;
			m_destinationRectangle.h = m_sourceRectangle.h;
			return true;
}
void MapControl::render() {

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}
void MapControl::update() {
	m_sourceRectangle.x = 150 * int(((SDL_GetTicks() / 100) % 4));
}
void MapControl::habdleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
void MapControl::clean() {
	std::cout << "cleaning Map\n";
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}